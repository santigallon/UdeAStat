#ifndef HUESPED_H
#define HUESPED_H
#include <string>
#include "Usuario.h"
#include "VectorManual.h"

// Declaración adelantada
class Reservacion;
class Fecha;

class Huesped : public Usuario {
private:
    VectorManual<Reservacion*> reservas;

public:
    Huesped(const std::string& doc, int ant, float punt);

    // Gestión de reservas
    void agregarReserva(Reservacion* reserva);
    void eliminarReserva(int indice);
    const VectorManual<Reservacion*>& getReservas() const;

    // Verificación de solapamiento
    bool tieneReservaSolapada(const Fecha& inicio, int duracion) const;

    // Sobreescritura del método virtual
    void mostrarInfo() const override;
};

#endif // HUESPED_H
