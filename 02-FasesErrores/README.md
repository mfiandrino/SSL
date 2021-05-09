# Fases de la Traducción y Errores

## 1. Objetivos
* Este trabajo tiene como objetivo identificar las fases del proceso de traducción o Build y los posibles errores asociados a cada fase.
* Para lograr esa identificación se ejecutan las fases de traducción una a una, se detectan y corrigen errores, y se registran las conclusiones en readme.md.
* No es un trabajo de desarrollo; es más, el programa que usamos como ejemplo es simple, similar a hello.c pero con errores que se deben corregir. La complejidad está en la identificación y comprensión de las etapas y sus productos.

## 2. Temas
* Fases de traducción
* Preprocesamiento
* Compilación
* Ensamblado
* Vinculación (Link)
* Errores en cada fase
* Compilación separada

## 3. Tareas
* La primera tarea es investigar las funcionalidades y opciones que su
compilador presenta para limitar el inicio y fin de las fases de traducción.
* La siguiente tarea es poner en uso lo que se encontró. Para eso se debe
transcribir al readme.md cada comando ejecutado y su resultado o error
correspondiente a la siguiente secuencia de pasos. También en readme.md se
vuelcan las conclusiones y se resuelven los puntos solicitados. Para claridad,
mantener en readme.md la misma numeración de la secuencia de pasos.

### 3.1 Secuencia de pasos
Se parte de un archivo fuente que es corregido y refinado en sucesivos pasos.
Es importante no saltearse pasos para mantener la correlación, ya que el estado
dejado por el paso anterior es necesario para el siguiente.

1. Preprocesador  
    a) Escribir hello2.c, que es una variante de hello.c:
    ~~~
    #include <stdio.h>
    int/*medio*/main(void){
    int i=42;
    prontf("La respuesta es %d\n");
    ~~~
    b) Preprocesar hello2.c, no compilar, y generar hello2.i. Analizar su contenido. ¿Qué conclusiones saca?  
      
      Para solo preprocesar el archivo fuente tuve que agregar el flag -E al compilador gcc. Comando: "gcc hello2.c -E -o hello2.i"
  
      Una vez preprocesado el archivo fuente, se puede ver que no hubo errores en tiempo de preprocesamiento. Lo que se puede oberservar en el nuevo archivo hello2.i es:  
      * En el lugar del #include <stdio.h> el preprocesador copió y pegó los contratos o las declaraciones de todas las funciones de stdio.h.  
      * Se pueden ver las declaraciones de las funciones de manejo de archivos como fwrite, fread, fseek, ftell, fclose, también la declaracion de puts, fputs, printf, fprintf, scanf, fscanf, getchar, getline que son todas funciones que venimos usando o usamos en algún momento y nunca vemos de donde salen, simplemente escribimos el #include.  
      * También se observa la declaración de tres variables de tipo FILE* que no son nada menos que el stdin, el stdout y e stderr.  
      * Por otro lado el preprocesador reemplazo el comentario "/*medio*/" por un espacio entre las palabras int y main.    

     Puedo concluir que el preprocesador no va a detectar errores de funciones mal escritas, falta de argumentos o llaves no cerradas, no es su función. El preprocesador se ocupa de traer de todos los includes los contratos o declaraciones de funciones y variables que estos tengan, de reemplazar comentarios por un espacio en blanco y también (aunque no lo hace en este caso) se ocupa de unir cadenas de caracteres que estan separadas por espacios sin nada entre sí. Por lo tanto es coherente que no haya errores en tiempo de preprocesamiento.
    