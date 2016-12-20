#include <iostream>
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
        y = x; // 親を設定
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
        if(z->key < y->key){ // 左の子
            y->left = z;
        }else{ // 右の子
            y->right = z;
        }
    }
}

void inOrder(Node *n){
    if(n == NIL) return;
    inOrder(n->left);
    cout << " " << n->key;
    inOrder(n->right);
}

void preOrder(Node *n){
    if(n == NIL) return;
    cout << " " << n->key;
    preOrder(n->left);
    preOrder(n->right);
}

int main(){
    int n, key;
    char command[10];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command;
        if(command[0] == 'i'){
            cin >> key;
            insert(key);
        }else if(command[0] == 'p'){
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }
    return 0;
}