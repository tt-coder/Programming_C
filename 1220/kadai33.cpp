#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Node{
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

Node * minimum(Node *x){
    while(x->left != NIL) x->left;
    return x;
}

Node * find(Node *u, int k){
    while(u != NIL && k != u->key){
        if(k < u->key){
            u = u->left;
        }else{
            u = u->right;
        }
    }
    return u;
}

Node * next(Node *x){
    if(x->right != NIL) return minimum(x->right);
    Node *y = x->parent;
    while(y != NIL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

void deleteTree(Node *z){
    Node *x;
    Node *y;
    if(z->left == NIL || z->right == NIL){
        y = z;
    }else{
        y = next(z);
    }
    if(y->left != NIL){
        x = y->left;
    }else{
        x = y->right;
    }
    if(x != NIL){
        x->parent = y->parent;
    }
    if(y->parent == NIL){
        root = x;
    }else{
        if(y == y->parent->left){
            y->parent->left = x;    
        }else{
            y->parent->right = x;
        }
    }
    if(y != z){
        z->key = y->key;
    }
    free(y);
}

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
        }else if(command[0] == 'f'){
            Node *t = find(root, key);
            if(t!=NIL){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }else if(command[0] == 'd'){
            deleteTree(find(root,key));
        }
    }
    return 0;
}