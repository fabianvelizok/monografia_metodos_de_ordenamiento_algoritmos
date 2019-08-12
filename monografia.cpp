#include <stdio.h>
#include "metodos_de_ordenamiento.h"

void cargarVector(int vector[], int &ordenVector);
void imprimirMetodosYSeleccionar(int &metodoSeleccionado);
void ejecutarMetodoSeleccionado(int metodoSeleccionado, int vector[], int ordenVector);

int main() {
    int vector[100], ordenVector, metodoSeleccionado;

    cargarVector(vector, ordenVector);

    imprimirMetodosYSeleccionar(metodoSeleccionado);

    ejecutarMetodoSeleccionado(metodoSeleccionado, vector, ordenVector);

    return 0;
}

void cargarVector(int vector[], int &ordenVector) {
    printf("Ingrese el orden del vector\n");
    scanf("%d", &ordenVector);

    printf("Ingrese los valores del vector\n");

    for (int i = 0; i < ordenVector; i++) {
        scanf("%d", &vector[i]);
    }
}

void imprimirMetodosYSeleccionar(int &metodoSeleccionado) {
    printf("===============================================================\n");
    printf("Ingrese el numero que correponda con el metodo de ordenamiento:\n");
    printf("1. Intercambio o método burbuja mejorado.\n");
    printf("2. Inserción o método de la baraja\n");
    printf("3. Selección o método sencillo\n");
    printf("4. Rápido o QuickSort\n");
    printf("5. Por Mezcla o MergeSort\n");
    printf("===============================================================\n");

    scanf("%d", &metodoSeleccionado);
}

void ejecutarMetodoSeleccionado(int metodoSeleccionado, int vector[], int ordenVector) {
    switch (metodoSeleccionado) {
        case 1:
            metodoDeBurbuja(ordenVector, vector);
            break;
        case 2:
            metodoDeInsercion(ordenVector, vector);
            break;
        case 3:
            metodoDeSeleccion(ordenVector, vector);
            break;
        case 4:
            metodoRapido(ordenVector, vector);
            break;
        case 5:
            metodoDeMezcla(ordenVector, vector);
            break;
        default:
            printf("Debe ingresar una opción válida.\n");
    }
}