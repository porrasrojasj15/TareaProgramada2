#include "Grupo.h"
#include <string.h>
#include <list>
#include "Estudiante.h"
using namespace std;

Grupo::Grupo():Curso(){
}

Grupo::Grupo(string pSigla, string pNombre, int pCreditos, string pCiclo, int pAnio):Curso(pSigla, pNombre, pCreditos){
  ciclo = pCiclo;
  anio = pAnio;
}

Grupo::~Grupo(){
}

Grupo::Grupo(const Grupo& otro){
  ciclo = otro.ciclo;
  anio = otro.anio;
}

/**
@brief Retorna el ciclo actual del curso
@returns El ciclo del curso
*/
string Grupo::getCiclo() {
  return ciclo;
}

/**
@brief Establece el ciclo actual del curso
@param valor El valor a pasar para modificarlo
*/
void Grupo::setCiclo(string valor) {
  ciclo = valor;
}

/**
@brief Retorna el año del curso
@returns El año del curso
*/
int Grupo::getAnio() {
  return anio;
}

/**
@brief Establece el año del curso
@param valor El valor a pasar para modificarlo
*/
void Grupo::setAnio(int valor) {
   anio = valor;
}

/**
@brief Sobreescribe el operador de salida para esta clase
@param os Una referencia a un stream de salida
@param estudiante Una referencia al objeto sobre el que se opera
@returns Una referencia al stream de salida
*/
ostream& operator<<(ostream& os, Grupo& grupo){
    return os << "Siglas: " << grupo.getSigla() << " ";
}
