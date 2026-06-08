#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>

using namespace std;

struct Proyecto {

    int idProyecto;
    string titulo;
    string descripcion;
    int anio;

    Proyecto* siguiente;

}; // Fin struct Proyecto

struct Estudiante {

    int idEstudiante;
    string nombreCompleto;
    string carrera;
    int semestre;
    float promedio;
    int puntaje;

    Proyecto* listaProyectos;
    Estudiante* siguienteHash;
}; // Fin struct Estudiante

#endif
