// Programa que pasa los parametros introducidos a un vector de enteros de tamanio igual al de elementos introducidos
// EJMEPLO ./test 45234354354354
//         ./test 12345678908774589652145236985412
#include <stdlib.h>
#include <stdio.h>



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
    fprintf(stdout, "El valor de k es: %d\n", k);
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
        printf("El valor de array_numero[%d] es: %d\n", j, array_numero[j]);

        //Incrementamos el contador
        i++;
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




int main (int argc, char *argv[]){
    int i=0, j=0, k=0, *array_numero, tam_array, n1, n2, numero_temporal;


    fprintf(stdout, "+++++++++++++++++++++++++\n");
    
    //Vemos la longitud del numero introducido
    tam_array = comprueba_tam_numero(argv);

    //Reservamos memoria para el array
    array_numero = (int*) malloc(sizeof(int)*tam_array);

    //Convertimos el string a un array de enteros
    string_a_array_enteros(argv, array_numero, tam_array);

    //Imprimimos el valor de array_numero
    imprime_vector(array_numero, tam_array);



    

}