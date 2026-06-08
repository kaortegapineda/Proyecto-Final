#ifndef PILAACCIONES_H
#define PILAACCIONES_H

#include <iostream>
#include <string>

using namespace std;

// Nodo de la pila
struct NodoPila {
    string accion;
    NodoPila* siguiente;
}; // Fin struct NodoPila

class PilaAcciones {
private:
    NodoPila* tope;
    int totalAcciones;

public:
    // Constructor
    PilaAcciones() {
        tope = NULL;
        totalAcciones = 0;
    } // Fin constructor

    // Agregar accion
    void push(
        string accionNueva
    ){
        NodoPila* nuevo =
        new NodoPila;

        nuevo->accion =
        accionNueva;

        nuevo->siguiente =
        tope;

        tope =
        nuevo;

        totalAcciones++;
    } // Fin push

    // Eliminar ultima accion
    void pop() {
        if(tope == NULL) {
        	cout
            << "Sin acciones"
            << endl;

            return;
        } // Fin if

        NodoPila* temp =
        tope;
        cout
        << "Accion eliminada "
        << tope->accion
        << endl;

        tope =
        tope->siguiente;

        delete temp;
        totalAcciones--;
    } // Fin pop

    // Mostrar ultima accion
    void mostrarUltimaAccion() {
        if(tope == NULL) {
            cout
            << "Sin acciones"
            << endl;

            return;
        } // Fin if
        
        cout
        << "Ultima accion "
        << tope->accion
        << endl;
    } // Fin mostrarUltimaAccion

    // Mostrar historial completo
    void mostrarHistorial() {
        if(tope == NULL) {
            cout
            << "Historial vacio"
            << endl;

            return;
        } // Fin if

        NodoPila* actual =
        tope;

        cout
        << "\nHistorial"
        << endl;
        while(actual != NULL) {
            cout
            << actual->accion
            << endl;

            actual =
            actual->siguiente;
        } // Fin while
    } // Fin mostrarHistorial

    // Cantidad de acciones
    int obtenerTotalAcciones() {
        return totalAcciones;
    } // Fin obtenerTotalAcciones

    // Destructor
    ~PilaAcciones() {
        while(tope != NULL) {

            NodoPila* temp =
            tope;

            tope =
            tope->siguiente;

            delete temp;
        } // Fin while
    } // Fin destructor
}; // Fin clase

#endif
