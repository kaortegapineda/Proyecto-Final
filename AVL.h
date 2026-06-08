#ifndef AVL_H
#define AVL_H

#include <iostream>
#include "Estudiante.h"

using namespace std;

class ArbolAVL {
private:
    struct NodoAVL {
        Estudiante estudiante;
        NodoAVL* izquierda;
        NodoAVL* derecha;
        int altura;
    }; // Fin Struct NodoAVL

    NodoAVL* raiz;
    int totalNodos;

    // Función para obtener la altura
    int obtenerAltura(NodoAVL* nodo) {
        if(nodo == NULL) {
            return 0;
        } // Fin if

        return nodo->altura;
    } // Fin obtenerAltura

    // Función para obtener el maximo
    int maximo(int a, int b) {
        if(a > b) {
            return a;
        } // Fin if

        return b;
    } // Fin maximo

    // Función para obtener el balance
    int obtenerBalance(NodoAVL* nodo) {
        if(nodo == NULL) {
            return 0;
        } // Fin if

        return obtenerAltura(nodo->izquierda)
             - obtenerAltura(nodo->derecha);
    } // Fin obtenerBalance

    // Función que rote a la derecha
    NodoAVL* rotarDerecha(NodoAVL* y){
    	
        NodoAVL* x = y->izquierda;
        NodoAVL* T2 = x->derecha;
        
        x->derecha = y;
        y->izquierda = T2;
        y->altura =
        maximo(
            obtenerAltura(y->izquierda),
            obtenerAltura(y->derecha)
        ) + 1;

        x->altura =
        maximo(
            obtenerAltura(x->izquierda),
            obtenerAltura(x->derecha)
        ) + 1;

        return x;
    } // Fin rotarDerecha

    // Función para rotar a la izquierda
    NodoAVL* rotarIzquierda(NodoAVL* x) {
        NodoAVL* y = x->derecha;
        NodoAVL* T2 = y->izquierda;

        y->izquierda = x;
        x->derecha = T2;

        x->altura =
        maximo(
            obtenerAltura(x->izquierda),
            obtenerAltura(x->derecha)
        ) + 1;

        y->altura =
        maximo(
            obtenerAltura(y->izquierda),
            obtenerAltura(y->derecha)
        ) + 1;

        return y;
    } // Fin rotarIzquierda

    // Función para insertar el AVL
    NodoAVL* insertarAVL(
        NodoAVL* nodo,
        Estudiante estudiante
    ){
        if(nodo == NULL) {
            NodoAVL* nuevo =
            new NodoAVL;

            nuevo->estudiante =
            estudiante;

            nuevo->izquierda = NULL;
            nuevo->derecha = NULL;

            nuevo->altura = 1;
            totalNodos++;

            return nuevo;
        } // Fin if
        
        if(estudiante.puntaje < nodo->estudiante.puntaje){
            nodo->izquierda =
            insertarAVL(
                nodo->izquierda,
                estudiante
            );
        }else if(estudiante.puntaje >
                nodo->estudiante.puntaje){
            nodo->derecha =
            insertarAVL(
                nodo->derecha,
                estudiante
            );
        }else{
            // Desempate por ID
            if(estudiante.idEstudiante <
               nodo->estudiante.idEstudiante) {

                nodo->izquierda =
                insertarAVL(
                    nodo->izquierda,
                    estudiante
                );
            }else{
                nodo->derecha =
                insertarAVL(
                    nodo->derecha,
                    estudiante
                );
            } // Fin if
        } // Fin if
        
        nodo->altura =
        1 +
        maximo(
            obtenerAltura(
                nodo->izquierda
            ),
            obtenerAltura(
                nodo->derecha
            )
        );
        int balance =
        obtenerBalance(nodo);

        // Caso Izquierda-Izquierda
		if(balance > 1 &&
		   nodo->izquierda != NULL &&
		   estudiante.puntaje <=
		   nodo->izquierda->estudiante.puntaje) {
		
		    return rotarDerecha(nodo);
		}
		
		// Caso Derecha-Derecha
		if(balance < -1 &&
		   nodo->derecha != NULL &&
		   estudiante.puntaje >=
		   nodo->derecha->estudiante.puntaje) {
		
		    return rotarIzquierda(nodo);
		}
		
		// Caso Izquierda-Derecha
		if(balance > 1 &&
		   nodo->izquierda != NULL &&
		   estudiante.puntaje >
		   nodo->izquierda->estudiante.puntaje) {
		
		    nodo->izquierda =
		    rotarIzquierda(
		        nodo->izquierda
		    );
		
		    return rotarDerecha(nodo);
		}
		
		// Caso Derecha-Izquierda
		if(balance < -1 &&
		   nodo->derecha != NULL &&
		   estudiante.puntaje <
		   nodo->derecha->estudiante.puntaje) {
		
		    nodo->derecha =
		    rotarDerecha(
		        nodo->derecha
		    );
		
		    return rotarIzquierda(nodo);
		}

        return nodo;
    } // Fin insertarAVL

    // Función InOrden
    void recorridoInOrden(
        NodoAVL* nodo
    ){

        if(nodo != NULL){
            recorridoInOrden(
                nodo->izquierda
            );

            cout
            << nodo->estudiante.nombreCompleto
            << " Score "
            << nodo->estudiante.puntaje
            << endl;

            recorridoInOrden(
                nodo->derecha
            );
        } // Fin if
    } // Fin recorridoInOrden

    // Ranking Decendente
    void mostrarRankingRec(
        NodoAVL* nodo,
        int& posicion
    ){
        if(nodo != NULL) {
            mostrarRankingRec(
                nodo->derecha,
                posicion
            );

            cout
            << posicion
            << ". "
            << nodo->estudiante.nombreCompleto
            << " Score "
            << nodo->estudiante.puntaje
            << endl;

            posicion++;
            mostrarRankingRec(
                nodo->izquierda,
                posicion
            );
        } // Fin if
    } // Fin mostrarRankingRec

    // Buscar el Score
    NodoAVL* buscarScore(
        NodoAVL* nodo,
        int score
    ){
        if(nodo == NULL) {
            return NULL;
        } // Fin if
        
        if(score ==
           nodo->estudiante.puntaje) {

            return nodo;
        } // Fin if

        if(score <
           nodo->estudiante.puntaje) {

            return buscarScore(
                nodo->izquierda,
                score
            );
        } // Fin if

        return buscarScore(
            nodo->derecha,
            score
        );
    } // Fin buscarScore
    
    void buscarTodosScore(
    NodoAVL* nodo,
    int score
	){
	    if(nodo == NULL) {
	        return;
	    } // Fin if
	
	    buscarTodosScore(
	        nodo->izquierda,
	        score
	    );
	
	    if(nodo->estudiante.puntaje == score) {
	        cout
	        << "ID "
	        << nodo->estudiante.idEstudiante
	        << endl;
	
	        cout
	        << "Nombre "
	        << nodo->estudiante.nombreCompleto
	        << endl;
	
	        cout
	        << "Carrera "
	        << nodo->estudiante.carrera
	        << endl;
	
	        cout
	        << "Puntaje "
	        << nodo->estudiante.puntaje
	        << endl;
	
	        cout << endl;
	    } // Fin if
	    
	    buscarTodosScore(
	        nodo->derecha,
	        score
	    );
	} // Fin buscarTodosScore

public:
    ArbolAVL() {
        raiz = NULL;
        totalNodos = 0;
    } // Fin constructor

    // Función Insertar
    void insertar(
        Estudiante estudiante
    ){
        raiz =
        insertarAVL(
            raiz,
            estudiante
        );
    } // Fin insertar

    // Mostrar Ranking
    void mostrarRanking() {
        int posicion = 1;
        mostrarRankingRec(
            raiz,
            posicion
        );
    } // Fin mostrarRanking

    // Mostrar InOrden
    void mostrarInOrden() {
        recorridoInOrden(raiz);
    } // Fin mostrarInOrden

    /*/ Función buscar Score
    void buscarPorScore(
        int score
    ){
        NodoAVL* encontrado =
        buscarScore(
            raiz,
            score
        );

        if(encontrado == NULL) {
            cout
            << "Score no encontrado"
            << endl;

            return;
        } // Fin if

        cout
        << "ID "
        << encontrado->estudiante.idEstudiante
        << endl;

        cout
        << "Nombre "
        << encontrado->estudiante.nombreCompleto
        << endl;
    } // Fin buscarPorScore */

    // Función mostrar estadistica
    void mostrarEstadisticas() {

        cout
        << "\Altura "
        << obtenerAltura(raiz)
        << endl;

        cout
        << "Balance Raiz "
        << obtenerBalance(raiz)
        << endl;

        cout
        << "Nodo "
        << totalNodos
        << endl;
    } // Fin mostrarEstadisticas
    
    void buscarPorScore(
	int score
	){
	    cout
	    << "\Resultado\n"
	    << endl;
	
	    buscarTodosScore(
	        raiz,
	        score
	    );
	} // Fin buscarPorScore
	
	int obtenerAlturaArbol() {
	    return obtenerAltura(raiz);
	} // Fin obtenerAlturaArbol
}; // Fin Clase

#endif
