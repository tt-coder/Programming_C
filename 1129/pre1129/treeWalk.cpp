#include <cstdio>
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

void preParse(int u){ // 先行
    if(u == NIL) return;
    cout << " " << u;
    preParse(tree[u].left);
    preParse(tree[u].right);
}

void inParse(int u){ // 中間
    if(u == NIL) return;
    inParse(tree[u].left);
    cout << " " << u;
    inParse(tree[u].right);
}

void postParse(int u){ // 後行
    if(u == NIL) return;
    postParse(tree[u].left);
    postParse(tree[u].right);
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
    preParse(root);
    cout << endl;
    cout << "Inorder" << endl;
    inParse(root);
    cout << endl;
    cout << "Postorder" << endl;
    postParse(root);
    cout << endl;
    return 0;
}