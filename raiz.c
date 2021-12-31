// Trabajo 2 - Algoritmia
// Autores: David Barrios Portales & Sergios Barrios Portales
// Fecha: 12/2021
//-----------------------------------------------------------------------------


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



//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Definiciones
#define TRUE 1
#define FALSE 0



//----------------------------------------------------------------------------------------------------------------------
// Funcion presentacion
//----------------------------------------------------------------------------------------------------------------------
// Funcion que presenta el programa
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//----------------------------------------------------------------------------------------------------------------------
void presentacion(){
    fprintf(stdout, "------------------------------------------------------------\n");
    fprintf(stdout, "--                TRABAJO 2 - CURSO 2021/2022             --\n");
    fprintf(stdout, "--    Raiz cuadrada de numeros de precision arbitraria    --\n");
    fprintf(stdout, "------------------------------------------------------------\n");
    fprintf(stdout, "--           David Barrios   &   Sergio Barrios           --\n");
    fprintf(stdout, "------------------------------------------------------------\n\n");
}


//----------------------------------------------------------------------------------------------------------------------
// Funcion es_par
//----------------------------------------------------------------------------------------------------------------------
// Funcion que comprueba si es par el numero que le pasamos
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero: el numero que recibimos para comprobar si es par o no
//----------------------------------------------------------------------------------------------------------------------
int es_par(unsigned long long numero){

  int cont=0;

  while (numero > 0){
      numero = numero / 10;
      cont++;
    }
    if (cont % 2 != 0){
      return FALSE;
    }else{
      return TRUE;
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Funcion concatenate
//----------------------------------------------------------------------------------------------------------------------
// Funcion que concatena dos numeros
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      x: primer numero
//      y: segundo numero
//----------------------------------------------------------------------------------------------------------------------
unsigned long long concatenate(unsigned long long x, unsigned long long y) {
    unsigned pow = 10;
    while(y >= pow)
        pow *= 10;
    return x * pow + y;        
}

//----------------------------------------------------------------------------------------------------------------------
// Funcion calculo_array
//----------------------------------------------------------------------------------------------------------------------
// Funcion que calcula en cuantas parejas de dos se tiene que dividir el numero que le pasamos
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero: numero para calcular
//----------------------------------------------------------------------------------------------------------------------
//Calcula en cuantas parejas de dos se tiene que dividir el numero y en caso de que sea impar el numero de digitos el ultimo que se guarda solo es 1 digito 
int calculo_array(unsigned long long numero)
{
    int numero_parejas=0;

    int numero_par=es_par(numero);

    while (numero > 0){
            /*
            printf ("\n--%d--\n",numero); 
            printf ("\n--%d--\n",numero_parejas );
            printf ("\n--%d--\n",es_par(numero) );
            */
            
            //Si el numero de cifras dividido entre 100 quiere decir que es el ultimo numero y si tambien es inpar se hace que el ultimo numero solo sea una cifra
            if((numero/100)<0 && numero_par==FALSE){
                numero = numero / 10;
                numero_parejas++;
            }

        numero = numero / 100;
        numero_parejas++;
    }
    return numero_parejas;
}


//----------------------------------------------------------------------------------------------------------------------
// Funcion dividir_parejas
//----------------------------------------------------------------------------------------------------------------------
// Funcion que divide el numero de parejas de dos y lo inserta en un array auxiliar para despues darles las vuelta
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero: numero para calcular
//      numero_array: array donde se guardan los numeros
//      tamano_array: tamaño del array
//----------------------------------------------------------------------------------------------------------------------
//
int dividir_parejas(unsigned long long numero, int *numero_array,int tamano_array){  
    int numero_parejas=0;
    int array_aux[tamano_array];
    int numero_par=es_par(numero);
    
    while (numero > 0){
            /*
            printf ("\n--%d--\n",numero); 
            printf ("\n--%d--\n",numero_parejas );
            printf ("\n--%d--\n",es_par(numero) );
            */
            
            //Si el numero de cifras dividido entre 100 quiere decir que es el ultimo numero y si tambien es inpar se hace que el ultimo numero solo sea una cifra
            if((numero/100)<0 && numero_par==FALSE){
                array_aux[numero_parejas] = numero % 10;
                numero = numero / 10;
                numero_parejas++;
            }
        array_aux[numero_parejas] = numero % 100;
        numero = numero / 100;
        numero_parejas++;
    }

    for(int s=numero_parejas-1,i=0;s>=0;s--,i++){
        numero_array[i]=array_aux[s];
    }
    return numero_parejas;
}

//----------------------------------------------------------------------------------------------------------------------
// Funcion busca_cercano
//----------------------------------------------------------------------------------------------------------------------
// Funcion que busca el numero mas cercano que multiplicado por si mismo de ese otro numero
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero: numero del que queremos saber el mas cercano
//----------------------------------------------------------------------------------------------------------------------
int busca_cercano(unsigned long long *numero){
    int i;
    //printf ("\n%llu\n",(*numero));
    for(i=0; i<=*numero; i++){
        //printf ("\n%d\n",i);
        if((i*i) > *numero && *numero != 1){
            //printf ("\n%d\n",i);
            return i-1;
        }
        else if(*numero == 1){
            return 1;
        }            
    }
    //printf("No devuelve nada");  
}

//----------------------------------------------------------------------------------------------------------------------
// Funcion calcula_cuadrado
//----------------------------------------------------------------------------------------------------------------------
// Funcion que calcula el cuadrado de un numero
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero: numero del que queremos saber el cuadrado
//----------------------------------------------------------------------------------------------------------------------
int calcula_cuadrado(unsigned long long *n){
    return (*n)*(*n);
}


//Buscamos un numero que sea de la forma solucion*2 _ x_ menor que el resto
int busca_n(unsigned long long doble_solucion, unsigned long long resto){
    unsigned long long i, concatenacion;
    for(i=1; i<=resto; i++){
        concatenacion = concatenate(doble_solucion, i);
        if((concatenacion *i) > resto){
            return i-1;
        } 
    }

}


//----------------------------------------------------------------------------------------------------------------------
// Funcion mostrar_raiz
//----------------------------------------------------------------------------------------------------------------------
// Funcion que muestra la solucion
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      resto: resto final
//      solucion: solucion final
//----------------------------------------------------------------------------------------------------------------------
void mostrar_raiz(unsigned long long resto, unsigned long long solucion){
    printf("\n");
    printf("SOLUCION -> %llu\n", solucion);
    printf("RESTO -> %llu\n", resto );
}


//----------------------------------------------------------------------------------------------------------------------
// Funcion calcula_raiz
//----------------------------------------------------------------------------------------------------------------------
// Funcion que calcula la raiz
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero_array: array donde se guarda el numero en parejas
//      resto: se van guardando los restos
//      solucion: se van guardando las soluciones
//      tamano_array: tamaño del array del numero de parejas
//----------------------------------------------------------------------------------------------------------------------
int calcula_raiz(int *numero_array, unsigned long long *resto, unsigned long long *solucion, int tamano_array){

    int i=0, raiz_cercana, numero_parejas, continuar = 1, cuadrado,  n ;
    unsigned long long doble_solucion,temporal;

    //for(int i=0;i<tamano_array;i++){
    //	printf("\n%d\n",numero_array[i]);
    //}
    //Dividimos al numero en parejas de dos empezando por la izquierda, lo guardamos en un array
    numero_parejas = tamano_array;    //1

    //Vamos a empezar a calcular, buscamos el numero que multiplicado por si mismo nos de el numero mas parecido al primero del array y lo guardamos en la solucion
    (*resto) = numero_array[0];

    temporal = busca_cercano(resto);          //2
    // Guardamos temporal en la solucion
    solucion = &temporal; 
    // Imprimimos la solucion
    //printf ("\nTemporal: %llu\n", *solucion);

    //Hacemos el cuadrado de la solucion para restarselo al numero que hemos sacado del array
    cuadrado = calcula_cuadrado(solucion);          //3

    (*resto) = (*resto) - cuadrado;             //4
    //printf ("\n%llu\n",(*resto));
    i++;
    if(i >= numero_parejas){
            continuar = 0;
    }

    while(continuar){

        // Con el doble_solucion de la solucino nos vamos a la parte auxiliar 
        doble_solucion = (*solucion)*2;                            //4
        
        // Concatenamos la siguiente pareja de numeros
        (*resto) = concatenate((*resto), numero_array[i]);     //5
        //printf ("\nNuevo resto:%llu\n",(*resto));
        //Buscamos un numero que sea de la forma solucion*2 _ x_ menor que el resto
        n = busca_n(doble_solucion, (*resto));                          //6
        // Concatenamos el numero encontrado con la solucino
        (*solucion) = concatenate((*solucion), n);                          //7
        //printf ("\n%llu\n",(*solucion));
        // Le restamos al resto doble_solucion concatenado con n x n
        //printf ("\n%llu-%llu%d*%d\n",(*resto),doble_solucion,n,n);

        (*resto) = (*resto) - (concatenate(doble_solucion, n)*n);  
        //printf ("\nNuevo resto 2:%llu\n",(*resto));                  

        //Incrementamos la iteracion
        // Condicion de parada
        i++;
        if(i >= numero_parejas){
            continuar = 0;
        }
        
    }

    //Mostramos la solucion
    mostrar_raiz((*resto),(*solucion));


}


//----------------------------------------------------------------------------------------------------------------------
// Funcion comprueba_tam_numero
//----------------------------------------------------------------------------------------------------------------------
// Funcion que comprueba el tamanio que tiene el numero que nos pasan por paramaetro
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      argv: argumento que nos pasan por parametro
//----------------------------------------------------------------------------------------------------------------------

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
    fprintf(stdout, "Numero de %d digitos\n", k);
    return k;                   //Devolvemos el valor de k, es decir, la longitud del numero
}


//----------------------------------------------------------------------------------------------------------------------
// Funcion string_a_array_enteros
//----------------------------------------------------------------------------------------------------------------------
// Funcion que convierte el parametro a un array de enteros
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      argv: argumento que nos pasan por parametro
//      array_numeros: array donde se guarda el numero en parejas
//      tamano_array: tamaño del array del numero de parejas
//----------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------
// Funcion longitud_array_numero
//----------------------------------------------------------------------------------------------------------------------
// Funcion que dice si la longitud del array es n medios o n medios mas uno
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      tamano_array: tamaño del array del numero de parejas
//----------------------------------------------------------------------------------------------------------------------
int longitud_array_numeros(int tamano_array){
    if(tamano_array%2 == 0){
        return tamano_array/2;
    }
    else{
        return (tamano_array/2)+1;
    }
   
}

int divide_dos_en_dos(int *numeros_final, int *numeros_inicio, int tam_num){
    int cont=0;

    //printf("\n%d\n",tam_num);

    for(int i=0;i<tam_num;i++,cont++){
        //printf("\n%d\n",i);
    
        if(tam_num%2!=0 && i==0){
            numeros_final[cont]=numeros_inicio[i];
        }
        else{
            numeros_final[cont]=concatenate(numeros_inicio[i],numeros_inicio[i+1]);
            i++;
        }
        
        
    }
/*     
    for(i=tam2-1; i>-1; i--){
        if((i-1) >0){
            numeros_final[i] = numeros_inicio[i-1]*10 + numeros_inicio[i];
        }
        else{
            numeros_final[i] = numeros_inicio[i];
        }
        
    }
*/

}

//----------------------------------------------------------------------------------------------------------------------
// Funcion imrpime_vector
//----------------------------------------------------------------------------------------------------------------------
// Funcion que imprime un vector
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      array_numero: array que queremos imprimir
//      tamanio_array: tamaño del array
//----------------------------------------------------------------------------------------------------------------------
int imprime_vector(int *array_numero, int tamano_array){
    int i;
    //Imprimimos el valor de array_numero
    printf ("------------------------------\n");
    printf ("El numero\n");
    for (i=0; i<tamano_array; i++){
        printf ("%d", array_numero[i]);
    }
    printf ("\n");
    printf ("\n");
    printf ("El numero separado por un espacio en cada caracter\n");

    for (i=0; i<tamano_array; i++){
        printf ("%d ", array_numero[i]);
    }
    printf ("\n");
}




//----------------------------------------------------------------------------------------------------------------------
// Funcion main
//----------------------------------------------------------------------------------------------------------------------
// Funcion principal
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//----------------------------------------------------------------------------------------------------------------------
int main (int argc, char *argv[])
{

    //Variables
    int  *numero_array, tamano_array, *numero_array_temporal;
    unsigned long long numero, *resto,*solucion;


    // Control de errores
    if (argc > 1){ 
        numero = atoi (argv[1]);
        if (numero <= 0){
            fprintf (stderr, "No existen raices negativas dentro de los numeros reales.\n"); return 1;
        }
	}
    else{
        fprintf (stderr, "Error: No se han introducido todos los datos.\n"); return 1;
    }

    
    // Presentacion del programa
    presentacion();

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
    // Preparacion de los datos:
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=

    fprintf (stderr, "Se procede al calculo.\n");
    //Vemos la longitud del numero introducido
    tamano_array = comprueba_tam_numero(argv);
    //Reservamos memoria para el array
    numero_array_temporal = (int*) malloc(sizeof(int)*tamano_array);
    //Convertimos el string a un array de enteros
    string_a_array_enteros(argv, numero_array_temporal, tamano_array);
    numero_array = (int*) malloc(sizeof(int)*longitud_array_numeros(tamano_array));
    // Dividimos en parejas de dos
    divide_dos_en_dos(numero_array, numero_array_temporal,tamano_array);

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
    // Calculo de la raiz:
    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=
    
    calcula_raiz( numero_array, resto, solucion, longitud_array_numeros(tamano_array));
    
}

