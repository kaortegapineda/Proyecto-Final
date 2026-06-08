
package main;

public class Estudiante {
    private int idEstudiante;
    private String nombreCompleto;
    private String carrera;
    private int semestre;
    private double promedio;
    private int puntajeHabilidad;

    // Constructor
    public Estudiante(int idEstudiante, String nombreCompleto, String carrera, int semestre, double promedio, int puntajeHabilidad) {
        this.idEstudiante = idEstudiante;
        this.nombreCompleto = nombreCompleto;
        this.carrera = carrera;
        this.semestre = semestre;
        this.promedio = promedio;
        this.puntajeHabilidad = puntajeHabilidad;
    }

    // Métodos Get
    public int getIdEstudiante() { return idEstudiante; }
    public String getNombreCompleto() { return nombreCompleto; }
    public String getCarrera() { return carrera; }
    public int getSemestre() { return semestre; }
    public double getPromedio() { return promedio; }
    public int getPuntajeHabilidad() { return puntajeHabilidad; }

    @Override
    public String toString() {
        return "ID: " + idEstudiante + 
               " | Nombre: " + nombreCompleto + 
               " | Carrera: " + carrera + 
               " | Semestre: " + semestre + 
               " | Promedio: " + String.format("%.2f", promedio) + 
               " | Habilidad: " + puntajeHabilidad;
    }
}

