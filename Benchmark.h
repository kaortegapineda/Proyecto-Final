#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <fstream>
#include <ctime>

#include "TablaHash.h"
#include "AVL.h"
#include "Grafo.h"

using namespace std;

class Benchmark {
public:
    void ejecutarBenchmark() {
        ofstream archivo("cpp_results.csv");
        if(!archivo.is_open()) {
            cout << "Error al crear cpp_results.csv"
                 << endl;
            return;
        } // Fin if

        archivo
        << "language,operation,structure,records,time_ms"
        << endl;

        const int REGISTROS = 10000;

        // Función para insertar la tabla Hash
        TablaHash hashInsert(1000);

        clock_t inicioHashInsert =
        clock();

        for(int i = 1; i <= REGISTROS; i++) {
            Estudiante e;

            e.idEstudiante = i;
            e.nombreCompleto = "Alumno";
            e.carrera = "Ingenieria";
            e.semestre = 1;
            e.promedio = 80;
            e.puntaje = i;
            hashInsert.insertar(e);
        } // Fin for

        clock_t finHashInsert =
        clock();

        double tiempoHashInsert =
        (double)
        (finHashInsert - inicioHashInsert)
        * 1000
        / CLOCKS_PER_SEC;

        // Función para buscar en tabla hash
        clock_t inicioHashSearch =
        clock();

        for(int i = 1;
            i <= REGISTROS;
            i++) {

            hashInsert.buscar(i);
        } // Fin if

        clock_t finHashSearch =
        clock();

        double tiempoHashSearch =
        (double)
        (finHashSearch - inicioHashSearch)
        * 1000
        / CLOCKS_PER_SEC;

        // Función para insertar un AVL
        ArbolAVL avl;

        clock_t inicioAVLInsert =
        clock();

        for(int i = 1; i <= REGISTROS; i++) {

            Estudiante e;

            e.idEstudiante = i;
            e.nombreCompleto = "Alumno";
            e.carrera = "Ingenieria";
            e.semestre = 1;
            e.promedio = 80;
            e.puntaje = i;

            avl.insertar(e);
        } // Fin for

        clock_t finAVLInsert =
        clock();

        double tiempoAVLInsert =
        (double)
        (finAVLInsert - inicioAVLInsert)
        * 1000
        / CLOCKS_PER_SEC;

        // Función de recorrido
        clock_t inicioAVLRecorrido =
        clock();

        avl.mostrarInOrden();

        clock_t finAVLRecorrido =
        clock();

        double tiempoAVLRecorrido =
        (double)
        (finAVLRecorrido - inicioAVLRecorrido)
        * 1000
        / CLOCKS_PER_SEC;

        // Función Grafo
        Grafo red;

        for(int i = 1; i < REGISTROS; i++) {

            red.conectar(i, i + 1);
        } // Fin for

        // Función BFS
        clock_t inicioBFS =
        clock();

        red.bfs(1);

        clock_t finBFS =
        clock();

        double tiempoBFS =
        (double)
        (finBFS - inicioBFS)
        * 1000
        / CLOCKS_PER_SEC;

        // Función DFS
        clock_t inicioDFS =
        clock();

        red.dfs(1);

        clock_t finDFS =
        clock();

        double tiempoDFS =
        (double)
        (finDFS - inicioDFS)
        * 1000
        / CLOCKS_PER_SEC;

        // Función para el archivo CSV
        archivo
        << "C++,insert,HashTable,"
        << REGISTROS
        << ","
        << tiempoHashInsert
        << endl;

        archivo
        << "C++,search,HashTable,"
        << REGISTROS
        << ","
        << tiempoHashSearch
        << endl;

        archivo
        << "C++,insert,AVL,"
        << REGISTROS
        << ","
        << tiempoAVLInsert
        << endl;

        archivo
        << "C++,traversal,AVL,"
        << REGISTROS
        << ","
        << tiempoAVLRecorrido
        << endl;

        archivo
        << "C++,bfs,Graph,"
        << REGISTROS
        << ","
        << tiempoBFS
        << endl;

        archivo
        << "C++,dfs,Graph,"
        << REGISTROS
        << ","
        << tiempoDFS
        << endl;

        archivo.close();

        cout
        << "\nBenchmark completado."
        << endl;

        cout
        << "Archivo generado: cpp_results.csv"
        << endl;

    }

};

#endif
