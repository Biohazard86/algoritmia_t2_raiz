#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0




/*
ALGORITMO
0 - Recibimos el numero del que tenemos que calcular la raiz cuadrada por parametro
1 - Dividimos el numero en un vector de N/2 si es par y de N/2 + 1 si es impar y pasamos el numero al vector en parejas de dos
2 - Buscamos "la raiz" mas proxima para el primer elemento del vector, un numero que multiplicado por el mismo nos de el numero que buscamos sin pasarnos.  
3 - Hacemos el cuadrado del numero del paso 2 y lo restamos al grupo 0 de dos digitos dandonos el resto
4 - Hacemos el doble del numero obtenido en el paso 2 y lo guardamos en la variable doble_solucion

Vamos a hacer lo siguiente hasta que el array de pares este vacio, es decir, estemos en la ultima pareja (Puntos 5, 6, 7 y 8)
    5 - concatenamos al resto los dos siguientes elementos del array de pares
    6 - Buscamos un numero que cumpla: doble_solucion_ x _ menor o igual que el resto que tenemos ahora (doce_solucion_ es la variable doble_solucion concatenada con un el mismo numero por la que se va a multiplicar)
    Por ejemplo si la solucino que llevamos es 14 y tiene que parecerse a 730 entonces haremos 145x5 que es 725, dandonos el resto que es 5
    7 - Guardamos el numero que hemos obtenido en el paso 6 como solucion, concatenandolo con lo que ya tenemos en la variable solucion
    8 - Restamos el resultado de doble_solucion_ x _ al resto que tenemos ahora
    9 - actualizamos el valor de doble solucion con el resultado actualizado de solucion.

10 - Una vez acabado el bucle, imprimimos lo que tengamos como solucion y resto.

*/

// Divide un numero en pareja de dos digitos y los guarda en un array


//Calcula si las cifras del numero es par o no
int es_par(int numero){

  int cont=0;

  while (numero > 0)
    {
      numero = numero / 10;
      cont++;
    }

    if (cont % 2 != 0){
      return FALSE;
    }else
    {
      return TRUE;
    }
}


//Concatena dos numeros 
unsigned concatenate(unsigned x, unsigned y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

//Calcula en cuantas parejas de dos se tiene que dividir el numero y en caso de que sea impar el numero de digitos el ultimo que se guarda solo es 1 digito 
int calculo_array(unsigned long long numero)
{
    int numero_parejas=0;

    int numero_par=es_par(numero);

    while (numero > 0)
        {
            /*
            printf ("\n--%d--\n",numero); 
            printf ("\n--%d--\n",numero_parejas );
            printf ("\n--%d--\n",es_par(numero) );
            */
            
            //Si el numero de cifras dividido entre 100 quiere decir que es el ultimo numero y si tambien es inpar se hace que el ultimo numero solo sea una cifra
            if((numero/100)<0 && numero_par==FALSE)
     
            {
                numero = numero / 10;
                numero_parejas++;
            }

        numero = numero / 100;
        numero_parejas++;

    }

    return numero_parejas;
}


//divide el numero de parejas de dos y lo inserta en un array auxiliar para despues darles las vuelta
int dividir_parejas(unsigned long long numero, int *numero_array,int tamano_array){
    
    int numero_parejas=0;

    int array_aux[tamano_array];

    int numero_par=es_par(numero);
    

    while (numero > 0)
        {
            /*
            printf ("\n--%d--\n",numero); 
            printf ("\n--%d--\n",numero_parejas );
            printf ("\n--%d--\n",es_par(numero) );
            */
            
            
            //Si el numero de cifras dividido entre 100 quiere decir que es el ultimo numero y si tambien es inpar se hace que el ultimo numero solo sea una cifra

            if((numero/100)<0 && numero_par==FALSE)
            {

                array_aux[numero_parejas] = numero % 10;
                numero = numero / 10;
                numero_parejas++;
            }
        array_aux[numero_parejas] = numero % 100;
        numero = numero / 100;
        numero_parejas++;


    }


    for(int s=numero_parejas-1,i=0;s>=0;s--,i++)
    {
        numero_array[i]=array_aux[s];
    }

    return numero_parejas;
}


//Busca el numero mas cercano que multiplicado por si mismo de ese otro numero
int busca_cercano(int numero){
    int i;
    printf ("\n%d\n",numero);
    for(i=0; i<=numero; i++){
        printf ("\n%d\n",i);
        if((i*i) > numero && numero != 1){
            printf ("\n%d\n",i);
            return i-1;
        }
        else if(numero == 1)
        {
            return 1;
        }     
            
    }
    printf("No devuelve nada");  
}

//Funcion que calcula el cuadrado de un numero
int calcula_cuadrado(int n){
    return n*n;
}


int busca_n(int doble_solucion, int resto){
    int i, concatenacion;
    for(i=1; i<=resto; i++){
        concatenacion = concatenate(doble_solucion, i);
        if((concatenacion *i) > resto){
            return i-1;
        } 
    }

}

void mostrar_raiz(int resto, int solucion){
    printf("\nsolucion: %d\n", solucion);
    printf("RESTO: %d\n", resto );
}




int hacer_raiz(int resto, int solucion,int cont,int *numero_array,int numero_parejas){
    int doble_solucion,n, cuadrado;
    //printf("\nCont:%d\n",cont);
    //printf("\nNumero parejas:%d\n",numero_parejas);
    
    //Mientras el contador no sea mayor o igual no entra 
  if(cont >= numero_parejas ){
      //Muestra la raiz
    mostrar_raiz(resto,solucion);
    return 1;
  }else{
      //Para la primera interaccion se necesita primero hacer 
    if(cont==0){

        //El resto es el primer numero o par de numeros
        resto = numero_array[cont];

        //Se busca un numero que multiplicado por si mismo de ese numero
        solucion= busca_cercano(resto);

        //Se calcula el cadruado de ese numero
        cuadrado = calcula_cuadrado(solucion);

        //y depues de calcula el resto de ese numero
        resto = resto - cuadrado; 
        cont++;

        //Y por ultimo se pasa estos mismo datos como parametros
        hacer_raiz(resto,solucion,cont,numero_array,numero_parejas);
    }
    else{

        doble_solucion = solucion *2; 
        resto = concatenate(resto, numero_array[cont]);
        printf("\nPrimer resto:%d\n",resto);
        n = busca_n(doble_solucion, resto);
        printf("\nPrimer n:%d\n",n);
        solucion = concatenate(solucion, n);
        printf("\nSolucion:%d\n",solucion);
        resto = resto - (concatenate(doble_solucion, n)*n);
        printf("\nSegundo resto:%d\n",resto);
        cont++;
    }
    
    hacer_raiz(resto,solucion,cont,numero_array,numero_parejas);
  }
}


int main (int argc, char *argv[])
{

    int  *numero_array, resto=0, solucion=0, tamano_array, cont=0;
    unsigned long long numero;
    
    if (argc > 0)
    {
        
        numero = atoi (argv[1]);
        if (numero <= 0)
        {
            fprintf (stderr, "No existen raices negativas dentro de los numeros reales.\n");
            return 1;
        }
	}
    else{
        fprintf (stderr, "Error: No se han introducido todos los datos.\n");
        return 1;
    }


    tamano_array=calculo_array(numero);
    numero_array=(int *) calloc (tamano_array, sizeof (int));
    
    //calcula_raiz(numero, numero_array, resto, solucion, tamano_array);

    dividir_parejas(numero, numero_array,tamano_array);
    
    
    hacer_raiz(resto,solucion,cont,numero_array,tamano_array);


   //mostrar_raiz(resto, solucion);
}

