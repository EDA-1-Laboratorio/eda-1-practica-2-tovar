#include <stdio.h>

void invertirCadena(char *inicio) {
    char *fin = inicio;
    char aux;

    while (*fin != '\0') {
        fin++;
    }
    fin--;

    while (inicio < fin) {
        aux = *inicio;
        *inicio = *fin;
        *fin = aux;

        inicio++;
        fin--;
    }
}

int main() {
    char palabra[] = "APUNTADORES";
    printf("Original: %s\n", palabra);
    invertirCadena(palabra);
    printf("Invertida: %s\n", palabra);
    return 0;
}

//Durante el ciclo de intercambio (swap), la condición de parada es while (inicio < fin). 
//Explica detalladamente qué es lo que se está comparando físicamente en esa instrucción (¿valores o direcciones?) 
// y qué sucedería si la condición fuera while (*inicio != *fin).
//RESPUESTA:En while (inicio < fin) se están comparando direcciones de memoria, no los caracteres.
//Como inicio y fin son apuntadores, el operador < verifica cuál está antes en memoria. El ciclo continúa mientras no se hayan cruzado, a
//segurando que el intercambio se haga correctamente desde los extremos hacia el centro.
//Si fuera while (*inicio != *fin), entonces se compararían los valores (los caracteres). Eso sería incorrecto porque si hay letras iguales
//en posiciones opuestas (por ejemplo en "ANA"), el ciclo podría detenerse antes de tiempo y la cadena no se invertiría bien.
