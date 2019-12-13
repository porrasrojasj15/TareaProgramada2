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

/**
@brief Sobreescribe el operador de salida para esta clase
@param os Una referencia a un stream de salida
@param estudiante Una referencia al objeto sobre el que se opera
@returns Una referencia al stream de salida
*/
ostream& operator<<(ostream& os,Estudiante& estudiante){
    return os << "Nombre: " << estudiante.getNombre() << ", " << "Carnet: " << estudiante.getCarnet() << ", " << "edad: " << estudiante.getEdad()<< ". ";
}

Estudiante::~Estudiante(){

}
/**
@brief No tiene implementación puesto que no existen objetos de tipo Estudiante puro
@returns Un cero
*/
double Estudiante::pagoMatricula(){
    return 0;
}
/**
@brief Establece el costo de créditos para el estudiante
@param costoCredito El valor a pasar para modificarlo
*/
void Estudiante::setCostoCredito(double costoCredito){
    this->costoCredito = costoCredito;
}

/**
@brief Retorna el costo de créditos para el estudiante
@returns El costo de créditos para el estudiante
*/
double Estudiante::getCostoCredito(){
    return costoCredito;
}

/**
@brief Establece el carnet del estudiante
@param carnet El valor a pasar para modificarlo
*/
void Estudiante::setCarnet(string carnet){
    this->carnet = carnet;
}

/**
@brief Retorna el carnet del estudiante
@returns El carnet del estudiante
*/
string Estudiante::getCarnet(){
    return carnet;
}

/**
@brief Establece el nombre del estudiante
@param nombre El valor a pasar para modificarlo
*/
void Estudiante::setNombre(string nombre){
    this->nombre = nombre;
}

/**
@brief Retorna el nombre del estudiante
@returns El nombre del estudiante
*/
string Estudiante::getNombre(){
    return nombre;
}
/**
@brief Establece la cantidad de créditos que cursa el estudiante
@param cantidadCreditos El valor a pasar para modificarlo
*/
void Estudiante::setCantidadCreditos(int cantidadCreditos){
    this->cantidadCreditos = cantidadCreditos;
}

/**
@brief Retorna la cantidad de créditos que cursa el estudiante
@returns La cantidad de créditos cursados
*/
int Estudiante::getCantidadCreditos(){
    return cantidadCreditos;
}

/**
@brief Establece la beca del estudiante
@param beca El valor a pasar para modificarlo
*/
void Estudiante::setBeca(int beca){
    this->beca = beca;
}

/**
@brief Retorna el tipo de beca del estudiante
@returns El tipo de beca del estudiante
*/
int Estudiante::getBeca(){
    return beca;
}

/**
@brief Establece la edad del estudiante
@param edad El valor a pasar para modificarlo
*/
void Estudiante::setEdad(int edad){
    this->edad = edad;
}

/**
@brief Retorna la edad del estudiante
@returns La edad del estudiante
*/
int Estudiante::getEdad(){
    return edad;
}
