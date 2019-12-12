#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante{
    protected:
        string carnet;
        string nombre;
        int cantidadCreditos;
        int beca;
        int edad;
        double costoCredito;
    public:
        Estudiante();
        ~Estudiante();
        Estudiante(string carnet, string nombre, int edad, int beca);
        virtual double pagoMatricula();
        void setCostoCredito(double costoCredito);
        double getCostoCredito();
        void setCarnet(string carnet);
        string getCarnet();
        void setNombre(string nombre);
        string getNombre();
        void setCantidadCreditos(int cantidadCreditos);
        int getCantidadCreditos();
        void setBeca(int beca);
        int getBeca();
        void setEdad(int edad);
        int getEdad();
        friend ostream& operator<<(ostream& os, Estudiante& estudiante);
};

#endif
