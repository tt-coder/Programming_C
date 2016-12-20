#include <iostream>
#define MAX 10000
#define NIL -1
using namespace std;

struct Node{
    int parent;
    int left;
    int right;
};

Node tree[MAX];
int n;

void preOrder(int u){ // 先行
    if(u == NIL) return;
    cout << " " << u;
    preOrder(tree[u].left);
    preOrder(tree[u].right);
}

void inOrder(int u){ // 中間
    if(u == NIL) return;
    inOrder(tree[u].left);
    cout << " " << u;
    inOrder(tree[u].right);
}

void postOrder(int u){ // 後行
    if(u == NIL) return;
    postOrder(tree[u].left);
    postOrder(tree[u].right);
    cout << " " << u;
}

int main(){
    int v,l,r,root;
    cin >> n;
    for(int i=0;i<n;i++){
        tree[i].parent = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> v >> l >> r;
        tree[v].left = l;
        tree[v].right = r;
        if(l != NIL) tree[l].parent = v;
        if(r != NIL) tree[r].parent = v;
    }
    for(int i=0;i<n;i++){
        if(tree[i].parent == NIL) root = i;
    }
    cout << "Preorder" << endl;
    preOrder(root);
    cout << endl;
    cout << "Inorder" << endl;
    inOrder(root);
    cout << endl;
    cout << "Postorder" << endl;
    postOrder(root);
    cout << endl;
    return 0;
}