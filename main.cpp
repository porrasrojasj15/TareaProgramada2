#include "Estudiante.h"
#include "EstudianteBachi.h"
#include "EstudianteMaestria.h"
#include "EstudianteDoctorado.h"

int main(){
    Estudiante *ptrEstudiante = new Estudiante();
    cout << "Estudiante comun: " << endl;
    cout << *ptrEstudiante << endl;
    delete ptrEstudiante;
    
    Estudiante *ptrEstudianteBachi = new EstudianteBachi(); 
    cout << "Estudiante bachi: " << endl;
    cout << *ptrEstudianteBachi << endl;  
    delete ptrEstudianteBachi;

    Estudiante *ptrEstudianteDoctorado = new EstudianteDoctorado(); 
    cout << "Estudiante doctorado: " << endl;  
    cout << *ptrEstudianteDoctorado << endl;
    delete ptrEstudianteDoctorado;
    
    return 0; 
}

