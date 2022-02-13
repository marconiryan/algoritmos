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
        printf("----------------\n");
        printf("Lista Vazia\n");
        printf("----------------\n");
        return TRUE;
    }
    return FALSE;
}

void MostrarAlunos(Aluno *first)
{
        Aluno *aux;
        for (aux = first; aux != NULL; aux = aux->next)
        {
            printf("%s, %s, %d/%d/%d, %.2f\n", aux->matricula, aux->nome, aux->nascimento.dia, aux->nascimento.mes,
                   aux->nascimento.ano, aux->media);
        }
}

void MostrarAlunosReverso(Aluno *first) // NOLINT(misc-no-recursion)
{
        if(first == NULL)
        {
            return;
        }
        MostrarAlunosReverso(first->next);
        printf("%s, %s, %d/%d/%d, %.2f\n", first->matricula, first->nome, first->nascimento.dia,first->nascimento.mes, first->nascimento.ano, first->media);
}
Aluno *Inserir(Aluno *atual)
{
    int dia, mes, ano;
    float media;
    char matricula[10], nome[40];
    atual = (Aluno * ) malloc(sizeof(Aluno));
    printf("Matricula:");
    scanf("%s",matricula);
    printf("Nome:");
    scanf("%s", nome);
    printf("Data Nascimento:");
    scanf("%d %d %d",&dia, &mes, &ano);
    printf("Media:");
    scanf("%f",&media);
    strcpy(atual->matricula, matricula);
    strcpy(atual->nome, nome);
    atual->nascimento.dia = dia;
    atual->nascimento.mes = mes;
    atual->nascimento.ano = ano;
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

void Sair(Aluno *first)
{
    printf("Desalocando...\n");
    Aluno *aux = first;
    while(aux != NULL)
    {
        Aluno *next = aux->next;
        printf("-Matricula:%s\n",aux->matricula);
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
        printf("(0) Sair\n(1) Adicionar\n(2) Excluir\n(3) Imprimir\n(4) Imprimir Reverso\n(5) Quantidade Elementos\n:");
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
            first = Excluir(first,matricula);
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
