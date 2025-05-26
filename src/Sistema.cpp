#include "Sistema.h"
#include "Huesped.h"
#include "Anfitrion.h"
#include <iostream>
#include <limits>
// Inicialización de variables estáticas
VectorManual<Usuario*> Sistema::usuarios;
VectorManual<Alojamiento*> Sistema::alojamientos;
VectorManual<Reservacion*> Sistema::reservasActivas;
VectorManual<Reservacion*> Sistema::historico;

// Implementación de métodos existentes
Usuario* Sistema::buscarUsuario(const std::string& documento) {
    for (int i = 0; i < usuarios.tamano(); ++i) {
        Usuario* u = usuarios.obtener(i);
        if (u->getDocumento() == documento) {
            return u;
        }
    }
    return nullptr;
}

Alojamiento* Sistema::buscarAlojamientoPorCodigo(const std::string& codigo) {
    for (int i = 0; i < alojamientos.tamano(); ++i) {
        Alojamiento* a = alojamientos.obtener(i);
        if (a->getCodigo() == codigo) {
            return a;
        }
    }
    return nullptr;
}

// Implementación de nuevos métodos
void Sistema::iniciarSesion() {
    std::string documento;
    std::cout << "Ingrese su documento: ";
    std::cin >> documento;
    limpiarBufferEntrada();

    Usuario* usuario = buscarUsuario(documento);
    if (!usuario) {
        std::cout << "❌ Usuario no encontrado.\n";
        return;
    }

    if (auto* huesped = dynamic_cast<Huesped*>(usuario)) {
        mostrarMenuHuesped(huesped);
    } else if (auto* anfitrion = dynamic_cast<Anfitrion*>(usuario)) {
        mostrarMenuAnfitrion(anfitrion);
    }
}

void Sistema::limpiarBufferEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Sistema::mostrarMenuHuesped(Huesped* huesped) {
    // Implementar menú para huéspedes
    std::cout << "\nBienvenido huésped " << huesped->getDocumento() << std::endl;
    // ... más opciones del menú
}

void Sistema::mostrarMenuAnfitrion(Anfitrion* anfitrion) {
    // Implementar menú para anfitriones
    std::cout << "\nBienvenido anfitrión " << anfitrion->getDocumento() << std::endl;
    // ... más opciones del menú
}

VectorManual<Alojamiento*> Sistema::buscarAlojamientosDisponibles(
    const std::string& municipio,
    float precioMax,
    float puntuacionMin,
    const Fecha& inicio,
    int duracion)
{
    VectorManual<Alojamiento*> resultados;
    for (int i = 0; i < alojamientos.tamano(); ++i) {
        Alojamiento* a = alojamientos.obtener(i);
        if (a->getMunicipio() == municipio &&
            a->getPrecioNoche() <= precioMax &&
            a->getAnfitrion()->getPuntuacion() >= puntuacionMin &&
            a->estaDisponible(inicio, duracion)) {
            resultados.agregar(a);
        }
    }
    return resultados;
}
