/*
Dada una aritmética modular en número primo p=761 y raíz primitiva r=6,
implementa un programa que genere un número aleatorio x, calcule X=rx mod p y
lo imprima. A continuación, el programa recoge como entrada por consola el número Y
que ha generado otro usuario y genera el número K=Yx=rxy.

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/**
 * @brief
 *
 * @param b
 * @param e
 * @param p
 * @return int
 */
// Funcion `b^e mod p`
int mod_exp(int b, int e, int p)
{
   int i, x, power;
   x = 1;
   power = b % p;

   for (i = 0; i < 8 * sizeof(int); i++)
   {
      if (e & 1)
      {
         x = (x * power) % p;
      }
      e >>= 1;
      power = (power * power) % p;
   }

   return x;
}

// Programa C para demostrar el algoritmo de Diffie-Hellman
int main()
{
   int p = 761;
   int r = 6;
   srand(time(NULL));

   // Numero aleatorio (Secreto)
   int numeroRandom;

   // X = Clave pública nuestra
   // Y = Clave pública que nos llega
   int X, Y;

   // Calculabmos numero aleatorio
   numeroRandom = rand();

   // Calculamos la X
   X = mod_exp(r, numeroRandom, p);

   printf("X:%d\n", X);

   // Pedimos que nos introduzcan su clave pública
   printf("Introduce el numero Y generado por otro usuario: ");
   scanf("%d", &Y);

   // Encontrar la clave privada
   int clave = mod_exp(Y, numeroRandom, p);

   printf("Clave privada es: %d\n", clave);
   return 0;
}