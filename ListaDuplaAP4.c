#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
struct data{
    int dia, mes, ano;
};
typedef struct data Data;
struct aluno{
    char matricula[10], nome[40];
    Data nascimento;
    float media;
    struct aluno *next,*prev;
};

typedef struct aluno Aluno;


int search(Aluno *first, const char matricula[10])
{
    Aluno *aux;
    int contador = 0;
    for(aux = first; aux !=NULL; aux = aux->next)
    {
        if(strcmp(aux->matricula,matricula) == 0)
        {
            contador++;
        }
    }
    return contador;
}

int Vazia(Aluno * first){
    if(first == NULL){
        printf("Lista Vazia!\n");
        return TRUE;
    }
    return FALSE;

}

void MostrarAlunos(Aluno *first)
{
    Aluno *aux;
    for (aux = first; aux != NULL; aux = aux->next)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.dia,aux->nascimento.mes,aux->nascimento.ano, aux->media);
    }
}

void MostrarAlunosReverso(Aluno *last)
{
    Aluno *aux;
    for (aux = last; aux != NULL; aux = aux->prev)
    {
        printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.dia,aux->nascimento.mes,aux->nascimento.ano, aux->media);
    }
}



void Sair(Aluno *first){
    for(Aluno *aux = first; aux != NULL; aux = aux->next){
        printf("*");
    }

}

Aluno *Magia(Aluno *last, const char matricula_anterior[10]){
    Aluno *aux = last;
    if(strcmp(matricula_anterior, aux->matricula) == 0){ // Ultimo
        return aux;
    }
    for(; aux->prev !=NULL; aux = aux->prev){ // Meio
        if(strcmp(matricula_anterior, aux->prev->matricula) == 0){
            return aux->prev;
        }
    }

    return NULL; // Inicio
}



int main(){
    Aluno *atual, *first=NULL, *last=NULL;
    int opt;

    while(TRUE){
        scanf("%d",&opt);
        if(opt == 0){
            Sair(first);
            printf("\n");
            break;
        }

        else if(opt == 1){
            char matricula[10],nome[40],matricula_anteiror[10];
            int dia, mes, ano;
            float media;
            atual = (Aluno *) malloc(sizeof(Aluno));
            scanf("%s",matricula_anteiror);
            scanf("%s",matricula);
            scanf("%s",nome);
            scanf("%d/%d/%d",&dia,&mes,&ano);
            scanf("%f",&media);
            atual->nascimento.dia = dia; atual->nascimento.mes = mes ;atual->nascimento.ano = ano;
            strcpy(atual->matricula, matricula);
            strcpy(atual->nome, nome);
            atual->media = media;
            atual->next = NULL;
            atual->prev = NULL;
            if(first == NULL){
                first = atual;
                last = first;
            }
            else{
                Aluno *aux = Magia(last,matricula_anteiror);
                if(aux == NULL){ //First
                    first->prev = atual;
                    atual->next = first;
                    atual->prev = NULL;
                    first = atual;

                }
                else if(aux == last){ // Ultimo
                    aux->next = atual;
                    atual->prev = aux;
                    atual->next = NULL;
                    last = atual;
                }
                else{ // Meio
                    Aluno *proximo = aux->next;
                    aux->next = atual;
                    atual->prev = aux;
                    atual->next = proximo;
                    proximo->prev = atual;
                    
                }
            }

        }
        else if(opt == 2){
            if(!Vazia(first)){
            char matricula[10];
            Aluno *auxiliar;
            scanf("%s",matricula);
            for(int i = search(first,matricula); i > 0; i--){
                for(auxiliar= first; auxiliar != NULL;auxiliar = auxiliar->next){
                    if(strcmp(matricula,auxiliar->matricula) == 0){
                        if(auxiliar == first){
                            first = auxiliar->next;
                            if(first != NULL){
                                first->prev = NULL;
                            }
                        }
                        else if(auxiliar == last){
                            last = auxiliar->prev;
                            last->next = NULL;
                        }
                        else{
                            auxiliar->prev->next = auxiliar->next;
                            auxiliar->next->prev = auxiliar->prev;
                        }
                        free(auxiliar);
                        break;
                        }
                    }
                }
            }
        }
        else if(opt == 3){if(!Vazia(first)){
                MostrarAlunos(first);}}
        else if(opt == 4){if(!Vazia(first)){
                MostrarAlunosReverso(last);}}
    }
    printf("\n");
    return 0;
}

