#include "Metricas.h"
#include "Sistema.h"

// Inicialización de miembros estáticos
int Metricas::iteraciones = 0;
size_t Metricas::memoria = 0;

void Metricas::contarIteracion() {
    iteraciones++;
}

void Metricas::actualizarMemoria() {
    memoria = 0;

    // Calcular memoria de usuarios
    for (int i = 0; i < Sistema::usuarios.tamano(); ++i) {
        memoria += calcularMemoriaObjeto(Sistema::usuarios.obtener(i));
    }

    // Calcular memoria de alojamientos
    for (int i = 0; i < Sistema::alojamientos.tamano(); ++i) {
        Alojamiento* a = Sistema::alojamientos.obtener(i);
        memoria += sizeof(*a) +
                   sizeof(VectorManual<Reservacion*>) +
                   a->getAmenidades().tamano() * sizeof(std::string);
    }

    // Calcular memoria de reservas
    auto calcularMemoriaReservas = [](const VectorManual<Reservacion*>& reservas) {
        size_t total = 0;
        for (int i = 0; i < reservas.tamano(); ++i) {
            total += sizeof(*reservas.obtener(i));
        }
        return total;
    };

    memoria += calcularMemoriaReservas(Sistema::reservasActivas);
    memoria += calcularMemoriaReservas(Sistema::historico);
}

void Metricas::mostrar() {
    actualizarMemoria();
    std::cout << "\n=== Métricas del Sistema ==="
              << "\nIteraciones totales: " << iteraciones
              << "\nMemoria utilizada: "
              << (memoria > 1048576 ? memoria/1048576 : memoria > 1024 ? memoria/1024 : memoria)
              << (memoria > 1048576 ? " MB" : memoria > 1024 ? " KB" : " bytes")
              << "\n============================\n";
}
