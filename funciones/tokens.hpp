#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep) // Retorna: int – Cuántos tokens genera sep en la cadena s.
{
   s = trim(s);
   if(length(s)==0)
   {
      return 0;
   }
      return charCount(s,sep) >= 0 ? (charCount(s,sep)+1) : 0;
}

void addToken(string& s,char sep,string t) // Retorna: void.  Agrega el token t al final de la cadena s.
{
/* if(length(s)==0)
   {
      s = t;
   }
   else
   {
      s = s+sep+t;
   }*/
   length(s)==0?s=t:s=s+sep+t;
}

string getTokenAt(string s,char sep, int i) // Retorna: string - El token ubicado en la posición i de la cadena s.

{
   int startIndex = indexOfN(s,sep,i); // Busca la primera ocurrencia del char sep a partir de los i (offsetes)
   int endIndex = indexOfN(s,sep,i+1); // Busca la siguiente ocurrencia del mismo.

   return substring(s,(startIndex+1),endIndex);
}

void removeTokenAt(string& s,char sep, int i) // Descripción: Remueve de s el token ubicado en la posición i. Retorna: void.
{
   int startIndex = indexOfN(s,sep,i); // Busca la primera ocurrencia del char sep a partir de los i (offsetes)
   int endIndex = indexOfN(s,sep,i+1); // Busca la siguiente ocurrencia del mismo.
/*   if(startIndex==-1)
   {
      s="";
   }*/
   startIndex==-1?s="":"";
   for(int x=0;x<(endIndex-startIndex);x++)
   {
      s = removeAt(s,startIndex);
   }
}

void setTokenAt(string& s,char sep, string t,int i) // Descripción: Reemplaza por t el token de s ubicado en la posición i. void.
/*{
   removeTokenAt(s,sep,i);
   int startIndex = indexOfN(s,sep,i);
   s = insertAt(s,startIndex+1,sep);

   for(int i=0 ;i<length(t);i++)
   {
      s = insertAt(s,startIndex+1,(char)t[length(t)-1-i]);
   }
}*/
{
    if(i == 0)
    {
        s = t + sep + substring(s, indexOf(s, sep) + 1);
    }
    else if(i == charCount(s, sep))
    {
        s = substring(s, 0, lastIndexOf(s, sep)) + sep + t;
    }
    else
    {
        s = substring(s, 0, indexOfN(s, sep, i)) + sep + t + substring(s, indexOfN(s, sep, i + 1));
    }
}

int findToken(string s,char sep, string t) // Determinar la posición que el token t ocupa dentro de la cadena s. int - La posición de la primera ocurrencia del token t dentro de la cadena
                                           // s, o un valor negativo si s no contiene a t.
{
   int firstOcurrencia = indexOf(s,t);
   int Token = charCount(substring(s,0,firstOcurrencia),sep);

   return Token;
}

#endif
