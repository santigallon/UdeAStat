#include "Reservacion.h"
#include "Huesped.h"
#include "Alojamiento.h"
#include <iostream>

// Inicialización de variable estática
int Reservacion::contadorCodigos = 0;

// Constructor
Reservacion::Reservacion(Huesped* hues, Alojamiento* aloj, const Fecha& inicio,
                         int dur, const std::string& metodo, const std::string& notas)
    : huesped(hues), alojamiento(aloj), fechaInicio(inicio),
    duracion(dur), metodoPago(metodo), anotaciones(notas.substr(0, 1000)) {

    // Generar código único
    codigo = "RES-" + std::to_string(++contadorCodigos);

    // Obtener fecha actual (hoy)
    time_t ahora = time(nullptr);
    tm* tiempoLocal = localtime(&ahora);
    fechaPago = Fecha(tiempoLocal->tm_mday,
                      tiempoLocal->tm_mon + 1,
                      tiempoLocal->tm_year + 1900);
}

// Getters
std::string Reservacion::getCodigo() const { return codigo; }
Huesped* Reservacion::getHuesped() const { return huesped; }
Alojamiento* Reservacion::getAlojamiento() const { return alojamiento; }
Fecha Reservacion::getFechaInicio() const { return fechaInicio; }
Fecha Reservacion::getFechaFin() const { return fechaInicio + duracion; }
int Reservacion::getDuracion() const { return duracion; }
std::string Reservacion::getMetodoPago() const { return metodoPago; }
std::string Reservacion::getAnotaciones() const { return anotaciones; }
Fecha Reservacion::getFechaPago() const { return fechaPago; }

// Mostrar información detallada
void Reservacion::mostrarInfo() const {
    std::cout << "\n=== Detalles de Reservación ==="
              << "\nCódigo: " << codigo
              << "\nAlojamiento: " << alojamiento->getNombre()
              << " (" << alojamiento->getCodigo() << ")"
              << "\nHuésped: " << huesped->getDocumento()
              << "\nFecha inicio: " << fechaInicio
              << "\nFecha fin: " << getFechaFin()
              << "\nDuración: " << duracion << " noches"
              << "\nMétodo de pago: " << metodoPago
              << "\nMonto total: $" << alojamiento->getPrecioNoche() * duracion
              << "\nFecha de pago: " << fechaPago
              << "\nAnotaciones: " << anotaciones
              << "\n===============================\n";
}
