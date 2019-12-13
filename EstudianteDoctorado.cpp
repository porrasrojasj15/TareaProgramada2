#include "EstudianteDoctorado.h"

    EstudianteDoctorado::EstudianteDoctorado():Estudiante(){
       setCostoCredito(37500);
    }

    EstudianteDoctorado::EstudianteDoctorado(string carnet, string nombre, int edad, int beca):Estudiante(carnet, nombre, edad, beca){
        setCostoCredito(37500);
    }
    /**
    @brief Establece el pago de la matricula de acorde a los créditos que lleva el estudiante, el costo de créditos y el tipo de beca
    @returns El precio que tiene que pagar el estudiante por sus créditos
    */
    double EstudianteDoctorado::pagoMatricula(){
        double pago = getCantidadCreditos() * getCostoCredito();
        return pago;
    }
