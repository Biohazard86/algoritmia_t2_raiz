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
    fprintf(stdout, "--                     Sergio Barrios                     --\n");
    fprintf(stdout, "------------------------------------------------------------\n\n");
}


//----------------------------------------------------------------------------------------------------------------------
// multiplicar_array
//----------------------------------------------------------------------------------------------------------------------
// Funcion que multiplica un array por otro numero
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero_array: el array de enteros que le pasas como factor
//      solucion: array de enteros que guarda la solucion de la multiplicacion
//      num: numero por el cual se multiplica el array
//----------------------------------------------------------------------------------------------------------------------

int multiplicar_array(int *numero_array,int *solucion , int tam,int num)
{

 //Se inicializa variables que seran contadores o que guardan el tamaño de los arrays y de la solucion
    int solucion_multi=0, resto=0 , sol_2,tam_sol=0;

    int tam_max=tam+1;

//Varables auxiliares que ayudaran a dar la vuelta al vector para un mejor tratamiento de estes para proceder a la multiplicacion
    int aux[tam];
    int aux2[tam];

//Se da la vuelta al vector y se guarda en una variable auxiliar
    for(int i=0,j=tam-1;i<tam;i++,j--)
    {
        aux[i]=numero_array[j];
    }

    //Se recorre todo el vector de numeros para que cada uno se multiplique por el numero introducido
    //En el caso de que el numero sea mayor de 9 se descompondra y la primera cifra se guardara en el array solucion
    //La segunda cifra de se guarda en la variable resto y en caso de que a la primera cifra de la solucion al sumarle el resto diera mayor a 9 se procederia a hacer lo mismo 
    //pero sumandole el segundo digito al resto
    for(int i=0;i<tam;i++)
    {

        solucion_multi=aux[i]*num;

        if(solucion_multi>9){
            if(i+1==tam){
                    
                    aux2[i]=(solucion_multi+resto)%10;
                    aux2[i+1]=(solucion_multi+resto)/10;
                    
                    tam_sol= i+1;
                    
                    
            }
            else{
                if(resto==0){
                    aux2[i]=solucion_multi%10;
                    resto=solucion_multi/10;
                }
                else{
                
                    aux2[i]=(solucion_multi%10)+resto;
                    resto=solucion_multi/10;
                    if(aux2[i]>9)
                    {
                        aux2[i]=aux2[i]%10;
                        resto+=1;
                    }
                    
                
                }
            }
            
            
        }
        else{
            aux2[i]=solucion_multi+resto;
             resto=0;
            tam_sol=i;
            
            
        }
          
        
    }
 
    for(int i=0,j=tam_sol;i<tam_max;i++,j--)
    {

        solucion[i]=aux2[j];
    }

    
    return tam_sol+1;
    
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
int busca_cercano(unsigned long long numero){
    int i;
    int num=numero;
    for(i=0; i<=num; i++){
        //printf ("\n%d\n",i);
        if((i*i) > num && num != 1){

            return i-1;
        }
        else if(num == 1){
            return 1;
        }            
    }
}

//----------------------------------------------------------------------------------------------------------------------
// Funcion calcula_cuadrado
//----------------------------------------------------------------------------------------------------------------------
// Funcion que calcula el cuadrado de un numero
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numero: numero del que queremos saber el cuadrado
//----------------------------------------------------------------------------------------------------------------------
int calcula_cuadrado(unsigned long long n){
    return n*n;
}




//----------------------------------------------------------------------------------------------------------------------
// Funcion busca_n
//----------------------------------------------------------------------------------------------------------------------
//Buscamos un numero que sea de la forma solucion*2 _ x_ menor que el resto
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      doble_solucion: array que contiene el doble de la solucion
//      resto: array que contiene el resto
//      tam_doble_solucion: numero que contiene el tamaño del doble de la solucion
//      tam_doble_solucion: numero que contiene el tamaño del resto
//----------------------------------------------------------------------------------------------------------------------
int busca_n(int *doble_solucion, int *resto,int tam_doble_solucion,int tam_resto){
    int i,j, *sol,tam_sol, busca_sol;


//Guardamos memoria para el array de enteros que contiene la solucion
    sol= (int*) malloc(sizeof(int)*10000000);

    
//Comprobamos todos los numeros del 0 al 9 
    for(i=0; i<10; i++){

        busca_sol=0;

 
        //Guardamos el numero del contador del bucle en la siguiente poscion de la variable 
        doble_solucion[tam_doble_solucion]=i;

        //Multiplicamos ese array por ese numero del bucle y comprobamos que si la solucion de la multiplicacion es mayor que el resto entonces 
        //se coge el numero anterior a este
        tam_sol=multiplicar_array(doble_solucion,sol,tam_doble_solucion+1,i);
 
        if(tam_sol>tam_resto){
            return i-1;
        }
        else{


            for(j=0;j<tam_resto;j++)
            {
                if(tam_sol==tam_resto &&  resto[busca_sol]<sol[busca_sol]){
                    
                    return i-1;    
                }
                else if(tam_sol==tam_resto &&  resto[busca_sol]==sol[busca_sol]){
                    busca_sol++;
                }

            }

            
            
        }

        
         
    }
    return 9;

}




//----------------------------------------------------------------------------------------------------------------------
// Funcion divide_dos_en_dos
//----------------------------------------------------------------------------------------------------------------------
//divide en dos el numero pasado por parametro
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      numeros_final: array que contiene el numero dividido en numeros de dos
//      numeros_inicio: array de numeros que le pasas como parametro
//      tam_num: tamaño del array del numero que le pasas como parametro
//----------------------------------------------------------------------------------------------------------------------

int divide_dos_en_dos(int *numeros_final, int *numeros_inicio, int tam_num){
    int cont=0;


    for(int i=0;i<tam_num;i++,cont++){

    
        if(tam_num%2!=0 && i==0){
            numeros_final[cont]=numeros_inicio[i];
        }
        else{
            numeros_final[cont]=concatenate(numeros_inicio[i],numeros_inicio[i+1]);
            i++;
        }
        
        
    }


}




//----------------------------------------------------------------------------------------------------------------------
// Funcion resta_arrays
//----------------------------------------------------------------------------------------------------------------------
// Funcion resta dos vectores de enteros
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      array1: vector de enteros que seran el minuendo de la resta
//      array2: vector de enteros que seran el sustraendo de la resta
//      cont: entero que el tamaño de array1
//      tam_doble_sol: entero que el tamaño de array2
//----------------------------------------------------------------------------------------------------------------------

void resta_arrays(int *array1,int *array2,int cont, int tam_doble_sol)
{
    int i,j,resto=0;
    
    int aux1[cont];
    int aux2[cont];
    
    for(int i=0,j=cont-1;i<cont;i++,j--)
    {
        aux2[i]=array2[j];
        
    }

//Se hace un blucle hasta llegar al limite de la varible del sustrayendo, una vez llegado hasta ahí los numeros del minuendo son iguales que los de la solucion
//Se hace que si los numeros son menores que si el numero del minuendo es menor que el numero del sustrayendo se le sume 10 al numero del minuendo y se le resta 
//una unidad al siguiente numero del minuendo

    for(i=cont-1,j=tam_doble_sol-1;i>=0 ;i--,j--)
    {

   
        if(j>=0)
        {
           

            if(array1[i]<array2[j])
            {
               
               array1[i]=((array1[i]+10))-array2[j];
               array1[i-1]=array1[i-1]-1;
               resto=1;
            }
            else{
                array1[i]=array1[i]-array2[j];
                resto=0;
               
            }
   
        }
        else{
            
            array1[i]=array1[i];
        }
        
        
    }
    
}

//----------------------------------------------------------------------------------------------------------------------
// Funcion hacer_raizv2
//----------------------------------------------------------------------------------------------------------------------
// Funcion que hace el algoritmo
//----------------------------------------------------------------------------------------------------------------------
// PARAMETROS
//      cont: contador que tiene la informacion de cuantas interacciones del algoritmo se tiene que hacer
//      numero_array: vector que contiene el numero pasado por parametro
//      resto: vector de enteros que sera el vector en que guardarenos el resto de la raiz
//      solucion: vector de enteros que sera el vector en que guardarenos la solucion de la raiz
//      tam_resto: entero que el tamaño de del resto
//      tam_sol: entero que el tamaño de de la solucion
//----------------------------------------------------------------------------------------------------------------------

int hacer_raizv2(int *cont,int *numero_array,int numero_parejas,int *resto,int *solucion,int *tam_resto,int *tam_sol)
{
    int cuadrado, *doble_solucion, n,tam_doble_solucion,i=0,j;

    doble_solucion= (int*) malloc(sizeof(int)*1000000);

    //Este es el caso trivial en el que es el primer numero o numeros en el cual podemos hacer la primera cuenta para ir sacando las demas
    if(*cont==0){


        resto[0]=numero_array[*cont];

//Se busca un numero que multiplicado por el mismo de lo mismo o menos que el resto  
        solucion[0]=busca_cercano(resto[0]);

//Se aumenta el tamaño de la solucion
        *tam_sol=*tam_sol+1;

//Se calcula el cuadrado de la solucion
        cuadrado = calcula_cuadrado(solucion[0]);

//Se resta el resto al cuadrado de la solucion y se obtiene el nuevo resto
        resto[0]=resto[0]-cuadrado;

//Se aumenta el tamaño del resto  
        *tam_resto=*tam_resto+1;

//Se quita los posibles 0
        if(resto[0]==0)
        {
            *tam_resto=*tam_resto=*tam_resto-1;
        }
        
        
        *cont=*cont+1;
        return 1;

    }  
    else{
        //Se decrementa el contador hasta llegar a 0 que es el caso trivial
        *cont=*cont-1;
        
        //Llamada recursiva
        hacer_raizv2(cont, numero_array,numero_parejas,resto,solucion,tam_resto,tam_sol);


    //calcula el doble de solucion
        tam_doble_solucion=multiplicar_array(solucion,doble_solucion,*tam_sol,2);
        
        
        //Si el resto es mayor que 9 divide el numero en 2 y se aumenta el resto
        resto[*tam_resto]=numero_array[*cont]/10;
        *tam_resto=*tam_resto+1;
        resto[*tam_resto]=numero_array[*cont]%10;
        *tam_resto=*tam_resto+1;


        //Se busca el numero inferior mas cercano al resto 
        n= busca_n(doble_solucion,resto,tam_doble_solucion,*tam_resto);
        

        solucion[*tam_sol]=n;
        *tam_sol=*tam_sol+1;

        doble_solucion[tam_doble_solucion]=n;
        tam_doble_solucion++;

        
        //Se calcula el numero inferior mas cercano al resto 
        tam_doble_solucion=multiplicar_array(doble_solucion,doble_solucion,tam_doble_solucion,n);

        //Se resta el resto con dicho numero para saber el nuevo resto
        resta_arrays(resto,doble_solucion,*tam_resto,tam_doble_solucion);


        //Se quitan los 0 delante del resto
        while(resto[i]==0)
        {
            for(j=0;j<*tam_resto;j++)
            {
                resto[j]=resto[j+1];
            }
            *tam_resto=*tam_resto-1;
        }


        *cont=*cont+1;

        
        return 1;        
        
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
//      tam_resto:tamaño del vector que contiene al resto
//      tam_sol:tamaño del vector que contiene la solucion
//----------------------------------------------------------------------------------------------------------------------
void mostrar_solucion(int *resto,int *solucion,int *tam_resto,int *tam_sol)
{
    int i;

    printf("\nSOLUCION: ");
    for(i=0;i<*tam_sol;i++)
    {
        printf("%d",solucion[i]);
    }
    printf("\n\n");

    printf("\nRESTO: ");
    for(i=0;i<*tam_resto;i++)
    {
        printf("%d",resto[i]);
    }
    printf("\n\n");
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
    int  *numero_array, tamano_array, *numero_array_temporal,*cont,*tam_resto,*tam_sol;
    int  *resto,*solucion;

    //Guarda memoria para las siguientes variables
    resto= (int*) malloc(sizeof(int)*100000);
    solucion= (int*) malloc(sizeof(int)*1000000);
    cont= malloc(sizeof(int)*1);

    tam_resto=  malloc(sizeof(int)*1);
    tam_sol=malloc(sizeof(int)*1);

    *tam_resto=0;
    *tam_sol=0;
    

//Recogemos el tamaño del parametro
    size_t size = strlen(argv[1]);

    int numero_parametro[size];
    int *numero_parametro2;

//Guardamos cada numero del parametro como un array

    for(int i=0;i<size;i++){
        numero_parametro[i]=argv[1][i]-'0';
    }


    presentacion();

    printf("\nEl numero que se va calcular es:\n");
    for(int i=0;i<size;i++){
        printf("%d",numero_parametro[i]);
    }

    
    fprintf (stdout, "\n\nSe procede al calculo.\n");

    //Dividimos el array del parametro en numeros de dos cifras 

    numero_parametro2 = (int*) malloc(sizeof(int)*size);

    divide_dos_en_dos(numero_parametro2, numero_parametro,size);

    

    if(size%2!=0){
        size=size/2+1;
    }
    else{
        size=size/2;
    }

    
    *cont=(int) size-1;
    
    

    hacer_raizv2(cont, numero_parametro2,size,resto,solucion,tam_resto,tam_sol);

    


    mostrar_solucion(resto,solucion,tam_resto,tam_sol);



}
