#include <stdio.h>

// Metodos de ordenamiento
int bubbleSort(int ordenVector, int vector[]);

int insertionSort(int ordenVector, int vector[]);

int selectionSort(int ordenVector, int vector[]);

int quickSort(int ordenVector, int vector[]);

int mergeSort(int A[], int p, int r);

// Metodos adicionales
int merge(int A[], int p, int q, int r);

int clonarVector(int ordenVector, int vector[], int nuevoVector[]);

void mostrarVector(int ordenVector, int vector[]);

int main() {
    int vector[100], ordenVector, metodoSeleccionado;

    printf("Ingrese el orden del vector\n");
    scanf("%d", &ordenVector);

    printf("Ingrese los valores del vector\n");

    for (int i = 0; i < ordenVector; i++) {
        scanf("%d", &vector[i]);
    }

    printf("===============================================================\n");
    printf("Ingrese el numero que correponde con el metodo de ordenamiento\n");
    printf("1. Intercambio o método burbuja mejorado.\n");
    printf("2. Inserción o método de la baraja\n");
    printf("3. Selección o método sencillo\n");
    printf("4. Rápido o QuickSort\n");
    printf("5. Por Mezcla o MergeSort\n");
    printf("===============================================================\n");

    scanf("%d", &metodoSeleccionado);

    switch (metodoSeleccionado) {
        case 1:
            bubbleSort(ordenVector, vector);
            break;
        case 2:
            insertionSort(ordenVector, vector);
            break;
        case 3:
            selectionSort(ordenVector, vector);
            break;
        case 4:
            quickSort(ordenVector, vector);
            break;
        case 5:
            printf("Vector original: \n");

            mostrarVector(ordenVector, vector);

            mergeSort(vector, 0, ordenVector - 1);

            printf("Vector ordenado: \n");

            mostrarVector(ordenVector, vector);
            break;
        default:
            printf("Debe ingresar una opción valida.\n");
    }

    return 0;
}

int bubbleSort(int ordenVector, int vector[]) {
    int aux, b, nuevoVector[100];
    clonarVector(ordenVector, vector, nuevoVector);

    do {
        b = 0;

        for (int i = 0; i < ordenVector; i++) {
            if (nuevoVector[i] > nuevoVector[i + 1]) {
                aux = nuevoVector[i];
                nuevoVector[i] = nuevoVector[i + 1];
                nuevoVector[i + 1] = aux;
                b = 1;
            }
        }
    } while (b == 1);

    printf("Vector original: \n");
    mostrarVector(ordenVector, vector);

    printf("Vector ordenado: \n");
    mostrarVector(ordenVector, nuevoVector);
}

int insertionSort(int ordenVector, int vector[]) {
    int nuevoVector[100];
    clonarVector(ordenVector, vector, nuevoVector);
    int i, a, index;

    for (i = 1; i < ordenVector; i++) {
        index = nuevoVector[i];
        a = i - 1;

        while (a >= 0 && nuevoVector[a] > index) {
            nuevoVector[a + 1] = nuevoVector[a];
            a--;
        }

        nuevoVector[a + 1] = index;
    }

    printf("Vector original: \n");
    mostrarVector(ordenVector, vector);

    printf("Vector ordenado: \n");
    mostrarVector(ordenVector, nuevoVector);
}

int selectionSort(int ordenVector, int vector[]) {
    // TODO: Agregar el correspondiente metodo
    return 0;
}

int quickSort(int ordenVector, int vector[]) {
    int nuevoVector[100];
    clonarVector(ordenVector, vector, nuevoVector);
    nuevoVector[2] = 2222;

    for (int i = 0; i < ordenVector; i++) {
        printf("ORIGINAL - vector[%d]", vector[i]);
        printf("NUEVO - nuevoVector[%d]\n", nuevoVector[i]);
    }
}

int merge(int A[], int p, int q, int r) {

    int n1, n2, i, j, k;

    n1 = q - p + 1;
    n2 = r - q;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }
    i = 0, j = 0;

    for (k = p; i < n1 && j < n2; k++) {
        if (L[i] < R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }

    while (i < n1) {
        A[k++] = L[i++];
    }

    while (j < n2) {
        A[k++] = R[j++];
    }
}

int mergeSort(int A[], int p, int r) {
    int nuevoVector[100];
    int q;

    clonarVector(r, A, nuevoVector);

    if (p < r) {
        q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int clonarVector(int ordenVector, int vector[], int nuevoVector[]) {
    for (int i = 0; i < ordenVector; i++) {
        nuevoVector[i] = vector[i];
    }
}

void mostrarVector(int ordenVector, int vector[]) {
    printf("[\n");

    for (int i = 0; i < ordenVector; i++) {
        printf("    %d => %d,\n", i, vector[i]);
    }

    printf("]\n");
}