#include <stdio.h>
#include <stdlib.h>

void aniadir(int **arr, int index, int value, int *tamanio, int *capacidad){
  int *temp;
  if(*tamanio >= *capacidad){
    temp=(int *) malloc((*capacidad)*2*sizeof(int));
    if(temp==NULL){
      printf("Ayuda por favor");
    }
    for(int i=0;i<*capacidad;i++){
      *(temp+i)=*(*arr+i);
    }
    free(*arr);
    *arr=temp;
    *capacidad = (*capacidad) * 2;
  }
  *(*arr+index)=value;
  *tamanio = *tamanio + 1;
}
int main(){
  int tamanio = 0;
  int n=0;
  int capacidad = 2;
  int *arr = malloc(2 * sizeof(int));
  printf("Ingrese cuantos números quiere imprimir: ");
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    aniadir(&arr,i,i+1,&tamanio,&capacidad);
    for(int j=0;j<tamanio;j++){
      printf("%d ",*(arr+j));
    }
    printf("\n");
  }
}