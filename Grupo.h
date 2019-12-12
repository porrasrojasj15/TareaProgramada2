#ifndef GRUPO_H
#define GRUPO_H

#include "Curso.h"
#include <string>
#include <list>
#include "Estudiante.h"

class Grupo : public Curso {
    public:
        Grupo();
        Grupo(string pSigla, string pNombre, int pCreditos, string pCiclo, int pAnio);
        virtual ~Grupo();
        Grupo(const Grupo& otro);

        string getCiclo();

        void setCiclo(string valor);

        int getAnio();

        void setAnio(int valor);

        friend ostream& operator<<(ostream& os, Grupo& grupo);

    protected:
    private:
        string ciclo;
        int anio;
};

#endif
