#include "Persistencia.h"
#include "Huesped.h"
#include "Anfitrion.h"
#include "Alojamiento.h"
#include "Reservacion.h"
#include "Sistema.h"
#include "VectorManual.h"
#include <sstream>
#include <stdexcept>

void Persistencia::cargarUsuarios() {
    std::ifstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("Error al abrir usuarios.txt");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        size_t p1 = linea.find('|');
        size_t p2 = linea.find('|', p1+1);
        size_t p3 = linea.find('|', p2+1);
        size_t p4 = linea.find('|', p3+1);

        std::string documento = linea.substr(0, p1);
        std::string tipo = linea.substr(p1+1, p2-p1-1);
        int antiguedad = std::stoi(linea.substr(p2+1, p3-p2-1));
        float puntuacion = std::stof(linea.substr(p3+1, p4-p3-1));

        Usuario* usuario = nullptr;
        if (tipo == "huesped") {
            usuario = new Huesped(documento, antiguedad, puntuacion);
        } else if (tipo == "anfitrion") {
            usuario = new Anfitrion(documento, antiguedad, puntuacion);
        }

        if (usuario) {
            Sistema::usuarios.agregar(usuario);
        }
    }
    archivo.close();
}

void Persistencia::cargarAlojamientos() {
    std::ifstream archivo("alojamientos.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("Error al abrir alojamientos.txt");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string token;
        VectorManual<std::string> partes;

        while (std::getline(ss, token, '|')) {
            partes.agregar(token);
        }

        if (partes.tamano() < 9) continue;

        std::string codigo = partes.obtener(0);
        std::string nombre = partes.obtener(1);
        std::string docAnfitrion = partes.obtener(2);
        std::string departamento = partes.obtener(3);
        std::string municipio = partes.obtener(4);
        std::string tipo = partes.obtener(5);
        std::string direccion = partes.obtener(6);
        float precio = std::stof(partes.obtener(7));

        Anfitrion* anf = dynamic_cast<Anfitrion*>(Sistema::buscarUsuario(docAnfitrion));
        if (!anf) continue;

        Alojamiento* aloj = new Alojamiento(codigo, nombre, anf, departamento,
                                            municipio, tipo, direccion, precio);

        // Cargar amenidades
        std::istringstream amenidadesStream(partes.obtener(8));
        std::string amenidad;
        while (std::getline(amenidadesStream, amenidad, ',')) {
            aloj->agregarAmenidad(amenidad);
        }

        Sistema::alojamientos.agregar(aloj);
    }
    archivo.close();
}

void Persistencia::moverReservasAHistorico(const Fecha& hoy) {
    for (int i = 0; i < Sistema::reservasActivas.tamano(); ) {
        Reservacion* r = Sistema::reservasActivas.obtener(i);
        if (r->getFechaFin() < hoy) {
            Sistema::historico.agregar(r);
            Sistema::reservasActivas.eliminar(i);
        } else {
            ++i;
        }
    }
    guardarReservasActivas(); // Actualiza el archivo
}

void Persistencia::cargarReservasActivas() {
    std::ifstream archivo("reservas_activas.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("Error al abrir reservas_activas.txt");
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        std::istringstream ss(linea);
        std::string token;
        VectorManual<std::string> partes;

        while (std::getline(ss, token, '|')) {
            partes.agregar(token);
        }

        if (partes.tamano() < 7) continue;

        std::string docHuesped = partes.obtener(1);
        std::string codAlojamiento = partes.obtener(2);
        Fecha inicio = parsearFecha(partes.obtener(3));
        Fecha fin = parsearFecha(partes.obtener(4));

        Huesped* hues = dynamic_cast<Huesped*>(Sistema::buscarUsuario(docHuesped));
        Alojamiento* aloj = Sistema::buscarAlojamientoPorCodigo(codAlojamiento);

        if (!hues || !aloj || !inicio.esValida() || !fin.esValida()) continue;

        int duracion = fin - inicio;
        Reservacion* res = new Reservacion(hues, aloj, inicio, duracion,
                                           partes.obtener(5), partes.obtener(6));

        Sistema::reservasActivas.agregar(res);
        hues->agregarReserva(res);
        aloj->agregarReserva(res);
    }
    archivo.close();
}

void Persistencia::guardarUsuarios() {
    std::ofstream archivo("usuarios.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("Error al guardar usuarios");
    }

    for (int i = 0; i < Sistema::usuarios.tamano(); ++i) {
        Usuario* u = Sistema::usuarios.obtener(i);
        archivo << u->getDocumento() << "|"
                << (dynamic_cast<Huesped*>(u) ? "huesped" : "anfitrion") << "|"
                << u->getAntiguedad() << "|"
                << u->getPuntuacion() << "|\n";
    }
    archivo.close();
}

void Persistencia::guardarAlojamientos() {
    std::ofstream archivo("alojamientos.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("Error al guardar alojamientos");
    }

    for (int i = 0; i < Sistema::alojamientos.tamano(); ++i) {
        Alojamiento* a = Sistema::alojamientos.obtener(i);
        archivo << a->getCodigo() << "|"
                << a->getNombre() << "|"
                << a->getAnfitrion()->getDocumento() << "|"
                << a->getDepartamento() << "|"
                << a->getMunicipio() << "|"
                << a->getTipo() << "|"
                << a->getDireccion() << "|"
                << a->getPrecioNoche() << "|";

        // Amenidades
        auto& amenidades = a->getAmenidades();
        for (int j = 0; j < amenidades.tamano(); ++j) {
            archivo << amenidades.obtener(j);
            if (j < amenidades.tamano() - 1) archivo << ",";
        }
        archivo << "|\n";
    }
    archivo.close();
}

void Persistencia::guardarReservasActivas() {
    std::ofstream archivo("reservas_activas.txt");
    if (!archivo.is_open()) {
        throw std::runtime_error("Error al guardar reservas");
    }

    for (int i = 0; i < Sistema::reservasActivas.tamano(); ++i) {
        Reservacion* r = Sistema::reservasActivas.obtener(i);
        archivo << r->getCodigo() << "|"
                << r->getHuesped()->getDocumento() << "|"
                << r->getAlojamiento()->getCodigo() << "|"
                << formatearFecha(r->getFechaInicio()) << "|"
                << formatearFecha(r->getFechaFin()) << "|"
                << r->getMetodoPago() << "|"
                << r->getAnotaciones() << "\n";
    }
    archivo.close();
}

Fecha Persistencia::parsearFecha(const std::string& strFecha) {
    std::istringstream ss(strFecha);
    int anio, mes, dia;
    char delim;
    ss >> anio >> delim >> mes >> delim >> dia;
    return Fecha(dia, mes, anio);
}

std::string Persistencia::formatearFecha(const Fecha& fecha) {
    std::ostringstream ss;
    ss << fecha.getAnio() << "-"
       << (fecha.getMes() < 10 ? "0" : "") << fecha.getMes() << "-"
       << (fecha.getDia() < 10 ? "0" : "") << fecha.getDia();
    return ss.str();
}
