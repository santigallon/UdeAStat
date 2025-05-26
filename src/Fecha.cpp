#include "Fecha.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Constructor
Fecha::Fecha(int d, int m, int a) : dia(d), mes(m), anio(a) {}

// Validación de fecha
bool Fecha::esValida() const {
    if (anio < 2000 || anio > 2100) return false;
    if (mes < 1 || mes > 12) return false;

    int diasMes = 31;
    if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        diasMes = 30;
    } else if (mes == 2) {
        // Verificar año bisiesto
        diasMes = (anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0)) ? 29 : 28;
    }
    return dia >= 1 && dia <= diasMes;
}

// Operador suma de días
Fecha Fecha::operator+(int dias) const {
    Fecha nueva = *this;
    nueva.dia += dias;

    while (true) {
        int diasMes = 31;
        if (nueva.mes == 4 || nueva.mes == 6 || nueva.mes == 9 || nueva.mes == 11) {
            diasMes = 30;
        } else if (nueva.mes == 2) {
            diasMes = (nueva.anio % 4 == 0 && (nueva.anio % 100 != 0 || nueva.anio % 400 == 0)) ? 29 : 28;
        }

        if (nueva.dia <= diasMes) break;

        nueva.dia -= diasMes;
        nueva.mes++;
        if (nueva.mes > 12) {
            nueva.mes = 1;
            nueva.anio++;
        }
    }
    return nueva;
}

// Diferencia entre fechas (aproximación)
int Fecha::operator-(const Fecha& otra) const {
    int diasThis = dia + mes * 30 + anio * 365;
    int diasOtra = otra.dia + otra.mes * 30 + otra.anio * 365;
    return abs(diasThis - diasOtra);
}

// Operadores de comparación
bool Fecha::operator>(const Fecha& otra) const {
    if (anio != otra.anio) return anio > otra.anio;
    if (mes != otra.mes) return mes > otra.mes;
    return dia > otra.dia;
}

bool Fecha::operator<(const Fecha& otra) const {
    if (anio != otra.anio) return anio < otra.anio;
    if (mes != otra.mes) return mes < otra.mes;
    return dia < otra.dia;
}

bool Fecha::operator==(const Fecha& otra) const {
    return dia == otra.dia && mes == otra.mes && anio == otra.anio;
}

// Operador de salida con formato
ostream& operator<<(ostream& os, const Fecha& f) {
    const string meses[] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                            "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    const string dias[] = {"Domingo", "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado"};

    // Ajuste para algoritmo de Zeller
    int m = f.mes;
    int a = f.anio;
    if (m < 3) {
        m += 12;
        a -= 1;
    }

    int k = a % 100;
    int j = a / 100;
    int q = f.dia;

    int h = (q + (13*(m + 1))/5 + k + (k/4) + (j/4) + 5*j) % 7;

    // Ajustar índice (0 = Sábado, 1 = Domingo...)
    int indiceDia = (h + 5) % 7;

    os << dias[indiceDia] << ", " << q << " de " << meses[f.mes-1] << " del " << f.anio;
    return os;
}

// Getters
int Fecha::getDia() const { return dia; }
int Fecha::getMes() const { return mes; }
int Fecha::getAnio() const { return anio; }
