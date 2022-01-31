// Trabajo 2 - Algoritmia
// Autores: David Barrios Portales & Sergios Barrios Portales
// Fecha: 12/2021
//-----------------------------------------------------------------------------

/*
Datos probados:
5676534

SOLUCION -> 2382
RESTO -> 2610

----------

456745324523345435

SOLUCION -> 675829360
RESTO -> 685335835

----------´

4567453245233

SOLUCION -> 2137160
RESTO -> 379633

----------

12345678908774589652145236985412

SOLUCION -> 3513641829893108
RESTO -> 1157118531085748

----------

123456789087712345678908774589652145236985412

SOLUCION -> 6171132129460938078
RESTO -> 11732841835877136320

----------

1239087712345678589652145236985412

SOLUCION -> 35200677725658615
RESTO -> 25307009713267187


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
            printf("\n%llu\n",i);
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

    

    printf("\n%d\n",tam_num);

    for(int i=0;i<tam_num;i++,cont++){
        printf("\n%d\n",i);
    
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



//Funcion que calcula el resultado de forma recursiva
int hacer_raiz(unsigned long long *resto,  unsigned long long *solucion,int cont,int *numero_array,int numero_parejas){
    int n, cuadrado;
    unsigned long long doble_solucion,temporal;

    printf("\nNumero parejas:%d\n",numero_parejas);
    printf("\ncont:%d\n",cont);

    //Mientras el contador no sea mayor o igual no entra y si entra es que ha acabado
    if(cont >= numero_parejas ){
      //Muestra la raiz
    mostrar_raiz(*resto,*solucion);     //Mostramos la solucion final y el resto
    return 1;          //Retornamos
    }else{
      //Para la primera iteraccion se necesita primero hacer 
    if(cont==0){    //Vemos si es la primera iteracion

        //El resto es el primer numero o par de numeros

        printf("\nnumeroarray%d\n",numero_array[cont]);
        (*resto) = numero_array[cont];

        //Se busca un numero que multiplicado por si mismo de ese numero
        //printf("\nBusca cercano:%d\n", busca_cercano(resto));
        temporal = busca_cercano(resto);


        printf("\nTemporal%d\n",temporal);
        solucion=&temporal;


        
        //printf("\nSoluciuon:%llu\n",*solucion);
        //Se calcula el cadruado de ese numero
        cuadrado = calcula_cuadrado(solucion);        
    
        //y depues de calcula el resto de ese numero
        (*resto) = (*resto) - cuadrado; 

        printf("\nResto%d\n",*resto);
        cont++;

        //Y por ultimo se pasa estos mismo datos como parametros
        hacer_raiz(resto,solucion,cont,numero_array,numero_parejas);
    }
    else{

        // Si no es la primera ejecución entonces se hace lo sigueinte  
        doble_solucion = *solucion *2;
        //printf("\ndoble solucion:%llu\n",doble_solucion);

        //Controlamos los restos, ya que puede dar problema los 0s
        if(numero_array[cont]==0 ||numero_array[cont]==1 ||numero_array[cont]==2 ||numero_array[cont]==3 ||numero_array[cont]==4 ||numero_array[cont]==5 ||
        numero_array[cont]==6 || numero_array[cont]==7|| numero_array[cont]==8 ||numero_array[cont]==9 )
        {
            *resto=*resto*100+numero_array[cont];
        }
        else{
             *resto = concatenate(*resto, numero_array[cont]);
        }
        printf("\nResto%d\n",*resto);

        //printf("\nPrimer resto:%llu\n",*resto);
        n = busca_n(doble_solucion, *resto);
        //printf("\nPrimer n:%d\n",n);
        *solucion = concatenate(*solucion, n);
        //printf("\nSolucion:%llu\n",*solucion);
        *resto = *resto - (concatenate(doble_solucion, n)*n);
        //printf("\nSegundo resto:%llu\n",*resto);
        cont++;
        hacer_raiz(resto,solucion,cont,numero_array,numero_parejas);
    }
    
    
  }
}

/*
void dividir_parametro(long int size)
{
    char *variables;
    //unsigned long long ;

    int num_var=(size/20)+1;
    int i;

    printf("\n%d\n",num_var);
    for(i=0;i<num_var;i++)
    {
         printf("\n%s\n",itoa("variables", "%d", i));
        variables[i]=sprintf("variables", "%d", i);
    }
    for(i=0;i<num_var;i++)
    {
        printf("\n%c\n",variables[i]);
    }

    
}
*/



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
    int  *numero_array, tamano_array, *numero_array_temporal,cont =0;
    unsigned long long numero, *resto,*solucion;

    

    size_t size = strlen(argv[1]);

    int numero_parametro[size];
    int *numero_parametro2;

    //printf("\n%ld\n",size);
    //printf("\n%d\n",argv[1][0]-'0');


    for(int i=0;i<size;i++){
        numero_parametro[i]=argv[1][i]-'0';
    }
    /*
    for(int i=0;i<size;i++){
        printf("%d--",numero_parametro[i]);
    }
    */

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
    
   
    presentacion();
    fprintf (stdout, "Se procede al calculo.\n");

    numero_parametro2 = (int*) malloc(sizeof(int)*size);

    printf("!!!\n");
    divide_dos_en_dos(numero_parametro2, numero_parametro,size);

    for(int i=0;i<size/2;i++){
        printf("\n%d\n",numero_parametro2[i]);
    }
    printf("!!!\n");

    if(size%2!=0){
        size=size/2+1;
    }
    else{
        size=size/2;
    }
    
    hacer_raiz(resto,solucion,cont,numero_parametro2,size);

  /*
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
    //printf("%d",longitud_array_numeros(tamano_array));
    hacer_raiz(resto,solucion,cont,numero_array,longitud_array_numeros(tamano_array));

    */
}



