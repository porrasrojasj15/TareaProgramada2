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

string Grupo::getCiclo() {
  return ciclo;
}

void Grupo::setCiclo(string valor) {
  ciclo = valor;
}

int Grupo::getAnio() {
  return anio;
}

void Grupo::setAnio(int valor) {
   anio = valor;
}

ostream& operator<<(ostream& os, Grupo& grupo){
    return os << "Siglas: " << grupo.getSigla() << " ";
}
