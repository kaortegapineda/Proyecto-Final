package main;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    
    private static HashMap<Integer,Estudiante> mapaEstudiantes = new HashMap<>();
    
    public static void main(String[] args) {
        Scanner teclado = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("--SISTEMA HASH en Java--");
            System.out.println("1. Cargar estudiantes desde CSV");
            System.out.println("2. Buscar estudiante por ID");
            System.out.println("3. Eliminar estudiante por ID");
            System.out.println("4. Mostrar evidencias y métricas del HashMap");
            System.out.println("5. Salir/Cerrar");
            System.out.print("Seleccione una opcion: ");
            opcion = teclado.nextInt();

            switch (opcion) {
                case 1:
                    cargarCSV("C:\\Users\\kevin\\OneDrive\\Documentos\\MEGA\\Universidad\\Semestre 5\\Programacion 3\\Proyecto Final\\estudiantes.csv\"");
                    break;
                case 2:
                    System.out.print("Ingrese el ID del estudiante a buscar: ");
                    int idBuscar = teclado.nextInt();
                    Estudiante encontrado = mapaEstudiantes.get(idBuscar);
                    if (encontrado != null) {
                        System.out.println("\n--Estudiante Encontrado--");
               
                        System.out.println(encontrado);
                    } else {
                        System.out.println("El estudiante con ID " + idBuscar + " no existe.");
                    }
                    break;
                case 3:
                    System.out.print("Ingrese el ID del estudiante a eliminar: ");
                    int idEliminar = teclado.nextInt();
                    if (mapaEstudiantes.remove(idEliminar) != null) {
                        System.out.println("Estudiante con ID " + idEliminar + " eliminado correctamente.");
                    } else {
                        System.out.println("Error: No se encontro ningun estudiante con el ID " + idEliminar + ".");
                    }
                    break;
                case 4:
                    mostrarEvidencias();
                    break;
                case 5:
                    System.out.println("Saliendo del sistema...");
                    break;
                default:
                    System.out.println("Opcion no valida.");
            }
        } while (opcion != 5);

        teclado.close();
    }

    public static void cargarCSV(String nombreArchivo) {

    int exitosos = 0;
    int omitidos = 0;
    
    System.out.println("Intentando abrir: " + nombreArchivo);

    try (BufferedReader br = new BufferedReader(new FileReader(nombreArchivo))) {

        String linea;

        // Saltar encabezado
        br.readLine();

        while ((linea = br.readLine()) != null) {

    System.out.println("Línea leída: " + linea);

    if (linea.trim().isEmpty()) {
        continue;
    }

    String[] campos = linea.split(";");

    System.out.println("Cantidad de campos: " + campos.length);

    if (campos.length == 6) {

        int id = Integer.parseInt(campos[0].trim());
        String nombre = campos[1].trim();
        String carrera = campos[2].trim();
        int semestre = Integer.parseInt(campos[3].trim());
        double promedio = Double.parseDouble(campos[4].trim());
        int habilidad = Integer.parseInt(campos[5].trim());

        Estudiante est = new Estudiante(
            id,
            nombre,
            carrera,
            semestre,
            promedio,
            habilidad
        );

        mapaEstudiantes.put(id, est);

        exitosos++;
    }
}
        System.out.println(
            ">> Carga finalizada. Registros exitosos: "
            + exitosos +
            " | Omitidos: " + omitidos
        );

    } catch (IOException e) {

        System.out.println(">> Error al leer el archivo");
        System.out.println(e.getMessage());

    } catch (NumberFormatException e) {

        System.out.println(">> Error de formato numérico en CSV");

    }
}

    // Módulo exclusivo para demostrar la presencia operativa del HashMap nativo
    public static void mostrarEvidencias() {
        System.out.println("\n--- EVIDENCIA DE USO DE HASHMAP NATIVO ---");
        System.out.println("Clase del objeto utilizado : " + mapaEstudiantes.getClass().getName());
        System.out.println("Total de estudiantes cargados (.size()): " + mapaEstudiantes.size());
        System.out.println("¿La estructura está vacía? (.isEmpty()): " + mapaEstudiantes.isEmpty());
        
        System.out.println("\n--- VOLCADO DE CLAVES ACTIVAS (student_id) ---");
        System.out.println("Set de claves (.keySet()): " + mapaEstudiantes.keySet());

        System.out.println("\n--- CONTENIDO COMPLETO ASOCIADO ---");
        for (Map.Entry<Integer, Estudiante> entrada : mapaEstudiantes.entrySet()) {
            System.out.println("Key [ID: " + entrada.getKey() + "] -> Value: [" + entrada.getValue().getNombreCompleto() + "]");
        }
    }
    
}
