#include "Usuario.h"

// Constructor
Usuario::Usuario(const std::string& doc, int ant, float punt)
    : documento(doc), antiguedad(ant), puntuacion(punt) {}

// Getters
std::string Usuario::getDocumento() const { return documento; }
int Usuario::getAntiguedad() const { return antiguedad; }
float Usuario::getPuntuacion() const { return puntuacion; }

// Setter con validación
void Usuario::setPuntuacion(float punt) {
    if (punt >= 0.0f && punt <= 5.0f) {
        puntuacion = punt;
    }
}

// Implementación base de mostrarInfo
void Usuario::mostrarInfo() const {
    std::cout << "Documento: " << documento
              << "\nAntigüedad: " << antiguedad << " meses"
              << "\nPuntuación: " << puntuacion << "/5.0"
              << std::endl;
}
