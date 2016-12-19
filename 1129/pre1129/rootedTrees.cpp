#include <iostream>
using namespace std;
#define MAX 100005
#define NIL -1

struct Node{
    int parent,left,right;
};

Node tree[MAX];
int n, depth[MAX];

void print(int a){
    int c;
    cout << "node " << a << ": ";
    cout << "parent = " << tree[a].parent << ", ";
    cout << "depth = " << depth[a] << ", ";
    if(tree[a].parent == NIL){
        cout << "root, ";
    }else if(tree[a].left == NIL){
        cout << "leaf, ";
    }else{
        cout << "internal node, ";
    }
    cout << "[";
    for(int i=0,c=tree[a].left;c!=NIL;i++,c=tree[c].right){
        if(i) cout << ", ";
        cout << c;
    }
    cout << "]" << endl;
}

int rec(int a, int b){ // 深さ-0
    depth[a] = b;
    if(tree[a].right != NIL){ // 右に同じ高さ
        rec(tree[a].right,b);
    }
    if(tree[a].left != NIL){ // 最も左に自分の深さ+1
        rec(tree[a].left,b+1);
    }
}

int main(){
    int id,k,c,tmp,r;
    cin >> n;
    for(int i=0;i<n;i++){
        tree[i].parent = NIL;
        tree[i].left = NIL;
        tree[i].right = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> id >> k;
        for(int j=0;j<k;j++){
            cin >> c;
            if(j == 0){
                tree[id].left = c;
            }else{
                tree[tmp].right = c;
            }
            tmp = c;
            tree[c].parent = id;
        }
    }
    for(int i=0;i<n;i++){
        if(tree[i].parent == NIL){
            r = i;
        }
    }
    rec(r,0);
    for(int i = 0;i<n;i++){
        print(i);
    }
    return 0;
}