#include <stdio.h>

/* TODO: Mover metodos a la libreria */
int bubbleSort(int ordenVector, int vector[]);
int insertionSort(int ordenVector, int vector[]);
int selectionSort(int ordenVector, int vector[]);
int quickSort(int ordenVector, int vector[]);
int mergeSort(int ordenVector, int vector[]);

int clonarVector(int ordenVector, int vector[], int nuevoVector[]);

int main() {
  int vector[100], ordenVector, metodoSeleccionado;

  printf("Ingrese el orden del vector\n");
  scanf("%d", &ordenVector);

  printf("Ingrese los valores del vector\n");

  for(int i = 0; i < ordenVector; i++) {
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

  switch(metodoSeleccionado) {
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
      mergeSort(ordenVector, vector);
      break;
    default:
      printf("Debe ingresar una opción valida.\n");
  }

  return 0;
}

int bubbleSort(int ordenVector, int vector[]) {
  // TODO: Agregar el correspondiente metodo
  return 0;
}

int insertionSort(int ordenVector, int vector[]) {
  int nuevoVector[100]; 
  clonarVector(ordenVector, vector, nuevoVector);
  int i, a, index;
  
  for (i=1; i < ordenVector; i++){
    index = nuevoVector[i];
    a = i-1;
    
    while (a >= 0 && nuevoVector[a] > index) {
      nuevoVector[a + 1] = nuevoVector[a];
      a--;
    }
    nuevoVector[a+1] = index;
    
  }
  
  	printf("ORIGINAL - [");
	for(int i=0;i<ordenVector;i++){
		printf("%d,",vector[i]);
	}
	printf("]\n");
	
	printf("NUEVO - [");
	for(int i=0;i<ordenVector;i++){
		printf("%d,",nuevoVector[i]);
	}
	printf("]\n");
}

int selectionSort(int ordenVector, int vector[]) {
  // TODO: Agregar el correspondiente metodo
  return 0;
}

int quickSort(int ordenVector, int vector[]) {
  int nuevoVector[100]; 
  clonarVector(ordenVector, vector, nuevoVector);
  nuevoVector[2] = 2222;

  for(int i = 0; i < ordenVector; i++) {
    printf("ORIGINAL - vector[%d]", vector[i]);
    printf("NUEVO - nuevoVector[%d]\n", nuevoVector[i]);
  }
}

int mergeSort(int ordenVector, int vector[]) {
  // TODO: Agregar el correspondiente metodo
  return 0;
}

int clonarVector(int ordenVector, int vector[], int nuevoVector[]) {
  for(int i = 0; i < ordenVector; i++) {
    nuevoVector[i] = vector[i];
  }
}