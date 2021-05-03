#include <stdio.h>
#include "Conversion.h"

double Celsius (double f) //Fahrenheit to Celsius
{
    return (5.0 / 9.0) * (f - 32);
}

double Fahrenheit (double c) //Celsius to Fahrenheit
{
    return ((9.0 / 5.0) * c) + 32;
}


void PrintFila(char tipoFila, double valor)
{
    if (tipoFila == 'c')
        printf("%3.0f | %5.1f\n", valor, Celsius(valor) );
    else if(tipoFila == 'f')
        printf("%3.0f | %5.1f\n", valor, Fahrenheit(valor) );
    else
        printf("Error en el tipo de fila");
}

void PrintFilas(char tipoFila, const int LOWER, const int UPPER, const int STEP)
{
    for(int valor = LOWER; valor <= UPPER; valor = valor + STEP)
        PrintFila(tipoFila,valor);
}


void PrintTablaCelsius(const int LOWER, const int UPPER, const int STEP)
{
    printf("\n\nTabla de Fahrenheit a Celsius\n\n F° |  C°\n------------\n");
    PrintFilas('c',LOWER,UPPER,STEP);
}

void PrintTablaFahrenheit(const int LOWER, const int UPPER, const int STEP)
{
    printf("\n\nTabla de Celsius a Fahrenheit\n\n C° |  F°\n------------\n");
    PrintFilas('f',LOWER,UPPER,STEP);
}

void PrintTablas(const int LOWER, const int UPPER, const int STEP)
{
    PrintTablaCelsius(LOWER, UPPER, STEP);
    PrintTablaFahrenheit(LOWER, UPPER, STEP);
}

