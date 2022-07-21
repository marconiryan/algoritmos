#include <iostream>
#include <stdlib.h>
#define COUNT 20

using namespace std;
struct tNode{
    int data;
    struct tNode *right, *left;
};
typedef struct tNode Node;



void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;
    print2DUtil(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
    print2DUtil(root->left, space);
}

void print2D(Node *root)
{
   print2DUtil(root, 0);
}

Node *newNode(int data){
    Node *novo = (Node *) malloc(sizeof(Node));
    novo->left = novo->right = NULL;
    novo->data = data;
    return novo;
}

Node *add(Node *root, int data){
    Node *novo = newNode(data);

    if(root == NULL){
        root = novo;
        return root;
    }

    Node *aux = root;
    while(aux != NULL){
        if(data <= aux->data){
            if(aux->left == NULL){
                aux->left = novo;
                return root;
            }
            aux = aux->left;
        }else{
            if(aux->right == NULL){
                aux->right = novo;
                return root;
            }
            aux = aux->right;
        }
    }
    return root;
}

void altura(Node *root, int count){
    if(root == NULL){
        return;
    }
    count += 1;
    altura(root->left, count);
    altura(root->right, count);
    cout << count << endl;

}



int main(){

    Node *arvore = NULL;
    int numero;
    while(1){
        cin >> numero;
        if(numero == -1){
            system("clear");
            altura(arvore, 0);
        }
        else{
        arvore = add(arvore,numero);
        system("clear");
        print2D(arvore);
        }
    }


    return 0;
}
