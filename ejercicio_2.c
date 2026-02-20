#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 5
#define COLS 5

int main() {
    int matriz[FILAS][COLS];
    int *ptr = &matriz[0][0];
    int *max1 = ptr; // Apuntador al valor más grande
    int *max2 = ptr; // Apuntador al segundo valor más grande
    int total = FILAS * COLS;

    srand(time(NULL));

    // 1. Llenado y visualización
    printf("--- MATRIZ DE BUSQUEDA ---\n");
    for (int i = 0; i < total; i++) {
        *(ptr + i) = rand() % 100;
        printf("%d\t", *(ptr + i));
        if ((i + 1) % COLS == 0) printf("\n");
    }

    // 2. Lógica de búsqueda con dos apuntadores
    // Inicializamos max2 al segundo elemento para evitar comparar contra el mismo sitio al inicio
    max2 = (ptr + 1);
    
    // Asegurar que max1 apunte al mayor de los dos primeros
    if (*max2 > *max1) {
        int *temp = max1;
        max1 = max2;
        max2 = temp;
    }

    for (int i = 2; i < total; i++) {
        int *actual = (ptr + i);
        
        // --- TU CÓDIGO AQUÍ ---
        // Caso A:
         if (*actual > *max1) {
            max2 = max1;   // el anterior máximo pasa a ser segundo máximo
            max1 = actual; // el nuevo máximo es el actual
        }
        // Caso B: 
        else if (*actual > *max2) {
            max2 = actual; // se actualiza solo el segundo máximo
        }
       
    // 3. Cálculo de distancia
    // La resta de apuntadores da la distancia en número de elementos
    long distancia = (max1 > max2) ? (max1 - max2) : (max2 - max1);

    printf("\n--- REPORTE DE MEMORIA ---");
    printf("\n1er Maximo: %d en la direccion %p", *max1, (void*)max1);
    printf("\n2do Maximo: %d en la direccion %p", *max2, (void*)max2);
    printf("\nDistancia entre ellos: %ld elementos de tipo int", distancia);
    printf("\nDistancia en bytes: %ld bytes\n", distancia * sizeof(int));

    return 0;
}

// PREGUNTA: Si el max1 se encuentra en la dirección 0x100 y el max2 en la 0x108,
// y estamos trabajando con enteros (int) de 4 bytes, 
// ¿qué valor numérico devolverá la operación max2 - max1 y por qué no devuelve simplemente 8?
//La operación max2 - max1 devuelve 2, porque la resta de apuntadores en C se expresa en número 
//de elementos del tipo apuntado (int), no en bytes. Como entre 0x100 y 0x108 hay 8 bytes y cada
//int ocupa 4 bytes, el resultado es 8 / 4 = 2.
