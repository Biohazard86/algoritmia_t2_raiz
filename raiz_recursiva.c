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


int multiplicar_array(int *numero_array,int *solucion , int tam,int num)
{

    int solucion_multi=0, resto=0 , sol_2,tam_sol=0;

    int tam_max=tam+1;
    int aux[tam];
    int aux2[tam];

    for(int i=0,j=tam-1;i<tam;i++,j--)
    {
        aux[i]=numero_array[j];
    }
    /*
    for(int i=0;i<tam;i++){
        printf("\n%d\n--",aux[i]);
    }

     printf("\n%d\n--",num);
*/
    for(int i=0;i<tam;i++)
    {

        solucion_multi=aux[i]*num;
       // printf("\nsolucion_multi:%d\n",solucion_multi);
         //printf("\nresto:%d\n",resto);
        if(solucion_multi>9){
            if(i+1==tam){
                   // printf("!!!\n");
                    aux2[i]=(solucion_multi%10)+resto;
                    aux2[i+1]=solucion_multi/10;
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
                
                }
            }
            
            
        }
        else{
            aux2[i]=solucion_multi+resto;
            tam_sol=i;
            
            
        }
        
    }
   /*
    printf("!!!\n");
    for(int i=0;i<tam_sol+1;i++){
        printf("\n%d\n--",aux2[i]);
    }
    
    printf("!!!\n");
        
    printf("%d\n",tam_sol);
    printf("%d\n",tam);
    */
    for(int i=0,j=tam_sol;i<tam_max;i++,j--)
    {
       // printf("!!!\n");
        // printf("\n%d\n--",aux2[j]);
        solucion[i]=aux2[j];
    }

    //printf("tam_sol---%d\n",tam_sol+1);
    
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
    //printf ("\n%llu\n",(*numero));
    for(i=0; i<=num; i++){
        //printf ("\n%d\n",i);
        if((i*i) > num && num != 1){
            //printf ("\n%d\n",i);
            return i-1;
        }
        else if(num == 1){
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
int calcula_cuadrado(unsigned long long n){
    return n*n;
}


//Buscamos un numero que sea de la forma solucion*2 _ x_ menor que el resto
int busca_n(int *doble_solucion, int *resto,int tam_doble_solucion,int tam_resto){
    int i,j, *sol,tam_sol, busca_sol;

    sol= (int*) malloc(sizeof(int)*10000000);

    //resto= (int*) malloc(sizeof(int)*1);
    
    //printf("\nTam doblesol %d\n",tam_doble_solucion);
    //printf("\ntam resto%d\n",tam_resto);

    for(int i=0;i<tam_doble_solucion;i++)
    {
        printf("\nDOBE SOL :: %d-----\n",doble_solucion[i]);
    }
    
    for(int i=0;i<tam_resto;i++)
    {
        printf("\nRESTO :: %d-----\n",resto[i]);
    }
    
   
    for(i=0; i<10; i++){

        busca_sol=0;

        //printf("\ni--%d\n",i);
        
        doble_solucion[tam_doble_solucion]=i;

        /*
        for(int i=0;i<tam_doble_solucion+1;i++)
        {
            printf("\nDOBE SOL :: %d-----\n",doble_solucion[i]);
        }
        */
        tam_sol=multiplicar_array(doble_solucion,sol,tam_doble_solucion+1,i);
        printf("\ntam_sol: %d\ni:%d\n",tam_sol,i);
        /*
        for(int i=0;i<tam_sol;i++)
        {
            printf("\nSOL :: %d-----\n",sol[i]);
        }
        */
        if(tam_sol>tam_resto){
            //printf("\n!!!! %d \n",i);
            return i-1;
        }
        else{
            /*
            for(j=0;j<tam_resto;j++)
            {

                printf("\nRESTO i: %d\n",resto[j]);
                printf("\nSOL i: %d\n",sol[busca_sol]);
            }
            printf("\nCompara RESTO i: %d\n",resto[busca_sol]);  
            printf("\nCompara SOL i: %d\n",sol[busca_sol]);   
*/
            for(j=0;j<tam_resto;j++)
            {
                if(tam_sol==tam_resto &&  resto[busca_sol]<sol[busca_sol]){
                    printf("\n!!!! %d \n",j);
                    return i-1;    
                }
                else if(tam_sol==tam_resto &&  resto[j]==sol[busca_sol]){
                    busca_sol++;
                }

            }

            
            
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

    

    printf("\nTamnum%d\n",tam_num);

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

void resta_arrays(int *array1,int *array2,int cont, int tam_doble_sol)
{
    int i,j,resto=0;
    
    int aux1[cont];
    int aux2[cont];
    /*
    for(int i=0,j=cont-1;i<cont;i++,j--)
    {
        aux1[i]=array1[j];
        printf("aux1:%d",aux1[i]);
    }
    for(int i=0,j=cont-1;i<cont;i++,j--)
    {
        aux2[i]=array2[j];
        printf("aux2:%d",aux2[i]);
    }
    

    for(int i=0;i<cont;i++)
    {
       array1[i]= aux1[i];
    }

    for(int i=0;i<cont;i++)
    {
       array2[i]= aux2[i];
    }
    */


    for(i=cont-1,j=tam_doble_sol-1;i>=0 ;i--,j--)
    {

        //printf("\ni--%d\nj---%d\n",i,j);
        if(j>=0)
        {
            printf("%d-%d",array1[i],array2[j]);
            array1[i]=array1[i]-array2[j]-resto;
            //printf("***%d",array1[i]);
            
            if(array1[i]<0){
                array1[i]=array1[i]+10;
                //printf("%d",array1[i]);
                resto=1;
            }
            else{
                resto=0;
            }
        }
        else{
            //printf("***%d",array1[i]);
            array1[i]=array1[i];
        }
        
        
    }
    
}



int hacer_raizv2(int *cont,int *numero_array,int numero_parejas,int *resto,int *solucion,int *tam_resto,int *tam_sol)
{
    int cuadrado, *doble_solucion, n,tam_doble_solucion,i=0,j;

    doble_solucion= (int*) malloc(sizeof(int)*1000000000);


    if(*cont==0){

        printf("\nCont1:%d\n", *cont);
        
        //caso trivial

        printf("\nnumero_array: %d\n", numero_array[*cont]);
        printf("\nresto: %d\n",resto[0]);

        resto[0]=numero_array[*cont];

        printf("!!!\n");

        //fprintf(stderr,"\nresto:%d\n", resto[0]);
        solucion[0]=busca_cercano(resto[0]);
        *tam_sol=*tam_sol+1;
        
        //fprintf(stderr,"\nresto:%d\n", resto[0]);


      // fprintf(stderr,"\nsolucion:%d\n", solucion[0]);
        cuadrado = calcula_cuadrado(solucion[0]);
        //fprintf(stderr,"\nsolucion:%d\n", solucion[0]);

      // fprintf(stderr,"\ncuadrado:%d\n", cuadrado);

         
        resto[0]=resto[0]-cuadrado;

        
        *tam_resto=*tam_resto+1;

        if(resto[0]==0)
        {
            *tam_resto=*tam_resto=*tam_resto-1;
        }
        
        
        
        fprintf(stderr,"\nresto: %d\nsolucion: %d\n", resto[0],solucion[0]);

        *cont=*cont+1;
        return 1;

    }  
    else{
        printf("cont2:%d\n",*cont);
        *cont=*cont-1;

        hacer_raizv2(cont, numero_array,numero_parejas,resto,solucion,tam_resto,tam_sol);
        printf("cont4:%d\n",*cont);

        printf("\ntam_sol%d\n",*tam_sol);
        printf("\ntam_resto%d\n",*tam_resto);
        

        tam_doble_solucion=multiplicar_array(solucion,doble_solucion,*tam_sol,2);
        
        //resto= (int*) malloc(sizeof(int)*2);
        

        resto[*tam_resto]=numero_array[*cont]/10;
        *tam_resto=*tam_resto+1;
        resto[*tam_resto]=numero_array[*cont]%10;
        *tam_resto=*tam_resto+1;

        for(int i=0;i<*tam_resto;i++)
        {
            printf("\nRESTO: %d\n",resto[i]);
        }
        for(int i=0;i<*tam_sol;i++)
        {
            printf("\nSOL: %d\n",solucion[i]);
        }

        


        n= busca_n(doble_solucion,resto,tam_doble_solucion,*tam_resto);

        printf("\nBusca n%d\n",n);
        

        

        //solucion= (int*) malloc(sizeof(int)*1);
    

        

        solucion[*tam_sol]=n;
        *tam_sol=*tam_sol+1;

        doble_solucion[tam_doble_solucion]=n;
        tam_doble_solucion++;

        

        tam_doble_solucion=multiplicar_array(doble_solucion,doble_solucion,tam_doble_solucion,n);


        //printf("\n******resto: %d\n",*tam_resto);
        /*for(int i=0;i<tam_resto;i++){
            printf("\n******resto: %d\n",resto[i]);
        }

        for(int i=0;i<tam_doble_solucion;i++){
            printf("\n******Doble sol: %d\n",doble_solucion[i]);
        }*/


        resta_arrays(resto,doble_solucion,*tam_resto,tam_doble_solucion);


        while(resto[i]==0)
        {
            for(j=0;j<*tam_resto;j++)
            {
                resto[j]=resto[j+1];
            }
            *tam_resto=*tam_resto-1;
        }

         for(int i=0;i<*tam_resto;i++)
        {
            printf("\n----------RESTO---------: %d\n",resto[i]);
        }
        for(int i=0;i<*tam_sol;i++)
        {
            printf("\n-----------SOL---------: %d\n",solucion[i]);
        }
        printf("!!!\n");
        printf("cont3:%d\n",*cont);

        *cont=*cont+1;
         printf("cont3:%d\n",*cont);

        printf("!!!\n");
        
        return 1;        
        
    }

}


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

    resto= (int*) malloc(sizeof(int)*10000000);
    solucion= (int*) malloc(sizeof(int)*100000000);
    cont= malloc(sizeof(int)*1);

    tam_resto=  malloc(sizeof(int)*1);
    tam_sol=malloc(sizeof(int)*1);

    *tam_resto=0;
    *tam_sol=0;
    


    size_t size = strlen(argv[1]);

    int numero_parametro[size];
    int *numero_parametro2;

    //printf("\n%ld\n",size);
    //printf("\n%d\n",argv[1][0]-'0');


    for(int i=0;i<size;i++){
        numero_parametro[i]=argv[1][i]-'0';
    }
/*
    int array1[3]={1,4,5};
    int array2[3]={1,2,7};

    
    resta_arrays(array1,array2,3);

    for(int i=0;i<3;i++){
        printf("\nSol resta:%d\n",array1[i]);
    }
    

    int tam_sol=multiplicar_array(numero_parametro,solucion,size,5);

    for(int i=0;i<tam_sol+1;i++){
        printf("\n%d\n",solucion[i]);
    }
*/
    presentacion();
    fprintf (stdout, "Se procede al calculo.\n");

    numero_parametro2 = (int*) malloc(sizeof(int)*size);

    printf("!!!\n");
    divide_dos_en_dos(numero_parametro2, numero_parametro,size);

    
    printf("!!!\n");

    if(size%2!=0){
        size=size/2+1;
    }
    else{
        size=size/2;
    }

     printf("Size:%ld\n",size);
    for(int i=0;i<size;i++){
        printf("\n%d---\n",numero_parametro2[i]);
    }
    
    *cont=(int) size-1;
    
    printf("Cont main: %d\n", *cont);
    

    hacer_raizv2(cont, numero_parametro2,size,resto,solucion,tam_resto,tam_sol);

    
 
    printf("Cont main2: %d\n", *cont);

    mostrar_solucion(resto,solucion,tam_resto,tam_sol);



}



