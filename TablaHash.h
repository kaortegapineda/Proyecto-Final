#ifndef TABLAHASH_H
#define TABLAHASH_H


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Estudiante.h"
#include <iostream>
#include <string>

using namespace std;

// Nodo Hash
struct NodoHash {
    Estudiante datos;
    NodoHash* siguiente;
    
    NodoHash(Estudiante estudiante) {
        datos = estudiante;
        siguiente = NULL;
    } // Fin constructor
}; // Fin Struct NodoHash

// Clase de TablaHash
class TablaHash {

private:
    int capacidad;
    NodoHash** tabla;
    int total_estudiantes;

public:
    // Constructor
    TablaHash(int tamanio = 100) {
        capacidad = tamanio;
        tabla = new NodoHash*[capacidad];
        for(int i = 0; i < capacidad; i++) {
            tabla[i] = NULL;
        } // Fin for
        
        total_estudiantes = 0;
    } // Fin constructor
    
    // Destructor
    ~TablaHash() {
        for(int i = 0; i < capacidad; i++) {
            NodoHash* actual = tabla[i];
            
            while(actual != NULL) {
                NodoHash* siguienteNodo = actual->siguiente;

                delete actual;
                actual = siguienteNodo;
            } // Fin while
        } // Fin for

        delete[] tabla;
    } // Fin destructor

    // Función Hash
    int funcionHash(int clave) {
        return clave % capacidad;
    } // Fin funcionHash

    // Función Insertar con Bool
    bool insertar(Estudiante estudiante) {
        int indice =
        funcionHash(estudiante.idEstudiante);
        NodoHash* actual =
        tabla[indice];

        while(actual != NULL) {
            if(actual->datos.idEstudiante ==
               estudiante.idEstudiante) {
               	
                return false;
            } // Fin if
            
            actual = actual->siguiente;
        } // Fin while

        NodoHash* nuevo =
        new NodoHash(estudiante);
        nuevo->siguiente =
        tabla[indice];
        tabla[indice] = nuevo;
        total_estudiantes++;

        return true;
    } // Fin insertar

    // Noo para Buscar
    NodoHash* buscar(int id) {
        int indice =
        funcionHash(id);
        NodoHash* actual =
        tabla[indice];

        while(actual != NULL) {
            if(actual->datos.idEstudiante == id) {

                return actual;
            } // Fin if
            
            actual = actual->siguiente;
        } // Fin while

        return NULL;
    } // Fin buscar

    // Función Eliminar
    bool eliminar(int id) {
        int indice =
        funcionHash(id);
        NodoHash* actual =
        tabla[indice];
        NodoHash* anterior =
        NULL;

        while(actual != NULL) {
            if(actual->datos.idEstudiante == id) {
                if(anterior == NULL) {
                    tabla[indice] =
                    actual->siguiente;
                }else{
                    anterior->siguiente =
                    actual->siguiente;
                } // Fin if

                delete actual;
                total_estudiantes--;

                return true;
            } // Fin if

            anterior = actual;
            actual = actual->siguiente;
        } // Fin while

        return false;
    } // Fin eliminar

    // Función para obtener el total de Estudiantes
    int obtenerTotalEstudiantes() {

        return total_estudiantes;
    } // Fin obtenerTotalEstudiantes

    // Función para obtener un Total de Coliciones
    int obtenerColisiones() {
        int colisiones = 0;

        for(int i = 0; i < capacidad; i++) {
            int cantidad = 0;
            NodoHash* actual =
            tabla[i];

            while(actual != NULL) {
                cantidad++;
                actual =
                actual->siguiente;
            } // Fin while

            if(cantidad > 1) {
                colisiones +=
                (cantidad - 1);
            } // Fin if
        } // Fin for

        return colisiones;
    } // Fin obtenerColisiones

    // Función de Factor de carga
    double obtenerFactorCarga() {
        return (double)
               total_estudiantes /
               capacidad;
    } // Fin obtenerFactorCarga

    // Función para mostrar la tabla
    void mostrarTabla() {
        cout << "\nTablaHash\n";

        for(int i = 0; i < capacidad; i++) {
            cout << "Bucket "
                 << i
                 << " --> ";
            NodoHash* actual =
            tabla[i];

            if(actual == NULL) {
                cout << "NULL";
            }else{
                while(actual != NULL) {
                    cout
                    << "["
                    << actual->datos.idEstudiante
                    << " "
                    << actual->datos.nombreCompleto
                    << "] -> ";

                    actual =
                    actual->siguiente;
                } // Fin while

                cout << "NULL";
            } // Fin if

            cout << endl;
        } // Fin for

    } // Fin mostrarTabla

    // Función para la Estadistica
    void mostrarEstadisticas() {
        cout << "\nEstadistica de Tabla Hash\n";
        cout << "Total estudiantes: "
             << obtenerTotalEstudiantes()
             << endl;

        cout << "Total colisiones: "
             << obtenerColisiones()
             << endl;

        cout << "Factor carga: "
             << obtenerFactorCarga()
             << endl;
    } // Fin mostrarEstadisticas
    
}; // Fin Clase TablaHash

#endif
