#include <stdio.h>
#include <stdlib.h> 

struct Doble{
	int dato;
	struct Doble *siguiente;
  struct Doble *anterior;
};

struct Doble * crear(int dato){
	struct Doble *nueva=NULL;
	nueva=(struct Doble *) malloc(sizeof(struct Doble));
	if(nueva==NULL){
		return NULL;
	}
	nueva->dato=dato;
	nueva->siguiente=NULL;
	return nueva;
} 

struct Doble * insertar(struct Doble *lista, int dato){
	struct Doble *nueva=crear(dato);
	nueva->siguiente=lista;
  lista->anterior=nueva;
	return nueva;
}

struct Doble * invertir(struct Doble *lista){
  struct Doble *temporal=NULL;
  do{
    temporal=lista->siguiente;
    lista->siguiente=lista->anterior;
    lista->anterior=temporal;
    if(temporal!=NULL){
      lista=temporal;
    }
  }
  while(temporal!=NULL);
  return lista;
}

void mostrar(struct Doble *lista){
  while(lista!=NULL){
		printf("%d ",lista->dato);
		lista=lista->siguiente;
	}
	printf("\n");
}	

int main(void){
	struct Doble *miLista=crear(10);
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