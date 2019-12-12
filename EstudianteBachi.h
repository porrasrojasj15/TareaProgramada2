#ifndef ESTUDIANTEBACHI_H
#define ESTUDIANTEBACHI_H

#include "Estudiante.h"

class EstudianteBachi : public Estudiante{
    private:
        
    public:        
        EstudianteBachi();
        EstudianteBachi(string carnet, string nombre, int edad, int beca);
        double pagoMatricula(); 
};

#endif
