# TP01 - Intefaces

## Autor de la resolucion
* Usuario github: mfiandrino
* Legajo: 152.277-2
* Apellido: Fiandrino
* Nombre: Maximiliano

## Estandar de compilación
* c18

## Enunciado:
* Desarrollar un programa que imprima dos tablas de conversión, una de
Fahrenheit a Celsius y otra de Celsisu a Fahrenheit.

### 1. Objetivos
* Aplicar el uso de interfaces y de Makefile .

### 2. Temas
* Makefile
* Archivos header (.h)
* Tipo de dato double
* Funciones
* Pruebas unitarias
* assert
* Interfaces e Implementación

### 3. Tareas
* Escribir el Makefile
* Escribir Conversion.h
* Escribir ConversionTest.h
* Escribir Conversion.c
* Escribir TablasDeConversion.c

### 4. Restricciones
* Las funciones deben llamarse Celsius y Farenheit
* Utilizar assert
* Utilizar const
* Utilizar for con declaración (C99)

### 5. Productos
~~~
01-Interfaces
|-- README.md
|-- Makefile
|-- Conversion.h
|-- ConversionTest.c
|-- Conversion.c
`-- TablasDeConversion.c.
 ~~~

 ### 6. Credito Extra
 * Desarrolle TablasDeConversion.c para que use funciones del estilo PrintTablas, PrintTablaCelsius, PrintTablaFahrenheit, PrintFilas, PrintFila.
 * Desarrollar la función PrintFilas para que que sea genérica, es decir, pueda invocarse desde PrintTablaFahrenheit y desde PrintTablaCelsius. PrintFilas debe invocar a PrintFila.
