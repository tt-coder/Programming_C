#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Node{
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k){
    Node *x = root;
    Node *y = NIL;
    Node *z;
    z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;
    while(x != NIL){
        y = x;
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y == NIL){
        root = z;
    }else{
        if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}

void inorder(Node *n){
    if(n == NIL) return;
    inorder(n->left);
    printf(" %d", n->key);
    inorder(n->right);
}

void preorder(Node *n){
    if(n == NIL) return;
    printf(" %d", n->key);
    preorder(n->left);
    preorder(n->right);
}

int main(){
    int n, key;
    char command[10];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s %d",&command,&key);
        if(command[0] == 'i'){
            insert(key);
        }else if(command[0] == 'p'){
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
    return 0;
}