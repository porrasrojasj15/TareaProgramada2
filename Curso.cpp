#include "Curso.h"
#include <string>
using namespace std;

Curso::Curso(){
}

Curso::Curso(string pSigla, string pNombre, int pCreditos){
  sigla = pSigla;
  nombre = pNombre;
  creditos = pCreditos;
}

Curso::~Curso(){
}

Curso::Curso(const Curso& otro){
  sigla = otro.sigla;
  nombre = otro.nombre;
  creditos = otro.creditos;
}

/**
@brief Retorna las siglas del curso
@returns Las siglas correspondientes al curso
*/
string Curso::getSigla() {
   return sigla;
}

/**
@brief Establece las siglas del curso
@param valor El valor a pasar para modificarlo
*/
void Curso::setSigla(string valor) {
   sigla = valor;
}

/**
@brief Retorna el nombre del curso
@returns Las siglas correspondientes al curso
*/
string Curso::getNombre() {
   return nombre;
}

/**
@brief Establece el nombre del curso
@param valor El valor a pasar para modificarlo
*/
void Curso::setNombre(string valor) {
   nombre = valor;
}

/**
@brief Retorna el costo de créditos del curso
@returns Los créditos que cuesta el curso
*/
int Curso::getCreditos() {
   return creditos;
}

/**
@brief Establece el costo de créditos del curso
@param valor El valor a pasar para modificarlo
*/
void Curso::setCreditos(int valor) {
   creditos = valor;
}

/**
@brief Sobreescribe el operador de salida para esta clase
@param os Una referencia a un stream de salida
@param estudiante Una referencia al objeto sobre el que se opera
@returns Una referencia al stream de salida
*/
ostream& operator<<(ostream& os,Curso& curso){
    return os << "Siglas: " << curso.getSigla() << ", " << "Nombre: " << curso.getNombre() << ", " << "Creditos: " << curso.getCreditos() << ". " << endl;
}
