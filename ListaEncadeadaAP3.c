#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0

struct data{
    char data_nascimento[15];
};
typedef struct data Data;
struct aluno{
    char matricula[10], nome[40];
    Data nascimento;
    float media;
    struct aluno *next;
};

typedef struct aluno Aluno;

int QuantosElementos(Aluno *first)
{
    int contador = 0;
    while(first != NULL)
    {
        contador++;
        first = first->next;
    }
    return contador;
}

int ListaVazia(Aluno *first)
{
    if (!QuantosElementos(first))
    {
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
        printf("%s, %s, %s, %.2f\n", aux->matricula, aux->nome, aux->nascimento.data_nascimento, aux->media);
    }
}

void MostrarAlunosReverso(Aluno *first) // NOLINT(misc-no-recursion)
{
    if(first == NULL)
    {
        return;
    }
    MostrarAlunosReverso(first->next);
    printf("%s, %s, %s, %.2f\n", first->matricula, first->nome, first->nascimento.data_nascimento, first->media);
}


Aluno *Inserir(Aluno *atual)
{
    float media;
    char matricula[10], nome[40], data_nasc[15];
    atual = (Aluno * ) malloc(sizeof(Aluno));
    scanf("%s",matricula);
    scanf("%s", nome);
    scanf("%s",data_nasc);
    scanf("%f",&media);
    strcpy(atual->matricula, matricula);
    strcpy(atual->nome, nome);
    strcpy(atual->nascimento.data_nascimento, data_nasc);
    atual->media = media;
    atual->next = NULL;
    return atual;
}

Aluno *Excluir(Aluno *first,  const char *matricula)
{
    Aluno *aux, *prev = first;
    for(aux = first; aux != NULL; aux = aux->next)
    {
        if(strcmp(aux->matricula, matricula) == 0)
        {
            if(aux == first)
            {
                first = aux->next;
                free(prev);
                return first;
            }
            prev->next = aux->next;
            free(aux);
            return first;

        }
        prev = aux;
    }
    return first;
}

Aluno *update(Aluno *first, Aluno *aux)
{
    if(first != NULL)
    {
        aux = first;
        while(TRUE)
        {
            if(aux->next == NULL)
            {
                return aux;
            }
            aux = aux->next;

        }
    }
    return NULL;
}

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


void Sair(Aluno *first)
{
    Aluno *aux = first;
    while(aux != NULL)
    {
        Aluno *next = aux->next;
        printf("-");
        free(aux);
        aux = next;
    }
}



int main()
{
    Aluno *atual, *aux, *first = NULL;
    while(TRUE)
    {
        int opt;
        scanf("%d", &opt);
        if(opt == 0)
        {
            Sair(first);
            break;
        }
        else if(opt == 1)
        {

            atual = Inserir(atual);
            if(first == NULL)
            {
                first = atual;
                aux = atual;
            }
            else
            {
                aux->next = atual;
                aux = atual;
            }
        }
        else if(opt == 2)
        {if(!ListaVazia(first))
            {
                char matricula[10]; scanf("%s",matricula);
                for(int i = search(first,matricula); i > 0; i--)
                {
                    first = Excluir(first,matricula);
                    aux = update(first,aux);
                }
            }
        }
        else if(opt == 3)
        {
            if(!ListaVazia(first))
            {
                MostrarAlunos(first);
            }
        }
        else if(opt == 4)
        {
            if(!ListaVazia(first))
            {
                MostrarAlunosReverso(first);
            }
        }
        else if(opt == 5)
        {
            printf("A lista tem %d elementos\n",QuantosElementos(first));
        }
    }
    return 0;
}
