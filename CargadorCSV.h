#ifndef CARGADORCSV_H
#define CARGADORCSV_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstdio>

#include "TablaHash.h"
#include "AVL.h"
#include "ListaProyectos.h"

using namespace std;

// Función para cargar el archivo CSV utilizando la librería estándar <cstdio>
void cargarCSV(const char* nombre_archivo, TablaHash &th, ArbolAVL &arbol) {
	
    FILE* archivo = fopen(nombre_archivo, "r");
    cout << "Leyendo el archivo..." << endl;
    
    if (archivo == NULL) {
        cout << ">> Error: No se pudo abrir el archivo '" << nombre_archivo << "'.\n";
        return;
    }//Fin if
    

    char linea[256];
    // Descartar la primera línea correspondiente a los encabezados
    if (fgets(linea, sizeof(linea), archivo) == NULL) {
        fclose(archivo);
        return;
    }// Fin if
    
    cout << "Cargando los encabezados..." << endl;

    int exitosos = 0;
    int omitidos = 0;

    // Leer línea por línea
    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        int id_est, sem, punt;
        double prom;
        char nom[100], carr[100];

        // Función sscanf:  extrae los datos usando patrones por comas
        int campos_leidos = sscanf(linea, "%d,%[^,],%[^,],%d,%lf,%d", 
                                   &id_est, nom, carr, &sem, &prom, &punt);

        // Si se lograron leer correctamente los 6 campos requeridos de la fila
        if (campos_leidos == 6) {
            Estudiante e;
            
            e.idEstudiante = id_est;
            e.nombreCompleto = nom;
            e.carrera = carr;
            e.semestre = sem;
            e.promedio = prom;
            e.puntaje = punt;
            
            e.listaProyectos = NULL;
            e.siguienteHash = NULL;

            if (th.insertar(e)) {
            	arbol.insertar(e);
            	
                exitosos++;
            } else {
                omitidos++;
            }// Finif
        }//Fin if
    }//Fin while
    fclose(archivo);
    cout << "Carga finalizada. Registros exitosos: " << exitosos
		 << "\nOmitidos por duplicado: " << omitidos << "\n";
}
	
#endif

