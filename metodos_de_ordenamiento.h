/*
 * Prototipos
 */

// Metodos principales
int metodoDeBurbuja(int ordenVector, int vector[]);
int metodoDeInsercion(int ordenVector, int vector[]);
int metodoDeSeleccion(int ordenVector, int vector[]);
int metodoRapido(int ordenVector, int vector[]);
int metodoDeMezcla(int ordenVector, int vector[]);

// Metodos adicionales
int obtenerMezcla(int vector[], int p, int r);
int ordenarMezcla(int vector[], int p, int q, int r);
void ordernarParticiones(int vector[], int menor, int mayor);
int obtenerPivote(int vector[], int menor, int mayor);
int clonarVector(int ordenVector, int vector[], int nuevoVector[]);
void mostrarVector(int ordenVector, int vector[]);

/*
 * Definiciones
 */

int metodoDeBurbuja(int ordenVector, int vector[]) {
    int aux, bandera, nuevoVector[100];
    clonarVector(ordenVector, vector, nuevoVector);

    do {
        bandera = 0;

        for (int i = 0; i < ordenVector; i++) {
            if (nuevoVector[i] > nuevoVector[i + 1]) {
                aux = nuevoVector[i];
                nuevoVector[i] = nuevoVector[i + 1];
                nuevoVector[i + 1] = aux;
                bandera = 1;
            }
        }
    } while (bandera == 1);

    printf("Vector original: \n");
    mostrarVector(ordenVector, vector);

    printf("Vector ordenado: \n");
    mostrarVector(ordenVector, nuevoVector);
}

int metodoDeInsercion(int ordenVector, int vector[]) {
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

int metodoDeSeleccion(int ordenVector, int vector[]) {
    int minimo = 0, i, j, temporal, nuevoVector[100];
    clonarVector(ordenVector, vector, nuevoVector);

    for (i = 0; i < ordenVector - 1; i++) {
        minimo = i;

        for (j = i + 1; j < ordenVector; j++) {
            if (nuevoVector[minimo] > nuevoVector[j]) {
                minimo = j;
            }
        }

        temporal = nuevoVector[minimo];
        nuevoVector[minimo] = nuevoVector[i];
        nuevoVector[i] = temporal;
    }

    printf("Vector original: \n");
    mostrarVector(ordenVector, vector);

    printf("Vector ordenado: \n");
    mostrarVector(ordenVector, nuevoVector);
}

int metodoRapido(int ordenVector, int vector[]) {
    int nuevoVector[100];
    clonarVector(ordenVector, vector, nuevoVector);

    ordernarParticiones(nuevoVector, 0, ordenVector - 1);

    printf("Vector original: \n");
    mostrarVector(ordenVector, vector);

    printf("Vector ordenado: \n");
    mostrarVector(ordenVector, nuevoVector);
}

int metodoDeMezcla(int ordenVector, int vector[]) {
    int nuevoVector[100];
    clonarVector(ordenVector, vector, nuevoVector);

    obtenerMezcla(nuevoVector, 0, ordenVector - 1);

    printf("Vector original: \n");
    mostrarVector(ordenVector, vector);

    printf("Vector ordenado: \n");
    mostrarVector(ordenVector, nuevoVector);
}

int ordenarMezcla(int vector[], int p, int q, int r) {
    int n1, n2, i, j, k;

    n1 = q - p + 1;
    n2 = r - q;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = vector[p + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = vector[q + j + 1];
    }
    i = 0, j = 0;

    for (k = p; i < n1 && j < n2; k++) {
        if (L[i] < R[j]) {
            vector[k] = L[i++];
        } else {
            vector[k] = R[j++];
        }
    }

    while (i < n1) {
        vector[k++] = L[i++];
    }

    while (j < n2) {
        vector[k++] = R[j++];
    }
}

int obtenerMezcla(int vector[], int p, int r) {
    int q;

    if (p < r) {
        q = (p + r) / 2;
        obtenerMezcla(vector, p, q);
        obtenerMezcla(vector, q + 1, r);
        ordenarMezcla(vector, p, q, r);
    }
}

int obtenerPivote(int vector[], int menor, int mayor) {
    int i, pivote, valorPivote, temporal;
    pivote = menor;
    valorPivote = vector[pivote];

    for (i = menor + 1; i <= mayor; i++) {
        if (vector[i] < valorPivote) {
            pivote++;

            temporal = vector[i];
            vector[i] = vector[pivote];
            vector[pivote] = temporal;
        }
    }

    temporal = vector[menor];
    vector[menor] = vector[pivote];
    vector[pivote] = temporal;

    return pivote;
}

void ordernarParticiones(int vector[], int menor, int mayor) {
    if (menor < mayor) {
        int pivote = obtenerPivote(vector, menor, mayor);

        ordernarParticiones(vector, menor, pivote - 1);
        ordernarParticiones(vector, pivote + 1, mayor);
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