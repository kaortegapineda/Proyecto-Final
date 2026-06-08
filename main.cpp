#include <iostream>
#include <string>
#include <cstdio>

#include "Estudiante.h"
#include "TablaHash.h"
#include "AVL.h"
#include "Grafo.h"
#include "ListaProyectos.h"
#include "PilaAcciones.h"
#include "Benchmark.h"
#include "CargadorCSV.h"

using namespace std;

int main() {

    TablaHash tabla(100);

    ArbolAVL arbol;

    Grafo red;

    ListaProyectos proyectos;

    PilaAcciones historial;

    Benchmark benchmark;

    int opcion;

    do {
        cout << "\nSistema de Estudiantes";

        cout << "\n 1. Cargar CSV";
        cout << "\n 2. Registrar estudiante";
        cout << "\n 3. Buscar estudiante";
        cout << "\n 4. Eliminar estudiante";
        cout << "\n 5. Agregar proyecto";
        cout << "\n 6. Mostrar proyectos";
        cout << "\n 7. Conectar estudiantes";
        cout << "\n 8. Verificar conexion";
        cout << "\n 9. Mostrar conexiones";
        cout << "\n10. BFS";
        cout << "\n11. DFS";
        cout << "\n12. Ranking academico";
        cout << "\n13. Estadisticas";
        cout << "\n14. Benchmark";
        cout << "\n15. Salir" << endl;

        cout << "\nOpcion: ";
        cin >> opcion;

        switch(opcion) {
		// Cargar el CSV
        case 1: {
        	cout << "Inicio de carga.." << endl;
			cargarCSV("estudiantes.csv", tabla, arbol);
			historial.push("Cargar Archivo CSV");
			
		    break;
        } // Fin cargar CSV

        // Registrar un nuevo estudiatntes
        case 2: {
            Estudiante estudiante;

            cout << "ID: ";
            cin >> estudiante.idEstudiante;

            cin.ignore();

            cout << "Nombre: ";
            getline(cin,
                    estudiante.nombreCompleto);

            cout << "Carrera: ";
            getline(cin, estudiante.carrera);

            cout << "Semestre: ";
            cin >> estudiante.semestre;

            cout << "Promedio: ";
            cin >> estudiante.promedio;

            cout << "Puntaje habilidad: ";
            cin >> estudiante.puntaje;

            if(tabla.insertar(estudiante)) {
                arbol.insertar(estudiante);

                historial.push(
                "Registro estudiante");

                cout
                << "Estudiante registrado"
                << endl;
            }else{
                cout
                << "ID duplicado"
                << endl;
            } // Fin if

            break;
        } // Fin registrar un nuevo estudiante

        // Buscar un estudiante
        case 3: {
            int id;

            cout << "ID: ";
            cin >> id;
            NodoHash* encontrado =
            tabla.buscar(id);
            if(encontrado == NULL) {
                cout
                << "No encontrado"
                << endl;
            }else{
                cout
                << "\nID: "
                << encontrado->datos.idEstudiante
                << endl;

                cout
                << "Nombre: "
                << encontrado->datos.nombreCompleto
                << endl;

                cout
                << "Carrera: "
                << encontrado->datos.carrera
                << endl;

                cout
                << "Semestre: "
                << encontrado->datos.semestre
                << endl;

                cout
                << "Promedio: "
                << encontrado->datos.promedio
                << endl;

                cout
                << "Score: "
                << encontrado->datos.puntaje
                << endl;
            } // Fin if
            break;
        } // Fin buscar

        // Eliminar estudiante
        case 4: {
            int id;
            
            cout << "ID: ";
            cin >> id;
            
            if(tabla.eliminar(id)) {
                historial.push(
                "Eliminar estudiante");

                cout
                << "Eliminado"
                << endl;
            }else{
                cout
                << "No encontrado"
                << endl;
            } // Fin if

            break;
        } // Fin eliminar

        // Agregar un proyecto
        case 5: {

            int id;

            cout << "ID estudiante: ";
            cin >> id;

            NodoHash* nodo = tabla.buscar(id);

            if(nodo == NULL) {
                cout << "No existe" << endl;
                
                break;
            } // Fin if

            int idProyecto;
            string titulo;
            string descripcion;
            int anio;

            cout << "ID proyecto: ";
            cin >> idProyecto;
            
            cin.ignore();

            cout << "Titulo: ";
            getline(cin, titulo);

            cout << "Descripcion: ";
            getline(cin, descripcion);

            cout << "Ano: ";
            cin >> anio;

            proyectos.agregarProyecto(
                &nodo->datos,
                idProyecto,
                titulo,
                descripcion,
                anio
            );

            historial.push("Agregar proyecto");

            break;
        } // Fin agregar un proyecto

        // Mostrar Proyectos
        case 6: {
            int id;

            cout
            << "ID estudiante: ";
            cin >> id;

            NodoHash* nodo =
            tabla.buscar(id);

            if(nodo == NULL) {
                cout
                << "No encontrado"
                << endl;
            }else{
                proyectos.mostrarProyectos(
                    &nodo->datos
                );
            } // Fin if

            break;
        } // Fin mostrar proyecto

        // Conectar estudiantes con proyectos
        case 7: {

            int origen;
            int destino;

            cout
            << "Origen: ";
            cin >> origen;

            cout
            << "Destino: ";
            cin >> destino;

            red.conectar(
                origen,
                destino
            );

            historial.push("Conectar estudiantes");

            break;
        } // Fin conectar estudiantes con proyectos

        // Verificar conexiones
        case 8: {
            int origen;
            int destino;

            cout
            << "ID origen: ";
            cin >> origen;

            cout
            << "ID destino: ";
            cin >> destino;

            if(red.estanConectados(
                origen,
                destino
            )) {

                cout
                << "SI estan conectados"
                << endl;

            }else{
                cout
                << "NO estan conectados"
                << endl;
            } // Fin if

            break;
        } // Fin mostrar conexiones

        // Mostrar las conexiones
        case 9: {
            int id;

            cout
            << "ID estudiante: ";
            cin >> id;
            red.mostrarConexiones(id);

            break;
        } // Fin mostrar conexiones

        // BFS
        case 10: {
            int inicio;

            cout << "ID inicial: ";
            cin >> inicio;

            red.bfs(inicio);

            break;
        } // Fin BFS

        // DFS
        case 11: {
            int inicio;

            cout
            << "ID inicial: ";
            cin >> inicio;
            red.dfs(inicio);

            break;
        } // Fin DFS

        // AVL
        case 12: {
        	arbol.mostrarEstadisticas();
            arbol.mostrarRanking();

            break;
        }

        // Estadisticas
        case 13: {
            tabla.mostrarEstadisticas();

            arbol.mostrarEstadisticas();

            break;
        } // Fin estadisticas

        // Benchmark
        case 14: {
            benchmark.ejecutarBenchmark();

            break;
        } // Fin Benchmark

        // Salir
        case 15: {

            cout
            << "Saliendo/Cerrando..."
            << endl;

            break;
        } // Fin cerrar

        default:
            cout
            << "Opcion invalida. Intente nuevamente"
            << endl;
        }

    } while(opcion != 15);

    return 0;
} // Fin main
