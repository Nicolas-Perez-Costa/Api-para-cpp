#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t) // Descripci�n: Escribe el valor t en la posici�n actual del archivo f.
{

   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   // fseek(f,long int offset: 0,int origin: SEEK_CUR);
   fseek(f,0,SEEK_CUR);
   fwrite(&t,sizeof(T),1,f);

}

template<typename T> T read(FILE* f) // Descripci�n: Lee del archivo f un registro tipo T y retorna el valor le�do.
{
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   fseek(f,0,SEEK_CUR);
   T t;
   fread(&t,sizeof(T),1,f);
   return t;
}

template<typename T> void seek(FILE* f, int n) // Descripci�n: Mueve el indicador de posici�n del archivo f al inicio del registro n.
{
   fseek(f,n*sizeof(T),SEEK_SET);
}

template<typename T> int fileSize(FILE* f) // Descripci�n: Retorna la cantidad de registros tipo T que contiene el archivo.
{
   fseek(f,0,SEEK_END);
   int cantidadBytes = ftell(f);
   return cantidadBytes/sizeof(T);
}

template<typename T> int filePos(FILE* f) // Descripci�n: Retorna el n�mero de registro que est� siendo apuntado por el
                                          // indicador de posici�n del archivo f
{
   fseek(f,0,SEEK_CUR);
   int posiciconActual = ftell(f);
   return posiciconActual/sizeof(T);
}

#endif
