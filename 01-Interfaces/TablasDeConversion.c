/* TablasDeConversion.c
 * Archivo donde se ejecuta el programa principal. Imprime dos tablas de conversion
 * Maximiliano Fiandrino
 * 20210502
 */
#include <stdio.h>
#include "Conversion.h"

int main(void)
{
    const int LOWER = 0;
    const int UPPER = 300;
    const int STEP = 20;

    PrintTablas(LOWER,UPPER,STEP);
    return 0;
}