#include "Estudiante.h"
#include "EstudianteBachi.h"
#include "EstudianteMaestria.h"
#include "EstudianteDoctorado.h"
#include "Grupo.h"
#include "Curso.h"
#include <deque>
#include <list>
#include <map>

using namespace std;

int main(){
  //aquí va la lectura


  deque<Curso> cursos;
  map< Grupo, list<Estudiante> > grupos;


  int opcion;
  cout << "1-Listar estudiantes." << endl;
  cout << "2-Imprimir información de los cursos." << endl;
  cout << "3-Calcular el cobro de matrícula de todos los estudiantes para un ciclo y año." << endl;
  cout << "4-Mostrar los cursos que ha llevado un estudiante en un ciclo y año." << endl;
  cout << "5-Calcular el cobro de matrícula de un estudiante para un ciclo y año." << endl;
  cout << "6-Eliminar un grupo." << endl;
  cout << "7-Eliminar un curso." << endl;
  cout << "8-Eliminar a un estudiante de un grupo." << endl;
  cout << "9-Añadir un estudiante a un grupo." << endl;
  cout << "10-Agregar un curso." << endl;
  cout << "11-Agregar un grupo." << endl;
  cout << "12-Salir." << endl;
  while (opcion != 12){
      cout << "¿Qué acción desea realizar (1-12)? ";
      cin >> opcion;
      cout << endl;
      while(opcion < 1 || opcion > 12){
          cout << "Por favor ingrese una opción válida (1-12): ";
          cin >> opcion;
          cout << endl;
      }
      switch (opcion){
          case 1:
            if(grupos.empty()){
              cout << "No existen grupos." << endl;
            }
            else{
              map<Grupo, list<Estudiante> >::iterator itGrupos; //crea iterador

              for (itGrupos = grupos.begin(); itGrupos != grupos.end(); itGrupos++){
                Grupo grupito = itGrupos->first; //se le nombra al valor del mapa como listaEstduiantes                
                cout << grupito << endl; //Imprime los datos del cursos

                list<Estudiante> listaEstudiantes = itGrupos->second; //se le nombra al valor del mapa como listaEstduiantes

                list<Estudiante>::iterator itEstudiantes;//crea iterador

                cout << "Estudiantes:" << endl;
                for (itEstudiantes = listaEstudiantes.begin(); itEstudiantes != listaEstudiantes.end(); itEstudiantes++){
                  cout << *itEstudiantes; //Imprime los datos de los estudiantes
                }
              }
            }
            break;
          case 2:
            if(cursos.empty()){
              cout << "No existen cursos." << endl;
            }
            else{
              deque<Curso>::iterator itCursos;//crea iterador
              for (itCursos = cursos.begin(); itCursos != cursos.end(); itCursos++){
                cout << *itCursos; //Imprime los datos de los estudiantes
              }
            }
            break;
          case 3:
            break;
          case 4:
            break;
          case 5:
            break;
          case 6:
            break;
          case 7:
            break;
          case 8:
            break;
          case 9:
            break;
          case 10:
            break;
          case 11:
            break;
      }
  }
  cout << "El programa se cerrará." << endl;

    return 0;
}
