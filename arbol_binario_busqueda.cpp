#include <stdio.h>
#include <stdlib.h>
#define reservar_memoria (nodo*)malloc(sizeof(nodo))

/**ARBOL BINARIO DE BUSQUEDA - LETRAS**/

struct nodo{
    int dato;
    nodo *izq;
    nodo *der; };

nodo *arbol=NULL;

void menu();
nodo *CrearNodo(int);
void InsertarNodo(nodo *&,int);
bool buscar_nodo(nodo *,int);
void mostrar_preorden(nodo *);
void mostrar_inorden(nodo *);
void mostrar_posorden(nodo *);
void editarNodo(nodo *&,int);

int main(){
    menu();
}

void menu(){
    int opc;
    char car;

    printf("\n ***** ARBOL BINARIO DE BUSQUEDA ***** \n\n");
    printf(" 1. Insertar elementos.\n");
    printf(" 2. Editar un nodo.\n");
    printf(" 3. Buscar un nodo.\n");
    printf(" 4. eliminar un nodo.\n");
    printf(" 5. Mostrar arbol en Preorden.\n");
    printf(" 6. Mostrar arbol en Postorden.\n");
    printf(" 7. Mostrar arbol en Inorden.\n");
    printf(" 0. Salir.\n");
    printf("Digite opcion: "); scanf("%d",&opc);

    switch(opc){

        case 0: /**  SALIR DEL MENU     **/
            exit(0);
            break;

        case 1:     /**  INSERTAR ELEMENTOS EN EL ARBOL     **/
            do{
                printf("\n\n Ingrese caracter: "); scanf("%s",&car);
                int convertir=car;
                if(convertir>=62 && convertir<=90 || convertir>=97 && convertir<=122){
                    if(convertir>90){
                        convertir=convertir-32;
                    }
                    InsertarNodo(arbol,convertir);
                }else{
                    printf("\n\n El caracter ingresado no es valido. \n");
                }
                printf("\n Desea ingresar mas datos 1.SI  2.NO: ");
                scanf("%d",&opc);
            }while(opc!=2);
        break;

        case 2:  {   /**  EDITAR ELEMENTOS DEL ARBOL     **/
            printf("\n  Ingrese el dato que desea editar: "); scanf("%s",&car);
            int conver=car;
            if(conver>=62 && conver<=90 || conver>=97 && conver<=122){
                if(conver>90){
                    conver=conver-32;
                }
                editarNodo(arbol,conver);
            }else{
                printf("\n\n El caracter ingresado no es valido. \n");
            }
        }break;


        case 3:{    /**  BUSCAR ELEMENTOS DEL ARBOL     **/
            printf("\n\n    Ingrese el dato que desea buscar: "); scanf("%s",&car);
            int convertir=car;
            if(convertir>=62 && convertir<=90 || convertir>=97 && convertir<=122){
                if(convertir>90){
                    convertir=convertir-32;
                }
                if(buscar_nodo(arbol,convertir)==true){
                    printf("\n\n El caracter se encuentra en el arbol.\n");
                }else{
                    printf("\n\n El caracter no se encuentra en el arbol.\n"); }
            }else{
                printf("\n\n El caracter ingresado no es valido. \n"); }
        }break;

        case 4:     /**  ELIMINAR ELEMENTOS DEL ARBOL     **/
            break;

        case 5:     /**  IMPRIMIR LOS ELEMENTOS DEL ARBOL EN PREORDEN    **/
            printf("\n\n  MOSTRANDO ARBOL EN PREORDEN:     \n\n");
            mostrar_preorden(arbol);
            break;

        case 6:     /**  IMPRIMIR LOS ELEMENTOS DEL ARBOL EN POSTORDEN    **/
            printf("\n\n  MOSTRANDO ARBOL EN POSTORDEN:     \n\n");
            mostrar_posorden(arbol);
            break;

        case 7:     /**  IMPRIMIR LOS ELEMENTOS DEL ARBOL EN INORDEN    **/
            printf("\n\n  MOSTRANDO ARBOL EN INORDEN:     \n\n");
            mostrar_inorden(arbol);
            break;

    }
    menu();
}

/**     FUNCIÓN PARA CREAR UN NUEVO NODO        **/
nodo *CrearNodo(int n){
    nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo->dato = n;
    nuevo_nodo->izq = NULL;
    nuevo_nodo->der = NULL;

    return nuevo_nodo;
}

/** 1..      INSERTAR ELEMENTOS EN EL ARBOL     **/
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

/**  2..   EDITAR ELEMENTOS DEL ARBOL     **/
void editarNodo(nodo *&arbol, int n){
    char car;
    if(arbol==NULL){
        return;
    }else if(arbol->dato==n){
        printf("\n  Ingrese el nuevo dato: "); scanf("%s",&car);
        int convertir=car;
        if(convertir>=62 && convertir<=90 || convertir>=97 && convertir<=122){
            if(convertir>90){
                convertir=convertir-32;
            }
            arbol->dato=convertir;
        }else{
            printf("\n\n El caracter ingresado no es valido. \n");
        }
        return;
    }else if(n<arbol->dato){
        return editarNodo(arbol->izq,n);
    }else{
        return editarNodo(arbol->der,n);
    }
}

/**  3..   BUSCAR ELEMENTOS EN EL ARBOL     **/
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



/**  5..   MOSTRAR ARBOL COMPLETO EN PREORDEN     **/
void mostrar_preorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        char convertir=arbol->dato;
        printf(" %c ",convertir);
        mostrar_preorden(arbol->izq);
        mostrar_preorden(arbol->der);
    }
}

/** 6..    MOSTRAR ARBOL COMPLETO EN INORDEN     **/
void mostrar_inorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_inorden(arbol->izq);
        char convertir=arbol->dato;
        printf(" %c ",convertir);
        mostrar_inorden(arbol->der);
    }
}

/** 7..    MOSTRAR ARBOL COMPLETO EN POSTORDEN     **/
void mostrar_posorden(nodo *arbol){
    if(arbol==NULL){
        return;
    }else{
        mostrar_posorden(arbol->izq);
        mostrar_posorden(arbol->der);
        char convertir=arbol->dato;
        printf(" %c ",convertir);
    }
}
