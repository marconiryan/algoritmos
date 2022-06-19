#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

struct lista{
	char info;
	struct lista *prox;
	

};
typedef struct lista Lista;

struct fila{
	Lista *ini;
	Lista *fim;

};
typedef struct fila Fila;

Fila *fila_cria(){
	Fila *f = (Fila *) malloc(sizeof(Fila));
	f->ini = f->fim = NULL;
	return f;

}

void fila_insere(Fila *f, const char letra){

	Lista *n  = (Lista*) malloc(sizeof(Lista));
	n->info = letra;
	n->prox = NULL;
	if(f->fim != NULL){
		f->fim->prox = n;
	}
	else{
		f->ini = n;
	}
	f->fim = n;
}


int fila_vazia(Fila *f){
	return (f->ini == NULL);

}

char fila_retira(Fila *f){
	Lista *t;
	char v;
	if (fila_vazia(f)){
		printf("Fila vazia.\n");
		//exit(1);

	}
	else{
	t = f->ini;
	v = t->info;
	f->ini = t->prox;
	if(f->ini == NULL){
		f->fim = NULL;

	}

	free(t);}
	return v;


}

void fila_libera(Fila *f){
	Lista *q = f->ini;
	while(q!=NULL){
		Lista *t = q->prox;
		free(q);
		q = t;


	}
	free(f);


}


void fila_imprime(Fila *f){
	Lista *q;
	printf("IMPRIMINDO:\n");
	for(q = f->ini; q !=NULL; q = q->prox){
		printf("%c\n",q->info);


	}
	printf("---------\n");


}

int main(){
	Fila *f = fila_cria();
	int opt;
	while(TRUE){
		printf("0.Sair\n1.Inserir\n2.Retira\n3.Imprime\n");
		scanf("%d",&opt);
		printf("OPCAO:%d\n",opt);
		if(opt == 0){break;}
		if(opt == 1){
			char c; scanf(" %c",&c);
			fila_insere(f,c);

		}
		else if(opt == 2){
			printf("Elemento retirado: %c\n",fila_retira(f));
		
		}

		else if(opt == 3){
			fila_imprime(f);
			
		}
	

	}
	fila_libera(f);


	return 0;
}
