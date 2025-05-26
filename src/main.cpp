#include "Fecha.h"
#include "Usuario.h"
#include "Huesped.h"
#include "Anfitrion.h"
#include "Alojamiento.h"
#include "Reservacion.h"
#include "Persistencia.h"
#include "Metricas.h"
#include "Sistema.h" // Incluir el header de la clase Sistema
#include <iostream>
#include <limits> // Para std::numeric_limits

// Prototipos de funciones
void mostrarMenuPrincipal();
void procesarOpcion(int opcion);
void limpiarBufferEntrada(); // Declaración adelantada

int main() {
    try {
        // Carga inicial de datos
        Persistencia::cargarUsuarios();
        Persistencia::cargarAlojamientos();
        Persistencia::cargarReservasActivas();

        int opcion = 0;
        do {
            mostrarMenuPrincipal();
            std::cin >> opcion;
            limpiarBufferEntrada();
            procesarOpcion(opcion);
            Metricas::contarIteracion();
        } while(opcion != 9);

        // Guardar datos al salir
        Persistencia::guardarUsuarios();
        Persistencia::guardarAlojamientos();
        Persistencia::guardarReservasActivas();

    } catch(const std::exception& e) {
        std::cerr << "\n❌ Error crítico: " << e.what() << std::endl;
        return 1;
    }

    Metricas::mostrar();
    return 0;
}

void mostrarMenuPrincipal() {
    std::cout << "\n=== Sistema de Reservaciones ==="
              << "\n1. Registrar nuevo usuario"
              << "\n2. Registrar alojamiento"
              << "\n3. Buscar alojamientos disponibles"
              << "\n4. Hacer reservación"
              << "\n5. Ver mis reservas (huéspedes)"
              << "\n6. Ver mis alojamientos (anfitriones)"
              << "\n7. Ver métricas del sistema"
              << "\n8. Mostrar todos los alojamientos"
              << "\n9. Salir"
              << "\nIngrese opción: ";
}

void procesarOpcion(int opcion) {
    switch(opcion) {
    case 1: {
        // Lógica para registrar usuario
        std::string doc, tipo;
        int ant;
        float punt;

        std::cout << "\n=== Registrar nuevo usuario ===";
        std::cout << "\nDocumento: ";
        std::getline(std::cin, doc);

        std::cout << "Tipo (huesped/anfitrion): ";
        std::getline(std::cin, tipo);

        std::cout << "Antigüedad (meses): ";
        std::cin >> ant;

        std::cout << "Puntuación inicial (0-5): ";
        std::cin >> punt;
        limpiarBufferEntrada();

        // Registrar en el sistema
        if(tipo == "huesped") {
            Sistema::usuarios.agregar(new Huesped(doc, ant, punt));
        } else {
            Sistema::usuarios.agregar(new Anfitrion(doc, ant, punt));
        }
        std::cout << "Usuario registrado exitosamente!\n";
        break;
    }
    case 7:
        Metricas::mostrar();
        break;
    // ... implementar demás casos
    default:
        std::cout << "Opción no válida\n";
    }
}

void limpiarBufferEntrada() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
