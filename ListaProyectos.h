#ifndef LISTAPROYECTOS_H
#define LISTAPROYECTOS_H

#include <iostream>
#include <string>
#include "Estudiante.h"

using namespace std;

class ListaProyectos {
public:
    // Agregar proyecto
    bool agregarProyecto(
        Estudiante* estudiante,
        int idProyecto,
        string titulo,
        string descripcion,
        int anio
    ){
    	
    	cout << "Entrando a 'Agregar Proyecto'..." << endl;
        Proyecto* actual = estudiante->listaProyectos;

        while(actual != NULL) {
            if(actual->idProyecto ==
               idProyecto) {
                cout
                << "Proyecto repetido"
                << endl;

                return false;
            } // Fin if
            
            actual =
            actual->siguiente;
        } // Fin while

        Proyecto* nuevo = new Proyecto;

        nuevo->idProyecto = idProyecto;

        nuevo->titulo = titulo;

        nuevo->descripcion = descripcion;

        nuevo->anio = anio;

        nuevo->siguiente = estudiante->listaProyectos;

        estudiante->listaProyectos = nuevo;

        cout << "Proyecto agregado Correctamente..." << endl;

        return true;
    } // Fin agregarProyecto

    // Mostrar proyectos
    void mostrarProyectos(
        Estudiante* estudiante
    ){
        Proyecto* actual =
        estudiante->listaProyectos;

        if(actual == NULL) {
            cout
            << "Sin proyectos"
            << endl;

            return;
        } // Fin if

        while(actual != NULL) {
            cout
            << "\nID Proyecto "
            << actual->idProyecto
            << endl;

            cout
            << "Titulo "
            << actual->titulo
            << endl;

            cout
            << "Descripcion "
            << actual->descripcion
            << endl;

            cout
            << "Anio "
            << actual->anio
            << endl;

            actual =
            actual->siguiente;
        } // Fin while
    } // Fin mostrarProyectos
    
    // Buscar proyecto
    Proyecto* buscarProyecto(
        Estudiante* estudiante,
        int idProyecto
    ){
        Proyecto* actual =
        estudiante->listaProyectos;

        while(actual != NULL) {
            if(actual->idProyecto ==
               idProyecto) {

                return actual;
            } // Fin if

            actual =
            actual->siguiente;
        } // Fin while

        return NULL;
    } // Fin buscarProyecto

    // Eliminar proyecto
    bool eliminarProyecto(
        Estudiante* estudiante,
        int idProyecto
    ){
        Proyecto* actual =
        estudiante->listaProyectos;

        Proyecto* anterior =
        NULL;

        while(actual != NULL) {
            if(actual->idProyecto ==
               idProyecto) {
                if(anterior == NULL) {
                    estudiante->listaProyectos =
                    actual->siguiente;
                }else{
                	anterior->siguiente =
                    actual->siguiente;
                } // Fin if

                delete actual;
                cout
                << "Proyecto eliminado"
                << endl;

                return true;
            } // Fin if

            anterior =
            actual;

            actual =
            actual->siguiente;
        } // Fin while

        cout
        << "Proyecto no encontrado"
        << endl;

        return false;
    } // Fin eliminarProyecto

    // Contar proyectos
    int contarProyectos(
        Estudiante* estudiante
    ){
        int total = 0;

        Proyecto* actual =
        estudiante->listaProyectos;

        while(actual != NULL) {
            total++;
            actual =
            actual->siguiente;
        } // Fin while
        return total;
    } // Fin contarProyectos
}; // Fin clase

#endif
