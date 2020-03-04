#include <stdio.h>
#include <stdlib.h> 

struct Circular{
	int dato;
	struct Circular *siguiente;
};

void mostrar(struct Circular * lista);

struct Circular * crear(int dato){
	struct Circular *nueva=NULL;
	nueva=(struct Circular *) malloc(sizeof(struct Circular));
	if(nueva==NULL){
		return NULL;
	}
	nueva->dato=dato;
	nueva->siguiente=nueva;
	return nueva;
} 

struct Circular * insertar(struct Circular *lista, int dato){
	struct Circular *nueva=crear(dato);
  struct Circular *inicio=lista;
	nueva->siguiente=inicio;
  while(lista->siguiente!=inicio){
    lista=lista->siguiente;
  }
  lista->siguiente=nueva;
	return nueva;
}

struct Circular * invertir(struct Circular *lista){
  struct Circular *actual=lista;
  struct Circular *siguiente=NULL;
  struct Circular *anterior=NULL;
  do{
    siguiente=actual->siguiente;
    actual->siguiente=anterior;
    anterior=actual;
    actual=siguiente;
    
  }
  while(actual!=lista);
  lista->siguiente=anterior;
  lista=anterior;
  return lista;
}

void mostrar(struct Circular *lista){
  struct Circular *inicio=lista;
  do{
    printf("%d ",lista->dato);
    lista=lista->siguiente;
  }while(lista!=inicio);
  
	printf("\n");
}	

int main(void){
	struct Circular *miLista=crear(10);
	if(miLista==NULL){
		printf("No se pudo crear la lista\n");
		return -1;
	}
	miLista=insertar(miLista,12);
	miLista=insertar(miLista,27);
	miLista=insertar(miLista,2020);
	miLista=insertar(miLista,1);
	mostrar(miLista);
  miLista=invertir(miLista);
  mostrar(miLista);
	return 0;
}