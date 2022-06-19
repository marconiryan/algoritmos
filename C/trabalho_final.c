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
        if(aux == produto->head){
            produto->head = aux->next;
            if(produto->head){
                produto->head->prev = NULL;
            }
        }
        else if(aux == produto->last){
            aux->prev->next = NULL;
            produto->last = aux->prev;
        }
        else{
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
        }
        free(aux);
    }
}

void create_product(LProduct *produto, int code, int qntd, float price, const char name[30]){
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

void shop(LProduct *produtos,LProduct *carrinho,int code, int quantidade){
    Product *compra_carrinho = search_id(carrinho,code);
    Product *produto_atual = search_id(produtos,code);
    if(produto_atual){
        if (produto_atual->qntd >= quantidade){
        if(!compra_carrinho){
            create_product(carrinho,code,quantidade,produto_atual->price * (float)quantidade,produto_atual->name);
        }
        else{
           compra_carrinho->qntd +=  quantidade;
           compra_carrinho->price += (float) quantidade * produto_atual->price;
        }
        produto_atual->qntd = produto_atual->qntd - quantidade;
    }
        else{
            printf("Quantidade insuficiente no estoque!\n");
        }
    }
    else{
        printf("Produto Não encontrado!\n");
    }
}

void tirar_carrinho(LProduct *produtos, LProduct *carrinho, int code){
    Product *devolver = search_id(carrinho,code);
    if(devolver){
        Product *estoque = search_id(produtos,code);
        estoque->qntd += devolver->qntd;
        printf("O produto %s foi devolvido ao estoque!\n",estoque->name);
        delete_product(carrinho,code);
    }
}

void limpar(LProduct *lista){
    Product *aux = lista->head;
    while (aux != NULL){
        aux = aux->next;
        free(lista->head);
        lista->head = aux;

    }
}

int main() {
    int opcao;
    LProduct produtos;
    int code,qntd;
    float price;
    char name[30];
    init_list(&produtos);
    while(TRUE){
        printf("1.Criar\n2.Imprimir\n3.Buscar\n4.Excluir\n5.Comprar\n:");
        scanf("%d",&opcao);
        if(opcao == -1){
            limpar(&produtos);
            break;
        }
        else if(opcao == 1){
            do{
                printf("CODE:");
                scanf("%d",&code);
            } while (search_id(&produtos,code));

            printf("NAME:");
            scanf("%s",name);
            printf("PRICE:");
            scanf("%f",&price);
            printf("QUANTIDADE:");
            scanf("%d",&qntd);
            create_product(&produtos,code,qntd,price,name);

        }
        else if(opcao == 2){
            print_list(&produtos,NULL);
        }
        else if(opcao == 3){
            int id; scanf("%d",&id);
            Product *aux = search_id(&produtos,id);
            if(aux){
                print_list(&produtos,aux);
            }
        }
        else if(opcao == 4){
            int id; scanf("%d",&id);
            delete_product(&produtos,id);
        }
        else if(opcao == 5){
            LProduct carrinho;
            init_list(&carrinho);
            while(TRUE){
                printf("----------------------\n");
                printf("Compras\n");
                printf("----------------------\n");
                printf("1.Comprar\n2.Lista de Compras\n3.Lista de Produtos\n4.Devolver\n:");
                scanf("%d",&opcao);
                if(opcao == -1){
                    limpar(&carrinho);
                    break;
                }
                else if(opcao == 1){
                    printf("Codigo:");
                    scanf("%d",&code);
                    printf("Quantidade:");
                    scanf("%d",&qntd);
                    shop(&produtos,&carrinho,code,qntd);
                }
                else if(opcao == 2){
                    print_list(&carrinho,NULL);
                }
                else if(opcao == 3){
                    print_list(&produtos,NULL);
                }
                else if(opcao == 4){
                    printf("Codigo:");
                    scanf("%d",&code);
                    tirar_carrinho(&produtos,&carrinho,code);

                }
            }
        }
    }
    return 0;
}
