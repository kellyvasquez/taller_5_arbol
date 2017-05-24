#include <stdio.h>
#include <stdlib.h>
#define reservar_memoria (nodo*)malloc(sizeof(nodo))

struct nodo{
    int dato;
    nodo *izq;
    nodo *der; };

nodo *arbol=NULL;

void menu();
nodo *CrearNodo(int);
void InsertarNodo(nodo *&,int);
bool buscar_nodo(nodo *,int);
void mostrarArbol(nodo *, int);
void mostrar_preorden(nodo *);
void mostrar_inorden(nodo *);
void mostrar_posorden(nodo *);
void editarNodo(nodo *&,int);

int main(){
    menu();
}

void menu(){
    int opc,contador=0, a;
    char c;

    printf("\n ***** ARBOL BINARIO DE BUSQUEDA ***** \n\n");
    printf(" 1. Insertar elementos.\n");
    printf(" 2. Editar un nodo.\n");
    printf(" 3. Buscar un nodo.\n");
    printf(" 4. eliminar un nodo.\n");
    printf(" 5. Mostrar arbol completo.\n");
    printf(" 6. Mostrar en Preorden.\n");
    printf(" 7. Mostrar en Postorden.\n");
    printf(" 8. Mostrar en Inorden.\n");
    printf(" 0. Salir.\n");
    printf("Digite opcion: "); scanf("%d",&opc);

    switch(opc){

        case 0:
            exit(0);
            break;

        case 1:
            do{
                printf("Ingrese dato: "); scanf("%s",&c);
                int convertir=c;
                if(convertir>=62 && convertir<=90 || convertir>=97 && convertir<=122){
                    if(convertir>90){
                        convertir=convertir-32;
                    }
                    InsertarNodo(arbol,convertir);
                }else{
                    printf("Caracter ingresado no valido\n");
                }
                printf("Desea ingresar mas datos 1.SI  2.NO: ");
                scanf("%d",&a);
            }while(a!=2);
        break;

        case 2:
            system("cls");

            break;

        case 3:{
            printf("Ingrese dato que desea buscar: ");
            scanf("%s",&c);
            int convertir=c;
            if(convertir>=65 && convertir<=90 || convertir>=97 && convertir<=122){
                if(convertir>90){
                    convertir=convertir-32;
                }
                if(buscar_nodo(arbol,convertir)==true){
                    printf("Elemento encontrado\n");
                }else{
                    printf("Elemento no encontrado\n");
                }
            }else{
                printf("Caracter ingresado no valido\n");
            }
            system("pause");
        }break;

        case 4:{
            printf("Ingrese dato que desea modificar: ");
            scanf("%s",&c);
            int conver=c;
            if(conver>=62 && conver<=90 || conver>=97 && conver<=122){
                if(conver>90){
                    conver=conver-32;
                }
                editarNodo(arbol,conver);
            }else{
                printf("Caracter ingresado no es valido\n");
            }
        }break;

        case 5:
            printf("\n Mostrando el arbol completo: \n\n");
            mostrarArbol(arbol, contador);
            printf("\n");
            system("pause");
            break;
    }
    menu();
}

/**FUNCIÓN PARA CREAR UN NUEVO NODO**/
nodo *CrearNodo(int n){
    nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo->dato = n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;

    return nuevo_nodo;
}

/**FUNCION PARA INSERTAR ELEMENTOS EN EL ARBOL**/
void InsertarNodo(nodo *&arbol, int n){
    if(arbol == NULL){ /**SI EL ARBOL ESTÁ VACIO**/
        nodo *nuevo_nodo = CrearNodo(n);
        arbol = nuevo_nodo;
    }else{ /**SI EL ARBOL TIENE UN NODO O MÁS**/
        int valorRaiz = arbol->dato;
        if(n < valorRaiz){
            InsertarNodo(arbol->izq,n);
        }else{
            InsertarNodo(arbol->der,n); }
    }
}

bool buscar_nodo(nodo *arbol, int n){
    if(arbol==NULL){
        return false;
    }else if(arbol->dato==n){
        return true;
    }else if(n<arbol->dato){
        return buscar_nodo(arbol->izq,n);
    }else{
        return buscar_nodo(arbol->der,n);
    }
}

/**FUNCIÓN PARA MOSTRAR ARBOL COMPLETO**/
void mostrarArbol(nodo *arbol, int cont){
    if(arbol == NULL){ //Si el arbol esta vacio
        return;
    }else{
        mostrarArbol(arbol->der,cont+1);
        for(int i=0; i<cont; i++){
            printf("    ");
        }
        printf(" ", arbol->dato);
        mostrarArbol(arbol->izq, cont+1);
    }
}

void mostrar_preorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        char convertir=arbol->dato;
        printf("%c ",convertir);
        mostrar_preorden(arbol->izq);
        mostrar_preorden(arbol->der);
    }
}

void mostrar_inorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_inorden(arbol->izq);
        char convertir=arbol->dato;
        printf("%c ",convertir);
        mostrar_inorden(arbol->der);
    }
}

void mostrar_posorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_posorden(arbol->izq);
        mostrar_posorden(arbol->der);
        char convertir=arbol->dato;
        printf("%c ",convertir);
    }
}

void editarNodo(nodo *&arbol, int n){
    char c;
    if(arbol==NULL){
        return;
    }else if(arbol->dato==n){
        printf("Ingrese nuevo dato: ");
        scanf("%s",&c);
        int convertir=c;
        if(convertir>=65 && convertir<=90 || convertir>=97 && convertir<=122){
            if(convertir>90){
                convertir=convertir-32;
            }
            arbol->dato=convertir;
        }else{
            printf("Caracter ingresado no valido\n");
        }
        return;
    }else if(n<arbol->dato){
        return editarNodo(arbol->izq,n);
    }else{
        return editarNodo(arbol->der,n);
    }
}
