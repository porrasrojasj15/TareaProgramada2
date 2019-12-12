#ifndef ESTUDIANTEDOCTORADO_H
#define ESTUDIANTEDOCTORADO_H

#include "Estudiante.h"

class EstudianteDoctorado : public Estudiante{
    private:
        
    public:        
        EstudianteDoctorado();
        EstudianteDoctorado(string carnet, string nombre, int edad, int beca);
        double pagoMatricula(); 
};

#endif
