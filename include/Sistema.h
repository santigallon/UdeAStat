#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include "VectorManual.h"
#include "Usuario.h"
#include "Alojamiento.h"
#include "Reservacion.h"

class Sistema {
public:
    static VectorManual<Usuario*> usuarios;
    static VectorManual<Alojamiento*> alojamientos;
    static VectorManual<Reservacion*> reservasActivas;
    static VectorManual<Reservacion*> historico;

    static Usuario* buscarUsuario(const std::string& documento);
    static Alojamiento* buscarAlojamientoPorCodigo(const std::string& codigo);

    static VectorManual<Alojamiento*> buscarAlojamientosDisponibles(
        const std::string& municipio,
        float precioMax,
        float puntuacionMin,
        const Fecha& inicio,
        int duracion
        );

    static void iniciarSesion();
    static void limpiarBufferEntrada();
    static void mostrarMenuHuesped(Huesped* huesped);
    static void mostrarMenuAnfitrion(Anfitrion* anfitrion);
};

#endif // SISTEMA_H
