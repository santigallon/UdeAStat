#include <string>
#ifndef METRICAS_H
#define METRICAS_H

#include "VectorManual.h"
#include "Usuario.h"
#include "Huesped.h"
#include "Anfitrion.h"
#include "Alojamiento.h"
#include "Reservacion.h"
#include <iostream>

class Metricas {
private:
    static int iteraciones;
    static size_t memoria;

    // Declaración de la plantilla
    template<typename T>
    static size_t calcularMemoriaObjeto(const T* obj);

public:
    static void contarIteracion();
    static void actualizarMemoria();
    static void mostrar();
};

// Implementación de la plantilla (debe estar en el header)
template<typename T>
size_t Metricas::calcularMemoriaObjeto(const T* obj) {
    size_t total = sizeof(*obj);

    // Verificar si es un Usuario
    if (const Usuario* usuario = dynamic_cast<const Usuario*>(obj)) {
        if (dynamic_cast<const Huesped*>(usuario)) {
            total += sizeof(VectorManual<Reservacion*>);
        } else if (dynamic_cast<const Anfitrion*>(usuario)) {
            total += sizeof(VectorManual<Alojamiento*>);
        }
    }
    return total;
}

#endif // METRICAS_H
