#ifndef VECTOR_MANUAL_H
#define VECTOR_MANUAL_H
#include <string>
#include <stdexcept> // Para std::out_of_range

template<typename T>
class VectorManual {
private:
    T* datos;
    int capacidad;
    int tam;

    void redimensionar(int nuevaCapacidad) {
        T* nuevosDatos = new T[nuevaCapacidad];
        for (int i = 0; i < tam; i++) {
            nuevosDatos[i] = datos[i];
        }
        delete[] datos;
        datos = nuevosDatos;
        capacidad = nuevaCapacidad;
    }

public:
    VectorManual(int cap = 10) : capacidad(cap), tam(0) {
        datos = new T[capacidad];
    }

    ~VectorManual() {
        delete[] datos;
    }

    void agregar(const T& elemento) {
        if (tam == capacidad) {
            redimensionar(capacidad * 2);
        }
        datos[tam++] = elemento;
    }

    T& obtener(int indice) {
        if (indice < 0 || indice >= tam) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return datos[indice];
    }

    const T& obtener(int indice) const {
        if (indice < 0 || indice >= tam) {
            throw std::out_of_range("Índice fuera de rango");
        }
        return datos[indice];
    }

    void eliminar(int indice) {
        if (indice < 0 || indice >= tam) return;

        for (int i = indice; i < tam - 1; i++) {
            datos[i] = datos[i + 1];
        }
        tam--;

        if (tam < capacidad / 4 && capacidad > 10) {
            redimensionar(capacidad / 2);
        }
    }

    int tamano() const {
        return tam;
    }

    bool vacio() const {
        return tam == 0;
    }
};

#endif // VECTOR_MANUAL_H
