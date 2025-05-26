#UdeAStay - Sistema de Gestión de Alojamientos

![Escudo UdeA](https://www.udea.edu.co/wps/portal/udea/web/inicio/somos-udea/empleados/gestion-organizacion/banco-recursos-multimedia/!ut/p/z1/lZBBDoIwEEXP4gk6baHAshSsFVIogmA3hpUhUXRhPL_EuEEi4uwmef9N5iOLGmT79tGd2nt37dvzsB8sO2rjxpgISMErBBhTFjIsCU0kRfUL8ANBMHcGQKsIOKOVKFUKABTZ__IJdoGbONdlJvJoS5bl4ctwWJafAey8vkZ2fEJmew_Mzo-VyyOsfe8TgA1eg8kYYVyEPibwBuY6HBsyRWMwgXZzKhVxPDoxTFv89cftUlVVA53q1OoJYvqUNA!!/?1dmy&urile=wcm%3Apath%3A/PortalUdeA/asPortalUdeA/asHomeUdeA/asSomosUdeA/empleados/Gesti%21c3%21b3n+y+organizaci%21c3%21b3n/Banco+de+recursos+multimedia/Contenido/asMenuLateral/logosimbolo-udea)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)

*Proyecto académico* desarrollado para el curso de *Informática II* en la *Universidad de Antioquia*, semestre 2025-1.

##  Descripción del Proyecto
Sistema de gestión para un mercado de estadías hogareñas (homestay) que permite:
- Administrar alojamientos, anfitriones y huéspedes
- Gestionar reservaciones
- Generar reportes y métricas
- Mantener persistencia de datos

## Contexto Académico
*Desafío II* - Mayo 2025  
*Docentes:*  
- Aníbal Guerra  
- Augusto Salazar  

*Objetivos de aprendizaje:*
- Aplicar conceptos de POO en C++
- Desarrollar habilidades de análisis y diseño
- Implementar estructuras de datos eficientes
- Gestionar persistencia de información

##  Funcionalidades Principales
1. *Gestión de usuarios* (Anfitriones y Huéspedes)
2. *Reserva de alojamientos* con validación de fechas
3. *Sistema de persistencia* (archivos planos)
4. *Métricas de rendimiento* (memoria e iteraciones)
5. *Menú interactivo* por roles de usuario

##   Estructura del Proyecto
UdeAStay/
├── include/        # Archivos de cabecera
│   ├── Alojamiento.h
│   ├── Anfitrion.h
│   ├── Fecha.h
│   ├── Huesped.h
│   ├── Metricas.h
│   ├── Persistencia.h
│   ├── Reservacion.h
│   ├── Sistema.h
│   ├── Usuario.h
│   └── VectorManual.h
├── src/           # Implementación
│   ├── Alojamiento.cpp
│   ├── Anfitrion.cpp
│   ├── Fecha.cpp
│   ├── Huesped.cpp
│   ├── Metricas.cpp
│   ├── Persistencia.cpp
│   ├── Reservacion.cpp
│   ├── Sistema.cpp
│   ├── Usuario.cpp
│   └── main.cpp
├── datos/         # Archivos de datos
│   ├── alojamientos.dat
│   ├── anfitriones.dat
│   ├── huespedes.dat
│   └── reservas.dat
├── docs/          # Documentación
│   ├── DiagramaClases.png
│   └── Informe.pdf
└── README.md    

## 🚀 Compilación y Ejecución
```bash
# Compilar (requiere g++)
g++ -std=c++17 src/*.cpp -o UdeAStay

# Ejecutar
./UdeAStay
## 📝 Requisitos Técnicos
- *Lenguaje:* C++17
- *Restricciones:*
  - No usar STL (implementaciones propias)
  - Uso obligatorio de memoria dinámica
  - Modularidad estricta
- *Eficiencia:* Análisis de complejidad requerido

## 📅 Entregables Académicos
1. Diagrama de clases UML
2. Informe técnico detallado
3. Video explicativo (5-14 mins)

## 📜 Derechos Académicos
Este proyecto es desarrollo exclusivo para fines académicos en la Universidad de Antioquia. Queda prohibido cualquier uso comercial sin autorización expresa.

---

*Desarrollado por:*  
[Santiago Gallón](mailto:santiago.gallon@udea.edu.co)  
Facultad de Ingeniería - Universidad de Antioquia  
Andes, Colombia - 2025
```

