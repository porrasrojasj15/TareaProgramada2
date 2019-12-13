
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
  deque<Curso> cursos;
  map< string, list<Estudiante*> > grupos;


  ifstream archivo;

    string ignorar;
    string sigla;
    string nombre;
    int creditos;

    archivo.open("cursos.txt", ios::in);
    if(archivo.fail()){
      cout << "No se puede abrir el archivo" << endl;
      return -1;
    }
    getline(archivo, ignorar);
    while(!archivo.eof()){
      getline(archivo, sigla, ';');
      getline(archivo, nombre, ';');
      archivo >> creditos;
      archivo.ignore();
      Curso nuevoCurso;
      nuevoCurso.setSigla(sigla);
      nuevoCurso.setNombre(nombre);
      nuevoCurso.setCreditos(creditos);
      cursos.push_back(nuevoCurso);
    }

    archivo.close();

  Curso curso0("MA0291", "Mate", 5);
  cursos.push_back(curso0);
  EstudianteBachi estudiante0("B12345","Pedro", 18, 1);
  EstudianteBachi estudiante1("B54321","Juan", 19, 2);
  list<Estudiante> listaEs;
  listaEs.push_back(estudiante0);
  listaEs.push_back(estudiante1);
  Grupo grupo0("MA0291", "Mate", 5, "I", 2019);
  string siglas0 = grupo0.getSigla();
  grupos.insert( {siglas0, listaEs } );

  long long opcion;
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
      cout << "\n¿Qué acción desea realizar (1-12)? ";
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
              cout << "Lista de grupos: " << endl;
              map<string, list<Estudiante> >::iterator itGrupos; //crea iterador

              for (itGrupos = grupos.begin(); itGrupos != grupos.end(); itGrupos++){
                cout << "Grupo " << itGrupos->first << ":" << endl; //Imprime los datos de los cursos

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
              cout << "Lista de cursos: " << endl;
              deque<Curso>::iterator itCursos;
              for (itCursos = cursos.begin(); itCursos != cursos.end(); itCursos++){
                cout << *itCursos << endl;
              }
            }
            break;

          case 3:

            break;

          case 4:

            break;

          case 5:

            break;

          case 6:{
            cout << "Por favor ingrese las siglas del curso a borrar:" << endl;
            string siglasInput;
            cin >> siglasInput;

            if( grupos.find(siglasInput)->second.empty() ){ //si la lista de estudiantes asociada a ese grupo está vacía
              grupos.erase(siglasInput);

              list<Grupo>::iterator itGrupos;

              for (itGrupos = listaGrupos.begin(); itGrupos != listaGrupos.end(); itGrupos++){
                if( siglasInput.compare( itGrupos->getSigla() ) == 0 ){
                  listaGrupos.erase(itGrupos);
                  cout << "Se ha borrado el grupo para " << siglasInput << " correctamente." <<endl;
                }
              }
            }

            else{
              cout << "El grupo tiene estudiantes, el borrado ha fallado." << endl;
            }

            }

            break;

          case 7:{
            cout << "Por favor ingrese las siglas del curso a borrar:" << endl;
            string siglasInput;
            cin >> siglasInput;

            deque<Curso>::iterator itCursos;

            for (itCursos = cursos.begin(); itCursos != cursos.end(); itCursos++){
              if( siglasInput.compare( itCursos->getSigla() ) == 0 ){
                if(grupos.find(siglasInput) != grupos.end()){ //si encontró un grupo con esas siglas
                  cout << "Existe un grupo para este curso, el borrado ha fallado." << endl;
                }
                else{
                  cursos.erase(itCursos);
                  cout << "Se ha borrado el curso " << siglasInput << " correctamente." << endl;
                  break;
                }
              }
            }


            }

            break;
          case 8:

            break;
          case 9:

            break;
          case 10:{
            cout << "Por favor ingrese las siglas del curso:" << endl;
            string siglasInput;
            cin >> siglasInput;
            cout << "Por favor ingrese el nombre del curso:" << endl;
            string nombreInput;
            cin >> nombreInput;
            cout << "Por favor ingrese la cantidad de créditos del curso:" << endl;
            int creditosInput;
            cin >> creditosInput;
            Curso cursoInput(siglasInput, nombreInput, creditosInput);
            cursos.push_back(cursoInput);
            cout << "El curso ha sido añadido exitosamente." << endl;
            }
            break;

          case 11:{
            cout << "Por favor ingrese las siglas del curso:" << endl;
            string siglasInput;
            cin >> siglasInput;
            cout << "Por favor ingrese el nombre del curso:" << endl;
            string nombreInput;
            cin >> nombreInput;
            cout << "Por favor ingrese la cantidad de créditos del curso:" << endl;
            int creditosInput;
            cin >> creditosInput;
            cout << "Por favor ingrese el semestre del curso (I ó II):" << endl;
            string cicloInput;
            cin >> cicloInput;
            cout << "Por favor ingrese el año del curso:" << endl;
            int anioInput;
            cin >> anioInput;
            Grupo grupoInput(siglasInput, nombreInput, creditosInput, cicloInput, anioInput);
            list<Estudiante> listaInput;
            grupos.insert( {siglasInput,listaInput} );
            listaGrupos.push_back(grupoInput);
            cout << "El grupo ha sido añadido exitosamente." << endl;
            }
            break;
      }
  }
  cout << "El programa ha cerrado." << endl;
  return 0;
}
