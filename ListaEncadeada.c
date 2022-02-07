#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

typedef struct point{
	int x,y;
	struct point *next;
}Point;


void setPoint(int *x, int *y){
	int *x_m; x_m = malloc(sizeof(int));
	int *y_m; y_m = malloc(sizeof(int));
	x = x_m;
	y = y_m;


}

int main(){
	Point *f,*aux,*first = NULL;
	while(TRUE){
		int xi,yi;
		printf("X:");
		scanf("%d",&xi);
		if(xi == 0){
			break;
		}
		printf("Y:");
		scanf("%d",&yi);
		f = (Point *) malloc(sizeof(Point));
		setPoint(&xi,&yi);
		f->x = xi;
		f->y = yi;
		if(first == NULL){
			first = f;
			aux = f;

		}
		else{
			aux->next = f;
			aux = f;
		}

	}
	printf("-----------------\n");	
	for(aux = first; aux != NULL; aux = aux->next){
		printf("(%d %d)\n",aux->x, aux->y);
	}
	printf("-----------------");
	


	return 0;
}
