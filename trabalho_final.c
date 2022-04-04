#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct product{
    int code,qntd;
    char name[30];
    float price;
    struct product *next,*prev;
};
typedef struct product Product;
struct lproduct{
    Product *head,*last;
};
typedef struct lproduct LProduct;

void init_list(LProduct *produto){
    produto->head=NULL;
    produto->last=NULL;
}
Product *search_id(LProduct *produto, int id){
    for(Product *aux = produto->head;aux != NULL; aux = aux->next){
        if(aux->code == id){
            return aux;
        }
    }
    return NULL;
}


void delete_product(LProduct *produto, int code){
    Product *aux = search_id(produto,code);
    if (aux !=NULL){
        aux->prev->next = aux->next;
        aux->next->prev = aux->prev;
        free(aux);
    }

}

void create_product(LProduct *produto){
    int code,qntd;
    float price;
    char name[30];
    do{
        printf("CODE:");
        scanf("%d",&code);
    } while (search_id(produto,code));

    printf("NAME:");
    scanf("%s",name);
    printf("PRICE:");
    scanf("%f",&price);
    printf("QUANTIDADE:");
    scanf("%d",&qntd);
    Product *aux = (Product *) malloc(sizeof(Product));
    aux->next= NULL;
    aux->prev= NULL;
    aux->code = code;
    strcpy(aux->name,name);
    aux->price = price;
    aux->qntd = qntd;
    if(produto->head == NULL){
        produto->head = aux;
        produto->last = aux;
    }
    else{
        aux->prev = produto->last;
        produto->last->next = aux;
        produto->last = aux;
    }
}

void print_list(LProduct *produto, Product *unico_print){
    printf("----------------------\n");
    Product *aux = produto->head;
    if(unico_print){aux = unico_print;}
    for(; aux!=NULL; aux = aux->next){
        printf("CODE:%d\n",aux->code);
        printf("NAME:%s\n",aux->name);
        printf("PRICE:%.2f\n",aux->price);
        printf("QUANTIDADE:%d\n",aux->qntd);
        printf("----------------------\n");
        if(unico_print){break;}
    }
}

void shop(LProduct *produtos){
    LProduct carrinho;
    Product *aux;
    int code_product;
    init_list(&carrinho);
    scanf("%d",&code_product);
    aux = search_id(produtos,code_product);
    // ToDo
}

int main() {
    int opcao;
    LProduct produtos;
    init_list(&produtos);
    while(TRUE){
        scanf("%d",&opcao);
        if(opcao == -1){break;}
        else if(opcao == 1){create_product(&produtos);}
        else if(opcao == 2){print_list(&produtos,NULL);}
        else if(opcao == 3){
            int id; scanf("%d",&id);
            Product *aux = search_id(&produtos,id);
            if(!aux){
                print_list(&produtos,aux);
            }
        }
        else if(opcao == 4){
            int id; scanf("%d",&id);
            delete_product(&produtos,id);
        }
        else if(opcao == 5){
           

        }
    }
    return 0;
}
