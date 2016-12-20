#include <cstdio>
#include <iostream>
using namespace std;
#define MAX 10000
#define NIL -1

struct Node{
    int parent;
    int left;
    int right;
};

Node tree[MAX];
int n,depth[MAX],height[MAX];

void recDepth(int a, int d){
    if(a == NIL) return;
    depth[a] = d;
    recDepth(tree[a].left, d+1);
    recDepth(tree[a].right, d+1);
}

int recHeight(int a){
    int hL=0,hR=0;
    if(tree[a].left != NIL){
        hL = recHeight(tree[a].left) + 1;
    }
    if(tree[a].right != NIL){
        hR = recHeight(tree[a].right) + 1;
    }

    if(hL > hR){
        return height[a] = hL;
    }else{
        return height[a] = hR;
    }
}

int getBrother(int a){
    if(tree[a].parent == NIL){
        return NIL;
    }
    if(tree[tree[a].parent].left != a && tree[tree[a].parent].left != NIL){
        return tree[tree[a].parent].left;
    }
    if(tree[tree[a].parent].right != a && tree[tree[a].parent].right != NIL){
        return tree[tree[a].parent].right;
    }
    return NIL;
}

int main(){
    int v,l,r,root=0;
    cin >> n;
    for(int i=0;i<n;i++){
        tree[i].parent = NIL;
    }
    for(int i=0;i<n;i++){
        cin >> v >> l >> r;
        tree[v].left = l;
        tree[v].right = r;
        if(l!=NIL) tree[l].parent = v;
        if(r!=NIL) tree[r].parent = v;
    }
    for(int i=0;i<n;i++){
        if(tree[i].parent == NIL){
            root = i;
        }
    }
    recDepth(root,0);
    recHeight(root);
    for(int a=0;a<n;a++){
        int count = 0;
        cout << a << " " << tree[a].parent << " " << getBrother(a) << " ";
        if(tree[a].left != NIL){
            count++;
        }
        if(tree[a].right != NIL){
            count++;
        }
        cout << count << " " << depth[a] << " " << height[a] << " " << endl;
    }
    return 0;
}