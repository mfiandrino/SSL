#include <stdio.h>
#include <assert.h>
#include "Conversion.h"

int main (void)
{
    //Pruebas de Fahrenheit a Celsius
    assert(Celsius(32)  == 0);
    assert(Celsius(104) == 40);
    assert(Celsius(248) == 120);
    assert(Celsius(428) == 220);
    assert(Celsius(32)  != 2);
    assert(Celsius(104) != 48);
    assert(Celsius(248) != 95);
    assert(Celsius(428) != 365);

    //Pruebas de Celsius a Fahrenheit
    assert(Fahrenheit(0)    == 32);
    assert(Fahrenheit(20)   == 68);
    assert(Fahrenheit(140)  == 284);
    assert(Fahrenheit(300)  == 572);
    assert(Fahrenheit(0)    != 40);
    assert(Fahrenheit(20)   != 65);
    assert(Fahrenheit(140)  != 120);
    assert(Fahrenheit(300)  != 674);

    printf("Las pruebas han pasado con exito\n");
}
