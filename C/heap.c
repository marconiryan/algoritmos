#include <stdio.h>
#include <stdlib.h>



void printvector(int vector[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ",vector[i]);
    }
    printf("\n");

}

void insertvector(int vector[], int size){
    for(int i = 0; i < size; i++){
        scanf("%d", &vector[i]);
    }

}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;

}


int parent(int index){
    if((index - 1) / 2 < 0){
        return 0;
    }
    return (int) (index - 1) / 2;
}
int right(int index){
    return 2*index + 1;

}
int left(int index){
    return 2 * index + 2;
}

void comp_pai(int vetor[],int i, int *flag){
    while(i >= 0){
        if(vetor[parent(i)] < *flag){
            swap(&vetor[parent(i)],flag);
        }
        else{
            return;
        }
        i--;
    }


}


void heap(int vetor[], int n){
    for(int i = 0; i < n/3; i++){
        comp_pai(vetor,i,&vetor[right(i)]);
        comp_pai(vetor,i,&vetor[left(i)]);
        }
}




int main(){
    int n; 
    scanf("%d",&n);
    int *vetor = (int *) malloc(sizeof(int) * n);
    insertvector(vetor, n);
    printvector(vetor,n);
    heap(vetor,n);
    printvector(vetor,n);




    return 0;
}
