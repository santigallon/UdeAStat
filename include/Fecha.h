#ifndef FECHA_H
#define FECHA_H
#include <string>
#include <iostream>

class Fecha {
private:
    int dia, mes, anio;

public:
    // Constructor con valores por defecto
    Fecha(int d = 1, int m = 1, int a = 2000);

    // Validación de fecha
    bool esValida() const;

    // Operadores
    Fecha operator+(int dias) const;      // Suma de días
    int operator-(const Fecha& otra) const; // Diferencia en días
    bool operator>(const Fecha& otra) const; // Comparación
    bool operator<(const Fecha& otra) const;
    bool operator==(const Fecha& otra) const;

    // Operador de salida para formato personalizado
    friend std::ostream& operator<<(std::ostream& os, const Fecha& f);

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;
};

#endif // FECHA_H
