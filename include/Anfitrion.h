#ifndef ANFITRION_H
#define ANFITRION_H
#include <string>
#include "Usuario.h"
#include "VectorManual.h"

// Declaración adelantada
class Alojamiento;

class Anfitrion : public Usuario {
private:
    VectorManual<Alojamiento*> alojamientos;

public:
    Anfitrion(const std::string& doc, int ant, float punt);

    // Gestión de alojamientos
    void agregarAlojamiento(Alojamiento* alojamiento);
    const VectorManual<Alojamiento*>& getAlojamientos() const;

    // Sobreescritura del método virtual
    void mostrarInfo() const override;
};

#endif // ANFITRION_H
