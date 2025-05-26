#include "Anfitrion.h"
#include "Alojamiento.h"
#include <iostream>

// Constructor
Anfitrion::Anfitrion(const std::string& doc, int ant, float punt)
    : Usuario(doc, ant, punt) {}

// Métodos de gestión de alojamientos
void Anfitrion::agregarAlojamiento(Alojamiento* alojamiento) {
    alojamientos.agregar(alojamiento);
}

const VectorManual<Alojamiento*>& Anfitrion::getAlojamientos() const {
    return alojamientos;
}

// Implementación de mostrarInfo
void Anfitrion::mostrarInfo() const {
    Usuario::mostrarInfo();
    std::cout << "Alojamientos registrados: " << alojamientos.tamano() << std::endl;
}
