#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>

class Usuario {
protected:
    std::string documento;
    int antiguedad;    // en meses
    float puntuacion;  // de 0 a 5.0

public:
    Usuario(const std::string& doc, int ant, float punt);
    virtual ~Usuario() = default;

    // Getters
    std::string getDocumento() const;
    int getAntiguedad() const;
    float getPuntuacion() const;

    // Setter con validación
    void setPuntuacion(float punt);

    // Método virtual para mostrar información
    virtual void mostrarInfo() const;
};

#endif // USUARIO_H
