#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <iostream>
#include <string>
using namespace std;

class Estudiante{
    private:
        string carnet;
        string nombre;
        int cantidadCreditos;
        int beca;
        int edad;
        double costoCredito;
    public:
        Estudiante();
        virtual ~Estudiante();
        Estudiante(string carnet, string nombre, int edad, int beca);
        virtual double pagoMatricula();
        virtual void setCostoCredito(double costoCredito);
        virtual double getCostoCredito();
        virtual void setCarnet(string carnet);
        virtual string getCarnet();
        virtual void setNombre(string nombre);
        virtual string getNombre();
        virtual void setCantidadCreditos(int cantidadCreditos);
        virtual int getCantidadCreditos();
        virtual void setBeca(int beca);
        virtual int getBeca();
        virtual void setEdad(int edad);
        virtual int getEdad();
};

#endif
