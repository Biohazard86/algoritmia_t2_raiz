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
int es_par(unsigned long long numero){

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
int busca_cercano(int *numero){
    int i;
    printf ("\n%d\n",(*numero));
    for(i=0; i<=*numero; i++){
        printf ("\n%d\n",i);
        if((i*i) > *numero && *numero != 1){
            printf ("\n%d\n",i);
            return i-1;
        }
        else if(*numero == 1)
        {
            return 1;
        }     
            
    }
    printf("No devuelve nada");  
}

//Funcion que calcula el cuadrado de un numero
int calcula_cuadrado(int *n){
    return (*n)*(*n);
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


int calcula_raiz(unsigned long long numero, int *numero_array, int *resto, int *solucion, int tamano_array){

    int i=0, raiz_cercana, numero_parejas, continuar = 1, cuadrado, doble_solucion, n, temporal;
    

    //Dividimos al numero en parejas de dos empezando por la izquierda, lo guardamos en un array
    numero_parejas = dividir_parejas(numero, numero_array,tamano_array);    //1
    //Vamos a empezar a calcular, buscamos el numero que multiplicado por si mismo nos de el numero mas parecido al primero del array y lo guardamos en la solucion
    (*resto) = numero_array[0];
    
    printf ("Se procede a calcular la raiz.\n");
    
    printf ("\n%d\n",numero_parejas);

    temporal = busca_cercano(resto);          //2
    // Guardamos temporal en la solucion
    solucion = &temporal; 
    // Imprimimos la solucion
    printf ("\nTemporal: %d\n", *solucion);

    
    
    



    //Hacemos el cuadrado de la solucion para restarselo al numero que hemos sacado del array
    cuadrado = calcula_cuadrado(solucion);          //3
    // Imprimimos el cuadrado de la solucion
    printf ("\nCuadrado: %d\n", cuadrado);
    
   
    
    (*resto) = (*resto) - cuadrado;             //4
    printf ("\n%d\n",(*resto));
    i++;
    if(i >= numero_parejas){
            continuar = 0;
    }

    while(continuar){

        // Con el doble_solucion de la solucino nos vamos a la parte auxiliar 
        doble_solucion = (*solucion)*2;                            //4
        
        // Concatenamos la siguiente pareja de numeros
        (*resto) = concatenate((*resto), numero_array[i]);     //5
        printf ("\nNuevo resto:%d\n",(*resto));
        //Buscamos un numero que sea de la forma solucion*2 _ x_ menor que el resto
        n = busca_n(doble_solucion, (*resto));                          //6
        // Concatenamos el numero encontrado con la solucino
        (*solucion) = concatenate((*solucion), n);                          //7
        printf ("\n%d\n",(*solucion));
        // Le restamos al resto doble_solucion concatenado con n x n
        (*resto) = (*resto) - (concatenate(doble_solucion, n)*n);                    




        //Incrementamos la iteracion
        
        // Condicion de parada
        i++;
        if(i >= numero_parejas){
            continuar = 0;
        }
        
    }

    mostrar_raiz((*resto),(*solucion));


}




int comprobar_num(int numero){

}


//Funcion que comprueba el tamanio del numero que tenemso en argv[1]
int comprueba_tam_numero(char *argv[]){
    int k;
    //Comprobamos la longitud del numero
    while (1){
        if(argv[1][k] == '\0'){ //Si el caracter es el final de la cadena
            break;              //Salimos del bucle
        }
        else{                   //Si no es el final de la cadena
            k++;                //Incrementamos el contador
        }
    }
    fprintf(stdout, "Se va a procesar un numero de %d digitos\n", k);
    return k;                   //Devolvemos el valor de k, es decir, la longitud del numero
}


// Funcion que convierte un string a un array de enteros
int string_a_array_enteros(char *argv[], int *array_numero, int tamano_array){
    int i, k, j, numero_temporal;
    

    //Convertimos el string a un array de enteros
    i=0;
    for(j=0; j<tamano_array; j++){
        
        
        // HAcemos un cast de char a int
        numero_temporal = argv[1][i]-'0';
        // Guardamos el numero en el array
        array_numero[j] = numero_temporal;
        //Imprimimos el numero
        //printf("El valor de array_numero[%d] es: %d\n", j, array_numero[j]);

        //Incrementamos el contador
        i++;
    }


}

int longitud_array_numeros(int tamano_array){
    if(tamano_array%2 == 0){
        return tamano_array/2;
    }
    else{
        return (tamano_array/2)+1;
    }
   
}

int divide_dos_en_dos(int *numeros_final, int *numeros_inicio, int tam){
    int i=0, j=0;

    for(i=tam-1; i>-1; i--){
        if((i-1) >0){
            numeros_final[i] = numeros_inicio[i-1]*10 + numeros_inicio[i];
        }
        else{
            numeros_final[i] = numeros_inicio[i];
        }
        
    }
}


int imprime_vector(int *array_numero, int tamano_array){
    int i;
    //Imprimimos el valor de array_numero
    printf ("------------------------------\n");
    printf ("El numero\n");
    for (i=0; i<tamano_array; i++)
    {
        printf ("%d", array_numero[i]);
    }
    printf ("\n");
    printf ("\n");
    printf ("El numero separado por un espacio en cada caracter\n");

    for (i=0; i<tamano_array; i++)
    {
        printf ("%d ", array_numero[i]);
    }
    printf ("\n");
}


int main (int argc, char *argv[])
{

    int  *numero_array, *resto, *solucion, tamano_array, *numero_array_temporal;

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

    // Preparacion de los datos:

    fprintf (stderr, "Se procede al calculo.\n");
    //Vemos la longitud del numero introducido
    tamano_array = comprueba_tam_numero(argv);

     //fprintf (stderr, "B.\n");
    //Reservamos memoria para el array
    numero_array_temporal = (int*) malloc(sizeof(int)*tamano_array);
    
    //fprintf (stderr, "C.\n");
    //Convertimos el string a un array de enteros
    string_a_array_enteros(argv, numero_array_temporal, tamano_array);

    //Aqui ya tenemos el numero en un array dividido en cifras
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    //Vamos a dividirlo de dos en dos
    //Vemos la longitud del array, para ello comprobamos si es par o impar

    numero_array = (int*) malloc(sizeof(int)*longitud_array_numeros(tamano_array));

    divide_dos_en_dos(numero_array, numero_array_temporal, longitud_array_numeros(tamano_array));

    
    //tamano_array=calculo_array(numero);
    //numero_array=(int *) calloc (tamano_array, sizeof (int));
    
    calcula_raiz(numero, numero_array, resto, solucion, tamano_array);
    


   //mostrar_raiz(resto, solucion);
}

