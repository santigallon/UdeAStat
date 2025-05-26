#include "Huesped.h"
#include "Reservacion.h"
#include "Fecha.h"
#include <iostream>

// Constructor
Huesped::Huesped(const std::string& doc, int ant, float punt)
    : Usuario(doc, ant, punt) {}

// Métodos de gestión de reservas
void Huesped::agregarReserva(Reservacion* reserva) {
    reservas.agregar(reserva);
}

void Huesped::eliminarReserva(int indice) {
    if (indice >= 0 && indice < reservas.tamano()) {
        reservas.eliminar(indice);
    }
}

const VectorManual<Reservacion*>& Huesped::getReservas() const {
    return reservas;
}

// Verificación de solapamiento
bool Huesped::tieneReservaSolapada(const Fecha& inicio, int duracion) const {
    Fecha fin = inicio + duracion;

    for (int i = 0; i < reservas.tamano(); i++) {
        Reservacion* r = reservas.obtener(i);
        Fecha inicioReserva = r->getFechaInicio();
        Fecha finReserva = inicioReserva + r->getDuracion();

        if (!(fin < inicioReserva || inicio > finReserva)) {
            return true;
        }
    }
    return false;
}

// Implementación de mostrarInfo
void Huesped::mostrarInfo() const {
    Usuario::mostrarInfo();
    std::cout << "Reservas activas: " << reservas.tamano() << std::endl;
}
