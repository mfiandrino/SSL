# Makefile
# Makefile para compilar varios archivos separados
# Maximiliano Fiandrino
# 20210502

all : TablasDeConversion ConversionTest
BIN		= TablasDeConversion
BIN2	= ConversionTest
OBJ		= TablasDeConversion.o Conversion.o
OBJ2	= ConversionTest.o Conversion.o
CC		= gcc
CFLAGS	= -std=c18

# Creo el ejecutable de Tablas de Conversion
$(BIN): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN)

#Creo el codigo objeto de TablasDeConversion
TablasDeConversion.o: TablasDeConversion.c Conversion.h
	$(CC) $(CFLAGS) -c TablasDeConversion.c -o TablasDeConversion.o 



# Creo el ejecutable de ConversionTest
$(BIN2): $(OBJ2) 
	$(CC) $(CFLAGS) $(OBJ2) -o $(BIN2)

#Creo el codigo objeto de ConversionTest
ConversionTest.o: ConversionTest.c Conversion.h
	$(CC) $(CFLAGS) -c ConversionTest.c -o ConversionTest.o



#Creo el codigo objeto de las funciones de Conversion.c para crear ambos ejecutables
Conversion.o: Conversion.c Conversion.h
	$(CC) $(CFLAGS) -c Conversion.c -o Conversion.o

