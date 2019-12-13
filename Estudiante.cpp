#include "Estudiante.h"

Estudiante::Estudiante(){
    carnet = "B00000";
    nombre = "Name";
    cantidadCreditos = 0;
    edad = 0;
    beca = 0;
}

Estudiante::Estudiante(string carnet, string nombre, int edad, int beca){
    setCarnet(carnet);
    setNombre(nombre);
    setEdad(edad);
    setBeca(beca);  
}

ostream& operator<<(ostream& os,Estudiante& estudiante){
    return os << "Nombre: " << estudiante.getNombre() << ", " << "Carnet: " << estudiante.getCarnet() << ", " << "edad: " << estudiante.getEdad()<< ". ";
}

Estudiante::~Estudiante(){

}

double Estudiante::pagoMatricula(){
    return 0;
}
        
void Estudiante::setCostoCredito(double costoCredito){
    this->costoCredito = costoCredito;
}

double Estudiante::getCostoCredito(){
    return costoCredito;
}
        
void Estudiante::setCarnet(string carnet){
    this->carnet = carnet;
}
        
string Estudiante::getCarnet(){
    return carnet;
}
        
void Estudiante::setNombre(string nombre){
    this->nombre = nombre;
}
        
string Estudiante::getNombre(){
    return nombre;
}
        
void Estudiante::setCantidadCreditos(int cantidadCreditos){
    this->cantidadCreditos = cantidadCreditos;
}
        
int Estudiante::getCantidadCreditos(){
    return cantidadCreditos;
}
        
void Estudiante::setBeca(int beca){
    this->beca = beca;
}
        
int Estudiante::getBeca(){
    return beca;
}

void Estudiante::setEdad(int edad){
    this->edad = edad;
}
        
int Estudiante::getEdad(){
    return edad;
}
