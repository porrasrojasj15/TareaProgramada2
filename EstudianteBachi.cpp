#include "EstudianteBachi.h"


    EstudianteBachi::EstudianteBachi():Estudiante(){
        
    }
        
    EstudianteBachi::EstudianteBachi(string carnet, string nombre, int edad, int beca):Estudiante(carnet, nombre, edad, beca){
        
    }
    
    double EstudianteBachi::pagoMatricula(){
        double pago = cantidadCreditos * costoCredito;
        if(getBeca() == 1){
            pago *= 0.80;
        }else if(getBeca() == 2){
            pago *= 0.60;
        }else if(getBeca() == 3){
            pago *= 0.40;
        }else if(getBeca() == 4){
            pago *= 0.20;
        }else if(getBeca() == 5){
            pago = 0;
        }
        return pago;
    }
