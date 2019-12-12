#include "EstudianteDoctorado.h"

    EstudianteDoctorado::EstudianteDoctorado():Estudiante(){
       setCostoCredito(37500);
    }

    EstudianteDoctorado::EstudianteDoctorado(string carnet, string nombre, int edad, int beca):Estudiante(carnet, nombre, edad, beca){
        setCostoCredito(37500);
    }
    
    double EstudianteDoctorado::pagoMatricula(){
        double pago = getCantidadCreditos() * getCostoCredito();
        return pago;
    }
