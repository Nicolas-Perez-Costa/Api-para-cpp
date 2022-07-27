#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"

using namespace std;

template<typename T>
struct Coll
{
   string token;
   char separador;
   int tokenIndex;
};

template<typename T>
Coll<T> coll(char sep)
{
   Coll<T> c;
   c.token="";
   c.separador=sep;
   c.tokenIndex=0;
   return c;
}

template<typename T>
Coll<T> coll()
{
   Coll<T> c;
   c.token="";
   c.separador='|';
   c.tokenIndex=0;
   return c;
}

template<typename T> // Descripci�n: Retorna la cantidad de elementos que contiene la colecci�n c. - int
int collSize(Coll<T> c)
{
   return tokenCount(c.token,c.separador);
}

template<typename T>
void collRemoveAll(Coll<T>& c) // Descripci�n: Remueve de la colecci�n c todos sus elementos, dej�ndola vac�a.
{
   c.token = "";
}

template<typename T>
void collRemoveAt(Coll<T>& c, int p) // Descripci�n: Remueve de la colecci�n c el elemento ubicado en la posici�n p.
{
   removeTokenAt(c.token,c.separador,p);
}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T)) // Descripci�n: Agrega el elemento t al final de la colecci�n c.
{
   addToken(c.token,c.separador,tToString(t));
   return collSize(c)-1;
}

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   setTokenAt(c.token,c.separador,tToString(t),p);
}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string)) // Descripci�n: Retorna el elemento que se ubica en la posici�n p de la colecci�n c
{
   T t=tFromString(getTokenAt(c.token,c.separador,p));
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   // recorro la coleccion c
   for(int i=0; i<collSize(c);i++)
   {
      // retorna el elemento que se ubica en la posicion p de la coleccion c
      T t = collGetAt<T>(c,i,tFromString);
      // comparo si los elementos son iguales
      if(cmpTK(t,k)==0)
      {
         return i;
      }
   }
   return -1;
}

template <typename T> // Descripci�n: Ordena los elementos de la colecci�n c seg�n el criterio de
                      // precedencia que establece cmpTT.
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
    T t1;
    T t2;

    for(int i = 0; i<collSize<T>(c); i++)
    {
        t1 = collGetAt<T>(c, i, tFromString);

        for(int z = i + 1; z < collSize<T>(c); z++)
        {
        t2 = collGetAt<T>(c, z, tFromString);
            if(cmpTT(t1, t2) > 0) // int cmpTT(T,T) - Funci�n que compara dos elementos tipo T (t1,t2) y
                                  // retorna: negativo si t1<t2; cero si t1==t2; positivo si t1>t2
            {
                collSetAt<T>(c, t2, i, tToString);
                collSetAt<T>(c, t1, z, tToString);

                t1 = t2;
            }
        }
    }
}

template<typename T>
bool collHasNext(Coll<T> c) // Descripci�n: Retorna true o false seg�n queden, en la colecci�n c, m�s elementos
                            // para continuar iterando.
{
   return c.tokenIndex+1 < collSize(c);
}

template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{
   c.tokenIndex++;
   return tFromString(collGetAt(c,c.tokenIndex,tFromString));
}

template<typename T> //Descripci�n: Retorna el pr�ximo elemento de la colecci�n c, indicando si se lleg� al
                     //   final de la colecci�n. De este modo, permite prescindir de usar collHasNext.
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   T t;
   return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.tokenIndex=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.separador+c.token;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.separador=s[0];
   c.token=substring(s,1);
   return c;
}

#endif
