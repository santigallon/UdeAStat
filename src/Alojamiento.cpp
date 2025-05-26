#include "Alojamiento.h"
#include "Anfitrion.h"
#include "Reservacion.h"
#include <iostream>
#include "VectorManual.h"
#include "Sistema.h"

// Constructor
Alojamiento::Alojamiento(const std::string& cod,
                         const std::string& nom,
                         Anfitrion* anf,
                         const std::string& dep,
                         const std::string& mun,
                         const std::string& tip,
                         const std::string& dir,
                         float precio)
    : codigo(cod), nombre(nom), anfitrion(anf), departamento(dep),
    municipio(mun), tipo(tip), direccion(dir), precioNoche(precio) {
    anfitrion->agregarAlojamiento(this);
}

// Getters
std::string Alojamiento::getCodigo() const { return codigo; }
std::string Alojamiento::getNombre() const { return nombre; }
Anfitrion* Alojamiento::getAnfitrion() const { return anfitrion; }
std::string Alojamiento::getDepartamento() const { return departamento; }
std::string Alojamiento::getMunicipio() const { return municipio; }
std::string Alojamiento::getTipo() const { return tipo; }
std::string Alojamiento::getDireccion() const { return direccion; }
float Alojamiento::getPrecioNoche() const { return precioNoche; }
const VectorManual<std::string>& Alojamiento::getAmenidades() const { return amenidades; }

// Gestión de amenidades
void Alojamiento::agregarAmenidad(const std::string& amenidad) {
    amenidades.agregar(amenidad);
}

// Gestión de reservas
void Alojamiento::agregarReserva(Reservacion* reserva) {
    reservas.agregar(reserva);
}

void Alojamiento::eliminarReserva(Reservacion* reserva) {
    for (int i = 0; i < reservas.tamano(); i++) {
        if (reservas.obtener(i) == reserva) {
            reservas.eliminar(i);
            break;
        }
    }
}

// Verificación de disponibilidad
bool Alojamiento::estaDisponible(const Fecha& inicio, int duracion) const {
    Fecha fin = inicio + duracion;

    for (int i = 0; i < reservas.tamano(); i++) {
        Reservacion* r = reservas.obtener(i);
        Fecha inicioReserva = r->getFechaInicio();
        Fecha finReserva = inicioReserva + r->getDuracion();

        if (!(fin < inicioReserva || inicio > finReserva)) {
            return false;
        }
    }
    return true;
}

// Mostrar información detallada
void Alojamiento::mostrarInfo() const {
    std::cout << "=== Información del Alojamiento ===\n"
              << "Código: " << codigo << "\n"
              << "Nombre: " << nombre << "\n"
              << "Tipo: " << tipo << "\n"
              << "Ubicación: " << municipio << ", " << departamento << "\n"
              << "Dirección: " << direccion << "\n"
              << "Precio/noche: $" << precioNoche << "\n"
              << "Anfitrión: " << anfitrion->getDocumento() << "\n"
              << "Puntuación anfitrión: " << anfitrion->getPuntuacion() << "\n"
              << "Amenidades: ";

    for (int i = 0; i < amenidades.tamano(); i++) {
        std::cout << amenidades.obtener(i);
        if (i < amenidades.tamano() - 1) std::cout << ", ";
    }

    std::cout << "\nReservas activas: " << reservas.tamano()
              << "\n===============================\n";
}

