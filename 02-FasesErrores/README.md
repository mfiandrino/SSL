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
  
  #### 1. Preprocesador  
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
  * En el lugar del #include <stdio.h> el preprocesador copió y pegó los contratos o las declaraciones de todas las funciones y variables de stdio.h.  
  * Se pueden ver las declaraciones de las funciones de manejo de archivos como fwrite, fread, fseek, ftell, fclose, también la declaracion de puts, fputs, printf, fprintf, scanf, fscanf, getchar, getline que son todas funciones que venimos usando o usamos en algún momento y nunca vemos de donde salen, simplemente escribimos el #include.  
  * También se observa la declaración de tres variables de tipo FILE* que no son nada menos que el stdin, el stdout y e stderr.  
  * Por otro lado el preprocesador reemplazo el comentario "/*medio*/" por un espacio entre las palabras int y main.    

  Puedo concluir que el preprocesador no va a detectar errores de funciones mal escritas, falta de argumentos o llaves no cerradas, no es su función. El preprocesador se ocupa de traer de todos los includes los contratos o declaraciones de funciones y variables que estos tengan, de reemplazar comentarios por un espacio en blanco y también (aunque no lo hace en este caso) se ocupa de unir cadenas de caracteres que estan separadas por espacios sin nada entre sí. Por lo tanto es coherente que no haya errores en tiempo de preprocesamiento.  
       
  c) Escribir hello3.c, una nueva variante:
  ~~~
  int printf(const char * restrict s, ...);
  int main(void){
  int i=42;
  prontf("La respuesta es %d\n");
  ~~~
  d) Investigar e indicar la semántica de la primera línea  
    
  La primera línea declara el contrato de la función printf, indicando el tipo de dato que recibe como argumentos y el tipo de dato que devuelve.  
      
  e) Preprocesar hello3.c, no compilar, y generar hello3.i. Buscar diferencias entre hello3.c y hello3.i.  
      
  La única diferencia entre ambos archivos es el siguiente bloque de código que se pega arriba de la declaración de printf:
  ~~~
  # 1 "hello3.c"
  # 1 "<built-in>"
  # 1 "<command-line>"
  # 31 "<command-line>"
  # 1 "/usr/include/stdc-predef.h" 1 3 4
  # 32 "<command-line>" 2
  # 1 "hello3.c"
  ~~~
  En donde podemos ver que cada línea tiene el siguiente formato "# linenum filename flags" que se interpreta como que la siguiente línea se originó en el archivo **filename** en la línea **linenum**.  
  Luego vienen los **flags** que pueden ser '1' '2' '3' '4', alguna combinación de ellos o no tener ninguno:  
  * '1' indica el comienzo de un nuevo archivo
  * '2' indica el retorno a un archivo
  * '3' indica que el siguiente texto viene de un archivo header del sistema
  * '4' indica que el siguiente texto debería ser tratado como si estuviera envuelto   en un bloque "C" externo implícito  
    
  \<built-in> no es realmente un archivo, es un pseudo-archivo que contiene las definiciones de las macros del compilador.  

  \<command-line> tampoco es realmente un archivo, es la línea de comandos del preprocesador, que se considera como otra fuente de definiciones de macros.  
      
  Por último se ve en la quinta línea como esta vez si comienza un nuevo archivo real llamado "stdc-predef.h" cuyo path en mi sistema operativo es "/usr/include/stdc-predef.h" con los flags 1 ya que comienza un nuevo archivo y tambien con los flags 3 y 4.
    
#### 2. Compilación 
    