#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t) // Descripción: Escribe el valor t en la posición actual del archivo f.
{

   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   // fseek(f,long int offset: 0,int origin: SEEK_CUR);
   fseek(f,0,SEEK_CUR);
   fwrite(&t,sizeof(T),1,f);

}

template<typename T> T read(FILE* f) // Descripción: Lee del archivo f un registro tipo T y retorna el valor leído.
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   fseek(f,0,SEEK_CUR);
   T t;
   fread(&t,sizeof(T),1,f);
   return t;
}

template<typename T> void seek(FILE* f, int n) // Descripción: Mueve el indicador de posición del archivo f al inicio del registro n.
{
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> int fileSize(FILE* f) // Descripción: Retorna la cantidad de registros tipo T que contiene el archivo.
{
   fseek(f,0,SEEK_END);
   int cantidadBytes = ftell(f);
   return cantidadBytes/sizeof(T);
}

template<typename T> int filePos(FILE* f) // Descripción: Retorna el número de registro que está siendo apuntado por el
                                          // indicador de posición del archivo f
{
   fseek(f,0,SEEK_CUR);
   int posiciconActual = ftell(f);
   return posiciconActual/sizeof(T);
}

#endif
