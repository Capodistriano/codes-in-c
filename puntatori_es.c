#include <stdio.h>
#include <stdlib.h>

// defisinisco il nodo
struct node{
    int data;
    struct node *next;
};
// alias nodo
typedef struct node nodo; 

//funzione per stampare i nodi della lista
void stampalista(nodo *lista){
    while(lista != NULL){
        printf("%d->", lista->data);
        lista=lista->next;
    }
    printf("NULL\n");
}
//funzione per contare i nodi della lista
void conta(nodo *lista){
    int count=0;
    while(lista !=NULL){
        count++;
        lista=lista->next;
    }
    printf("Il numero di nodi nella lista è: %d\n", count);
}



int main(){
    // buona pratica inizializzare il primo membro a null onde evitare futuri problemi
    nodo *lista=NULL;
    int n;
    printf("Quale vuoi che sia il primo elemento della lista:");
    scanf("%d", &n);
    
    int u;
    printf("Quale vuoi sia l'ultimo elemento da raggiungere: ");
    scanf("%d", &u);
    // alloco memeoria al primo elemento della lista
    nodo *new= malloc(sizeof(nodo));
    new->data=n;
    lista=new;
    for(int i=n*2;i<=u;i*=2){
        new->next=malloc(sizeof(nodo));
        new=new->next;
        new->data=i;
    }
    new->next=NULL;

    printf("Lista:\n");
    stampalista(lista);
    printf("\n");

    conta(lista);

    //come liberare memoria
    nodo *temp;
    while(lista !=NULL){
        temp=lista;
        lista= lista->next;
        free(temp);
    }
    return 0;
}
