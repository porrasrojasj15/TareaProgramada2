Diseño:

El main va a tener un map con una key que es el grupo y el value es una lista de estudiantes, una lista de grupos y un deque de cursos.
el primer paso es abrir los archivos de texto y leerlo (primero cursos y luego grupos)
para leer los cursos ignora la primera linea y despues de eso hace un ciclo mientras el archivo no termine lee 3 valores, 2 separados por ";" y el ultimo "\n", los guarda en variables, crea un objeto curso y le asigna los valores, finalmente lo guarda en el deque de cursos

1-Listar cursos: Accede al deque de cursos y crea un iterador para recorrerlos y segun pasa los va imprimiendo;

2-listar estudiantes: Accede al map y con un iterador pasa por cada par de valores que haya imprime la key y posteriormente accede a las lista vinculada y lo recorre con un iterador e imprime cada estudiante.

3-cobro de matricula para todos los estudiantes: pide año y semestre y lo busca por cada lista del map, si lo encuentra le pide el valor de creditos de ese grupo y lo guarda en una variable, finalmente le asigna la cantidad de creditos al estudiante y procede a guardarlo en una variable, repite ese metodo para cada estudiante vinculado a esa lista. 

4-Pedir los cursos de un estudiante en una semestre pide datos del estudiante, y de semestre; despues busca en el map una key que tenga el mismo semestre y año y luego entra en la lista asociada a buscar el estudiante y si lo encientra imprime la key

5-Calcular cobro para un estudiante: pide los datos del estudiante (carnet) y lo busca por cada lista del map, si lo encuentra le pide el valor de creditos de ese grupo y lo guarda en una variable, finalmente le asigna la cantidad de creditos al estudiante y procede a imprimir el cobro de matricula

6-eliminar un curso: pide las siglas del curso, busca el curso en el map y si la lista asociada esta vacia lo elimina, en caso conyrario no lo deja

7-Eliminar estudiantes de un grupo: pide el carnet de un estudiante y el curso de donde lo quiere eliminar, busca el curso en el map y si lo encuentra accede a la lsita vinculada, y procede a buscar el alumno por el carnet, si lo encuentra lo borra

8-eliminar grupo: pide el curso y lo busca en el map y si lo encuentra y la lista asignada esta vacia borra esa posicion.

9-Agregar un estudiante a un grupo: pide los datos para hacer estudiante, y pide el codigo  y lo crea (para asignar la beca hace un string.back() al carnet para sacar el ultimo dijoto y lo asigna a beca, (si la beca es mayor a 5 le pone un 5 automaticamente) despues con la edad asigna un grado academico al estudiante, posteriormente lo crea, despues busca el curso en el map y una vez encontrado lo asigna a la lista asignada al grupo

10-Agregar un curso: pide los datos del curso y crea un curso por defecto, despues le asigna los valores al curso creado y finalmente agrega el curso al deque de cursos 

11-Agregar un grupo: pide los datos del grupo, crea un grupo vacio y posteriormente le asigna los valores al grupo y crea una lista de estudiantes vacia, finalmente agrega el par curso creado y la lista vacia creada al map con un insert.
