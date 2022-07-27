#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i;
   for(i=0;s[i]!='\0';i++)   {}
   return i;
}

int charCount(string s,char c)
{
   int j=0;
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]==c)
      {
        j++;
      }
   }
   return j;
}

string substring(string s,int d,int h)
{
   string j = "";
   for(int i=d;i<h;i++)
   {
     j = j+s[i];
   }
   return j;
}

string substring(string s,int d)
{
   string j = "";
   for(int i=d;s[i]!='\0';i++)
   {
     j = j+s[i];
   }
   return j;
}

int indexOf(string s,char c)
{
   int i=0;
   int p = charCount(s,c);
   if(p>0)
   {
      while(s[i]!=c)
      {
         i++;
      }
      return i;
   }
   else
      {
         return (int)-1;
      }
}

int indexOf(string s,char c,int offSet)
{
   int x;
   string p = substring(s,offSet);
   if(indexOf(p,c)>=0)
      {
         x = offSet + indexOf(p,c);
      }
   else
      {
         x=-1;
      }
   return x;
}

int indexOf(string s,string toSearch)
{
   bool igualdadDeLetra = false;
   int posicion =-1;
   int p;
   for(int i=0 ; i<length(s) || igualdadDeLetra == true ; i++)
   {
      if(igualdadDeLetra==true)
      {
         posicion = indexOf(s,char(toSearch[0]),i-(p+1));
         break;
      }
      for(p=0;p<length(toSearch);p++)
      {
         if(s[i]==toSearch[p])
         {
            igualdadDeLetra = true;
            i++;
         }
         else
         {
            igualdadDeLetra = false;
            break;
         }
      }
   }

   return posicion;
}

int indexOf(string s,string toSearch,int offSet)
{
   int x;
   string p = substring(s,offSet);
   if(indexOf(p,toSearch)>=0)
      {
         x = offSet + indexOf(p,toSearch);
      }
   else
      {
         x=-1;
      }
   return x;
}

int lastIndexOf(string s,char c)
{
   int largoString = length(s);
   while(largoString>=0)
   {
      if(s[largoString]==c)
      {
         break;
      }
      largoString--;
   }
   return largoString;
}

int indexOfN(string s,char c,int n)
{
   int Rx=0;
   if(n>0&&n<=charCount(s,c))
   {
      int j=0,i=0;
      while(j!=n)
      {
         for(i=0;s[i]!='\0';i++)
         {
            if(s[i]==c)
            {
               j++;
            }
            else if(j==n)
            {
               break;
            }
         }
      }
      Rx = i-1;
   }
   else if(n>charCount(s,c)||n==0)
   {
      if(n>charCount(s,c))
      {
         Rx = length(s);
      }
      else if(n==0)
      {
         Rx = -1;
      }
   }
   return Rx;
}

int charToInt(char c)
{
   string caracteres ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int posicion = indexOf(caracteres,c);
   return posicion;
}

char intToChar(int i)
{
   string caracteres ="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   char c = char(caracteres[i]);
   return c;
}

int getDigit(int n,int i)
{
   while (i>0)
   {
       n /= 10; // n = n /10
       i--;
   }
   return (n % 10);
}

int digitCount(int n)
{

   int i=0;
   while (abs(n)>=1)
   {
       n /= 10; // n = n /10
       i++;
   }
   return i;
}

string intToString(int i)
{
   string x="";
   x = to_string(i);
   return x;

/* Otra forma de hacer el ejercicio.

   string j = "";
   int aux = digitCount(i);
   while(aux>0)
   {
      j = j + to_string(getDigit(i,aux));
      aux--;
   }
   return j;
   OTRA FORMA
      string res="";
   for(int a=digitCount(i);a>0;a--)
   {
      res += intToChar(getDigit(i,a-1));
   }
   return res; */
}

int stringToInt(string s,int b)
{
   int num=0;
   int base = 1;

   for(int a=length(s);a>0;a--)
   {
      num += charToInt(char(s[a-1]))*base;
      base *= b;
   }
   return num;
}

int stringToInt(string s)
{
   int num=0;
   int base = 1;

   for(int a=length(s);a>0;a--)
   {
      num += charToInt(char(s[a-1]))*base;
      base *= 10;
   }

   return num;
}

string charToString(char c)
{
   string x="";
   x = c;
   return x;
}

char stringToChar(string s)
{
   return char(s[0]);
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{
   string stringRe="";
   char cadena [20];
   sprintf (cadena,"%f",d);
   stringRe=cadena;
   return stringRe;
}

double stringToDouble(string s)
{
   string preCadena = substring(s,0,indexOf(s,'.'));
   string subCadena = substring(s,1+indexOf(s,'.'));
   double parteEntera = stringToInt(preCadena);
   double divisor=1;
      for(int i=0;i<length(subCadena);i++)
      {
         divisor *=10;
      }
   double parteDecimal = stringToInt(subCadena)/divisor;
   return double (parteEntera+parteDecimal);
}

bool isEmpty(string s)
{
   if(length(s)==0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool startsWith(string s,string x)
{
   if(indexOf(s,x)==0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool endsWith(string s,string x)
{
   int pul = lastIndexOf(s,char (x[0]));
   if(indexOf(s,x,pul)==-1)
   {
      return false;
   }
   else
   {
      if(x[length(x)-1]==s[length(s)-1] )
      {
         return true;
      }
      else
      {
         return false;
      }
   }
}

bool contains(string s,char c)
{
   if(charCount(s,c)>0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

string replace(string s,char oldChar,char newChar)
{
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]==oldChar)
      {
         s[i]=newChar;
      }
   }
   return s;
}

string insertAt(string s,int pos,char c)
{
   string preCadena = substring(s,0,pos);
   string posCadena = substring(s,pos);
   return preCadena + charToString(c) + posCadena;
}

string removeAt(string s,int pos)
{
   string preCadena = substring(s,0,pos);
   string posCadena = substring(s,pos+1);
   return preCadena + posCadena;
}

string ltrim(string s)
{
   int i=0;
   string newCadena = "";
   while(s[i]==' ')
   {
      s = removeAt(s,i);
   }
   return s;
}

string rtrim(string s)
{
   if(length(s)>0)
   {
      while(s[length(s)-1]==' ')
      {
         s = removeAt(s,length(s)-1);
         if(length(s)==0)
         {
            break;
         }
      }
      return s;
   }
   return s;
}

string trim(string s)
{
   return rtrim(ltrim(s));
}

string replicate(char c,int n)
{
   string s = "";
   while(n>0)
   {
      s = s + c;
      n--;
   }
   return s;
}

string spaces(int n)
{
   return replicate(' ',n);
}

string lpad(string s,int n,char c)
{
   string p = replicate(c,n-length(s));
   return p+s;
}

string rpad(string s,int n,char c)
{
   string p = replicate(c,n-length(s));
   return s+p;
}

string cpad(string s,int n,char c)
{
   if(n%2==0)
   {
      string p = replicate(c,(n-length(s))/2);
      return p+s+p;
   }
   else if(n%2!=0&&n>2)
   {
      int resta = n-1;
      string p = replicate(c,(resta-length(s))/2);
      return c+p+s+p;
   }
   else
   {
      return s;
   }
}

bool isDigit(char c)
{
   if(c>='0'&&c<='9')
   {
      return true;
   }
   return false;
}

bool isLetter(char c)
{
   if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
   {
      return true;
   }
   return false;
}

bool isUpperCase(char c)
{
   if(c>='A'&&c<='Z')
   {
      return true;
   }
   return false;
}

bool isLowerCase(char c)
{
   if(c>='a'&&c<='z')
   {
      return true;
   }
   return false;
}

char toUpperCase(char c)
{
   if(isLowerCase(c))
   {
      return c-32;
   }
   return c;
}

char toLowerCase(char c)
{
   if(isUpperCase(c))
   {
      return c+32;
   }
   return c;
}

string toUpperCase(string s)
{
   for(int i=0;i<length(s);i++)
   {
      s[i] = toUpperCase((char)s[i]);
   }
   return s;
}

string toLowerCase(string s)
{
   for(int i=0;i<length(s);i++)
   {
      s[i] = toLowerCase((char)s[i]);
   }
   return s;
}

int cmpString(string a,string b)
{
   string c = toLowerCase(a);
   string d = toLowerCase(b);
   int largo;
   if(length(c)>length(d))
   {
      largo = length(d);
   }
   else
   {
      largo = length(c);
   }
   for(int i=0;i<largo;i++)
   {
       if(c[i]>d[i])
       {
          return 1;
       }
       else if(c[i]<d[i])
       {
          return -1;
       }
   }
   if(length(c)>length(d))
   {
      return 1;
   }
   return 0;
}

int cmpDouble(double a,double b)
{
   if(a>b)
   {
      return 1;
   }
   else if(b>a)
   {
      return -1;
   }
   return 0;
}

#endif
