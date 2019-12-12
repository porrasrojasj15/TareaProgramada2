#include "EstudianteMaestria.h"

    EstudianteMaestria::EstudianteMaestria():Estudiante(){
        setCostoCredito(25000);
    }

    EstudianteMaestria::EstudianteMaestria(string carnet, string nombre, int edad, int beca):Estudiante(carnet, nombre, edad, beca){
        setCostoCredito(25000);
    }
    
    double EstudianteMaestria::pagoMatricula(){
        double pago = getCantidadCreditos() * getCostoCredito();
        if(getBeca() == 1){
            pago *= 0.90;
        }else if(getBeca() == 2){
            pago *= 0.80;
        }else if(getBeca() == 3){
            pago *= 0.70;
        }else if(getBeca() == 4){
            pago *= 0.60;
        }else if(getBeca() == 5){
            pago *= 0.50;
        }
        return pago;
    } 
