#ifndef ESTUDIANTEMAESTRIA_H
#define ESTUDIANTEMAESTRIA_H

#include "Estudiante.h"

class EstudianteMaestria : public Estudiante{
    private:
        
    public:        
        EstudianteMaestria();
        EstudianteMaestria(string carnet, string nombre, int edad, int beca);
        double pagoMatricula(); 
};

#endif
