#ifndef RESERVACION_H
#define RESERVACION_H

#include "Fecha.h"
#include <string>

// Declaraciones adelantadas
class Huesped;
class Alojamiento;

class Reservacion {
private:
    static int contadorCodigos;  // Variable estática para códigos únicos
    std::string codigo;
    Huesped* huesped;
    Alojamiento* alojamiento;
    Fecha fechaInicio;
    int duracion;        // en noches
    std::string metodoPago;  // "PSE" o "TCrédito"
    std::string anotaciones;
    Fecha fechaPago;

public:
    Reservacion(Huesped* hues, Alojamiento* aloj, const Fecha& inicio,
                int dur, const std::string& metodo, const std::string& notas = "");

    // Getters
    std::string getCodigo() const;
    Huesped* getHuesped() const;
    Alojamiento* getAlojamiento() const;
    Fecha getFechaInicio() const;
    Fecha getFechaFin() const;
    int getDuracion() const;
    std::string getMetodoPago() const;
    std::string getAnotaciones() const;
    Fecha getFechaPago() const;

    // Mostrar información de la reserva
    void mostrarInfo() const;
};

#endif // RESERVACION_H
