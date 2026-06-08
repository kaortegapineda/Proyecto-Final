#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
using namespace std;

// Nodo de conexion
struct NodoConexion {
    int idEstudiante;
    NodoConexion* siguiente;
}; // Fin struct NodoConexion

class Grafo {
private:
	int totalConexiones;
    static const int MAX_ESTUDIANTES = 5000;
    NodoConexion* listaAdyacencia[MAX_ESTUDIANTES];
    bool visitado[MAX_ESTUDIANTES];

    // Funcion DFS recursiva
    void dfsRecursivo(int id) {
        visitado[id] = true;
        cout << id << " ";
        NodoConexion* actual =
        listaAdyacencia[id];

        while(actual != NULL) {
            if(!visitado[actual->idEstudiante]) {
                dfsRecursivo(
                actual->idEstudiante);
            } // Fin if

            actual = actual->siguiente;
        } // Fin while
    } // Fin dfsRecursivo

public:
    Grafo() {
    totalConexiones = 0;
    for(int i = 0;
        i < MAX_ESTUDIANTES;
        i++) {

        listaAdyacencia[i] = NULL;
        visitado[i] = false;
		totalConexiones++;
    } // Fin for
} // Fin constructor

    // Conectar estudiantes
    void conectar(
        int origen,
        int destino
    ){
        if(origen < 0 ||
		   origen >= MAX_ESTUDIANTES ||
		   destino < 0 ||
		   destino >= MAX_ESTUDIANTES) {
		
		    cout << "ID fuera de rango"
		         << endl;
		    return;
		}else if(origen == destino) {
            cout << "No se puede conectar el mismo estudiante"
                 << endl;
                 
            return;
        }else if(estanConectados(
           origen,
           destino)){
            cout << "Conexion repetida"
                 << endl;

            return;
        } // Fin if

        NodoConexion* nuevo1 =
        new NodoConexion;
        
        nuevo1->idEstudiante =
        destino;

        nuevo1->siguiente =
        listaAdyacencia[origen];

        listaAdyacencia[origen] =
        nuevo1;

        NodoConexion* nuevo2 =
        new NodoConexion;

        nuevo2->idEstudiante =
        origen;

        nuevo2->siguiente =
        listaAdyacencia[destino];

        listaAdyacencia[destino] =
        nuevo2;

        cout << "Conexion creada"
             << endl;
    } // Fin conectar

    // Mostrar conexiones
    void mostrarConexiones(
        int id
    ){
        NodoConexion* actual = listaAdyacencia[id];

        if(actual == NULL) {
            cout << "Sin conexiones"
                 << endl;

            return;
        } // Fin if

        cout << "Conexiones de "
             << id
             << endl;
        while(actual != NULL) {
            cout
            << actual->idEstudiante
            << endl;

            actual =
            actual->siguiente;
        } // Fin while
    } // Fin mostrar conexiones

    // Verificar conexion
    bool estanConectados(
        int origen,
        int destino
    ){
        NodoConexion* actual =
        listaAdyacencia[origen];

        while(actual != NULL) {
            if(actual->idEstudiante
               == destino) {

                return true;
            } // Fin if

            actual =
            actual->siguiente;
        } // Fin while

        return false;
    } // Fin estan conectados


    // BFS
    void bfs(int inicio) {
    	if(inicio < 0 ||
	       inicio >= MAX_ESTUDIANTES) {
	       	
	        cout << "ID fuera de rango" << endl;
	
	        return;
	    }

        for(int i = 0;i < MAX_ESTUDIANTES; i++) {
            visitado[i] = false;
            
        } // Fin for
        
        int cola[MAX_ESTUDIANTES];
        int frente = 0;
        int final = 0;

        visitado[inicio] = true;
        cola[final] = inicio;
        final++;

        cout << "BFS "
             << endl;
        while(frente < final) {
            int actual =
            cola[frente];

            frente++;
            cout
            << actual
            << " ";

            NodoConexion* vecino =
            listaAdyacencia[actual];
            while(vecino != NULL) {
                int idVecino =
                vecino->idEstudiante;
                if(!visitado[idVecino]) {
                    visitado[idVecino]
                    = true;

                    cola[final]
                    = idVecino;

                    final++;
                } // Fin if
                
                vecino =
                vecino->siguiente;
            } // Fin while
        } // Fin while

        cout << endl;
    } // Fin bfs


    // DFS
    void dfs(int inicio) {
    	if(inicio < 0 ||
	       inicio >= MAX_ESTUDIANTES) {
	        cout << "ID fuera de rango" << endl;
	
	        return;
	    }
    	
        for(int i = 0; i < MAX_ESTUDIANTES; i++) {

            visitado[i] = false;
        } // Fin for

        cout << "DFS "
             << endl;
        dfsRecursivo(inicio);
        cout << endl;
    } // Fin dfs

    // Destructor
    ~Grafo() {

        for(int i = 0;
            i < MAX_ESTUDIANTES;
            i++) {
            NodoConexion* actual =
            listaAdyacencia[i];

            while(actual != NULL) {
                NodoConexion* temp =
                actual;

                actual =
                actual->siguiente;

                delete temp;
            } // Fin while
        } // Fin for
    } // Fin destructor
    
    int obtenerTotalConexiones() {
    	return totalConexiones;
	} // Fin obtenerTotalConexiones
	
	void mostrarEstadisticas() {
	    cout
	    << "\nEstadistica Grafo"
	    << endl;
	
	    cout
	    << "Total conexiones "
	    << totalConexiones
	    << endl;
	}// Fin mostrarEstadisticas
	
}; // Fin clase Grafo

#endif
