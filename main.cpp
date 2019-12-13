#include "Estudiante.h"
#include "EstudianteBachi.h"
#include "EstudianteMaestria.h"
#include "EstudianteDoctorado.h"
#include "Grupo.h"
#include "Curso.h"
#include <deque>
#include <list>
#include <map>
#include <fstream>

using namespace std;

int main(){
//Estructuras de datos necesarias:

  deque<Curso> cursos;
  map< string, list<Estudiante> > grupos;
  list<Grupo> listaGrupos;

//____________________________________________________________________________

//Lectura de archivo:
  ifstream archivo;

  string ignorar; //línea inicial que debe ser ignorada
  string sigla;
  string nombre;
  string creditosString;

  archivo.open("cursos.txt", ios::in);
  if(archivo.fail()){
    cout << "No se puede abrir el archivo" << endl;
    return -1;
  }
  getline(archivo, ignorar);
  while(!archivo.eof()){
    getline(archivo, sigla, ';');
    getline(archivo, nombre, ';');
    getline(archivo, creditosString, '\n');
    int creditos;
    creditos = stoi(creditosString); //se hace casting al leer los créditos
    Curso nuevoCurso;
    nuevoCurso.setSigla(sigla);
    nuevoCurso.setNombre(nombre);
    nuevoCurso.setCreditos(creditos);
    cursos.push_back(nuevoCurso);
  }

  archivo.close();
//______________________________________________________________________________

//Pruebas "quemadas", para probar funcionalidades más rápidamente:
  Curso curso0("MA0291", "Mate", 5);
  cursos.push_back(curso0);
  EstudianteBachi estudiante0("B12345","Pedro", 18, 5);
  EstudianteBachi estudiante1("B54321","Juan", 19, 1);
  list<Estudiante> listaEs;
  listaEs.push_back(estudiante0);
  listaEs.push_back(estudiante1);
  Grupo grupo0("MA0291", "Mate", 5, "I", 2019);
  string siglas0 = grupo0.getSigla();
  grupos.insert( {siglas0, listaEs } );
//______________________________________________________________________________


//Menú:

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

  while (opcion != 12){ //si elige la opción 12, sale del programa
      cout << "\n¿Qué acción desea realizar (1-12)? ";
      cin >> opcion;
      cout << endl;
      while(opcion < 1 || opcion > 12){ //comprueba que el número sea una opción válida
          cout << "Por favor ingrese una opción válida (1-12): ";
          cin >> opcion;
          cout << endl;
      }

//Switch para opciones del 1 al 11:
      switch (opcion){

//Imprimir estudiantes. Imprime los grupos existentes en el programa con sus estudiantes correspondientes. Usa sobrecarga de operadores:
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
                  cout << *itEstudiantes << endl; //Imprime los datos de los estudiantes
                }
              }
            }
            break;

//Imprimir los cursos. Imprime las siglas de los cursos actualmente en el programa. Usa sobrecarga de operadores:
          case 2:
            if(cursos.empty()){
              cout << "No existen cursos." << endl;
            }
            else{
              cout << "Lista de cursos: " << endl;
              deque<Curso>::iterator itCursos;
              for (itCursos = cursos.begin(); itCursos != cursos.end(); itCursos++){
                cout << *itCursos;
              }
            }
            break;

          case 3:

            break;

/*Muestra los cursos en los que está inscrito un estudiante en un ciclo y año. Para todos los grupos en la lista de grupos que cumplan con el
mismo ciclo y año que los indicados por el usuario, busca en el mapa los cursos correspondientes, revisa su lista de estudiantes relacionada
y devuelve las siglas de aquellos cursos cuya lista de estudiantes tenga una coincidencia con el estudiante*/
          case 4:{
            cout << "Ingrese el carnet del estudiante: " << endl;
            string carnetInput;
            cin >> carnetInput;

            cout << "Por favor ingrese el semestre de los cursos (I ó II):" << endl;
            string cicloInput;
            cin >> cicloInput;

            cout << "Por favor ingrese el año de los cursos:" << endl;
            int anioInput;
            cin >> anioInput;

            list<Grupo>::iterator itGrupos;
            string siglasInput;

            for (itGrupos = listaGrupos.begin(); itGrupos != listaGrupos.end(); itGrupos++){
              if( cicloInput.compare( itGrupos->getCiclo() ) == 0 && anioInput == itGrupos->getAnio() ){
              //si el ciclo y año del grupo actual son los mismos que los ingresados por el usuario
                siglasInput = itGrupos->getSigla(); //siglasInput es la sigla del grupo actual

                if( !(grupos.find(siglasInput)->second.empty()) ){ //si la lista de estudiantes actual no está vacía
                  list<Estudiante>::iterator itEstudiantes;

                  for(itEstudiantes = grupos.find(siglasInput)->second.begin(); itEstudiantes != grupos.find(siglasInput)->second.end(); itEstudiantes++){
                    if( carnetInput.compare( itEstudiantes->getCarnet() ) == 0 ){ //si el carnet proporcionado por el usuario es igual al del estudiante actual
                      cout << "d" << endl;
                      break;
                    }
                  }
                }
              }
            }

            }
            break;

          case 5:

            break;

/*Borra un grupo del programa. Efectúa operaciones de borrado tanto para el mapa de grupos como para la lista auxiliar de grupos.
No efectúa esto si la lista de estudiantes de este grupo no está vacía. */
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

/*Borra un curso del deque de cursos. Efectúa una operación de borrado sobre el elemento que coincida con las siglas proporcionadas por el usuario.
No efectúa esto si el curso tiene grupos relacionados*/
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

/*Borra a un estudiante de la lista de estudiantes de un grupo. Determina el tipo de beca y el grado de carrera que cursa el estudiante antes
de añadirlo. No añade al estudiante si el grupo no existe.*/
          case 8:{
            cout << "Ingrese las siglas del grupo del que desee borrar al estudiante: " << endl;
            string siglasInput;
            cin >> siglasInput;

            cout << "Ingrese el carnet del estudiante: " << endl;
            string carnetInput;
            cin >> carnetInput;

            if(grupos.find(siglasInput) != grupos.end()){
              list<Estudiante>::iterator itEstudiantes;

              for (itEstudiantes = grupos.find(siglasInput)->second.begin(); itEstudiantes != grupos.find(siglasInput)->second.end(); itEstudiantes++){
              // ^ recorre la lista de estudiantes accediendo desde el mapa, con la llave que coincide
                if( carnetInput.compare( itEstudiantes->getCarnet() ) == 0 ){
                  grupos.find(siglasInput)->second.erase(itEstudiantes);
                  cout << "Se ha borrado el estudiante correctamente." << endl;
                  break;
                }
              }
            }

            else{
              cout << "No existe un grupo con esas siglas,la operación ha fallado." << endl;
            }

            }
            break;

          case 9:{

            cout << "Ingrese las siglas del grupo al que quiere añadir al estudiante: " << endl;
            string siglasInput;
            cin >> siglasInput;

            cout << "Ingrese el carnet del estudiante: " << endl;
            string carnetInput;
            cin >> carnetInput;

            cout << "Ingrese el nombre del estudiante: " << endl;
            string nombreInput;
            cin >> nombreInput;

            cout << "Ingrese la edad del estudiante: " << endl;
            int edadInput;
            cin >> edadInput;

            int becaInput = carnetInput.back() - '0'; /* Se le resta el caracter de '0' para conseguir el verdadero número.
            Daría el mismo resultado si se le resta 48*/
            if(becaInput > 5){
              becaInput = 5;
            }

            if(edadInput <= 20){
              EstudianteBachi estudianteInput(carnetInput,nombreInput,edadInput,becaInput);
              grupos.find(siglasInput)->second.push_back(estudianteInput); //busca el grupo con esas siglas y añade al estudiante a este
            }

            else if(edadInput <= 22){
              EstudianteMaestria estudianteInput(carnetInput,nombreInput,edadInput,becaInput);
              grupos.find(siglasInput)->second.push_back(estudianteInput);
            }

            else{
              EstudianteDoctorado estudianteInput(carnetInput,nombreInput,edadInput,becaInput);
              grupos.find(siglasInput)->second.push_back(estudianteInput);
            }

            cout << "El estudiante se añadió exitosamente." << endl;
            }
            break;

//Añade un curso a el deque de cursos del programa.
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

//Añade un grupo para el curso con las siglas proporcionadas por el usuario.
          case 11:{
            cout << "Por favor ingrese las siglas del curso:" << endl;
            string siglasInput;
            cin >> siglasInput;
            string nombreInput;
            int creditosInput;
            deque<Curso>::iterator itCursos;

            for (itCursos = cursos.begin(); itCursos != cursos.end(); itCursos++){
              if( siglasInput.compare( itCursos->getSigla() ) == 0 ){
                nombreInput = itCursos->getNombre();
                creditosInput = itCursos->getCreditos();
                break;
              }
            }

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
//______________________________________________________________________________
  cout << "El programa ha cerrado." << endl;
  return 0;
}
