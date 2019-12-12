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
string Curso::getSigla() {
   return sigla;
}

void Curso::setSigla(string valor) {
   sigla = valor;
}

string Curso::getNombre() {
   return nombre;
}

void Curso::setNombre(string valor) {
   nombre = valor;
}

int Curso::getCreditos() {
   return creditos;
}

void Curso::setCreditos(int valor) {
   creditos = valor;
}

ostream& operator<<(ostream& os,Curso& curso){
    return os << "Siglas: " << curso.getSigla() << ". ";
}
