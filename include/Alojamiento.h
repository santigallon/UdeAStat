#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H
#include <string>
#include "Usuario.h"
#include "VectorManual.h"
#include "Fecha.h"

// Declaraciones adelantadas
class Anfitrion;
class Reservacion;

class Alojamiento {
private:
    std::string codigo;
    std::string nombre;
    Anfitrion* anfitrion;
    std::string departamento;
    std::string municipio;
    std::string tipo;  // "casa" o "apartamento"
    std::string direccion;
    float precioNoche;
    VectorManual<std::string> amenidades;
    VectorManual<Reservacion*> reservas;

public:
    Alojamiento(const std::string& cod,
                const std::string& nom,
                Anfitrion* anf,
                const std::string& dep,
                const std::string& mun,
                const std::string& tip,
                const std::string& dir,
                float precio);

    // Getters
    std::string getCodigo() const;
    std::string getNombre() const;
    Anfitrion* getAnfitrion() const;
    std::string getDepartamento() const;
    std::string getMunicipio() const;
    std::string getTipo() const;
    std::string getDireccion() const;
    float getPrecioNoche() const;
    const VectorManual<std::string>& getAmenidades() const;

    // Métodos de gestión
    void agregarAmenidad(const std::string& amenidad);
    void agregarReserva(Reservacion* reserva);
    void eliminarReserva(Reservacion* reserva);

    // Disponibilidad
    bool estaDisponible(const Fecha& inicio, int duracion) const;

    // Mostrar información
    void mostrarInfo() const;
};

#endif // ALOJAMIENTO_H
