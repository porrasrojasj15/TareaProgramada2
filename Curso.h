#ifndef CURSO_H
#define CURSO_H

#include <string>
#include <iostream>

using namespace std;

class Curso {
    public:
        Curso();
        Curso(string pSigla, string pNombre, int pCreditos);
        virtual ~Curso();
        Curso(const Curso& otro);

        string getSigla();

        void setSigla(string valor);

        string getNombre();

        void setNombre(string valor);

        int getCreditos();

        void setCreditos(int valor);
        
        friend ostream& operator<<(ostream& os, Curso& curso);

    protected:
    private:
        string sigla;
        string nombre;
        int creditos;
};

#endif
