#include "EstudianteMaestria.h"

    EstudianteMaestria::EstudianteMaestria():Estudiante(){
        setCostoCredito(25000);
    }

    EstudianteMaestria::EstudianteMaestria(string carnet, string nombre, int edad, int beca):Estudiante(carnet, nombre, edad, beca){
        setCostoCredito(25000);
    }
    /**
    @brief Establece el pago de la matricula de acorde a los créditos que lleva el estudiante, el costo de créditos y el tipo de beca
    @returns El precio que tiene que pagar el estudiante por sus créditos
    */
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
