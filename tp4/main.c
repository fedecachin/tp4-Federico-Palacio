#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[20];
    char sexo;
    int edad;
} ePersona;

void mostrarPersona(ePersona* p);
void mostrarPersonas(LinkedList* list);

int main()
{
    LinkedList* lista = ll_newLinkedList();
    LinkedList* cloneLista = NULL;

    ePersona p1 = {2000, "jorge",'m', 30};
    ePersona p2 = {2001, "daniel",'m', 28};
    ePersona p3 = {2002, "maria",'f', 18};
    ePersona p4 = {2003, "susana",'f', 54};
    ePersona p5 = {2006, "muriel",'f', 46};


    ll_add(lista, &p1);
    ll_add(lista, &p2);
    ll_add(lista, &p3);
    ll_add(lista, &p4);

    mostrarPersonas(lista);

    ll_set(lista, 3, &p5);

    mostrarPersonas(lista);

    ll_remove(lista, 3);

   mostrarPersonas(lista);

    ll_push(lista, 2, &p4);

    mostrarPersonas(lista);

    cloneLista = ll_clone(lista);

    printf("lista clonada\n");
    mostrarPersonas(cloneLista);
    printf("lista original\n");
    mostrarPersonas(lista);

    if(ll_containsAll(lista, cloneLista))
    {
        printf("todos los elementos de la clonelista estan contenidos en la lista");
    }

    if(!ll_clear(cloneLista))
    {
        printf("elemntos de la lista clonada eliminados");
    }
    if(ll_isEmpty(cloneLista))
    {
        printf("lista clonada vacia");
    }

    if(!ll_deleteLinkedList(cloneLista))
    {
        printf("lista clonada eliminada");
    }

    return 0;
}

void mostrarPersona(ePersona* p)
{
    if(p!=NULL)
    {
        printf("%d  %10s   %c    %d\n", p->id, p->nombre, p->sexo, p->edad);
    }


}

void mostrarPersonas(LinkedList* list)
{
    int tam;
    if(list!=NULL)
    {
        tam = ll_len(list);
        printf("id         nombre sexo edad\n");
        for(int i = 0; i<tam; i++)
        {
            mostrarPersona((ePersona*) ll_get(list, i));
        }
        printf("\n\n");
    }
}
