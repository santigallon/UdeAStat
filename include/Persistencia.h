#ifndef PERSISTENCIA_H
#define PERSISTENCIA_H
#include <string>
#include "Sistema.h"
#include <fstream>
#include <string>

class Persistencia {
public:
    static void cargarUsuarios();
    static void cargarAlojamientos();
    static void cargarReservasActivas();
    static void guardarUsuarios();
    static void guardarAlojamientos();
    static void guardarReservasActivas();
    static void moverReservasAHistorico(const Fecha& hoy);

private:
    static Fecha parsearFecha(const std::string& strFecha);
    static std::string formatearFecha(const Fecha& fecha);
};

#endif // PERSISTENCIA_H
