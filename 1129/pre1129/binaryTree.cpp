#include <cstdio>
#define MAX 10000
#define NIL -1

struct Node{
    int parent;
    int left;
    int right;
};

Node tree[MAX];
int n,depth[MAX],height[MAX];

void setDepth(int u, int d){
    if(u == NIL) return;
    depth[u] = d;
    setDepth(tree[u].left, d+1);
    setDepth(tree[u].right, d+1);
}

int setHeight(int u){
    int h1=0,h2=0;
    if(tree[u].left != NIL) h1 = setHeight(tree[u].left) + 1;
    if(tree[u].right != NIL) h2 = setHeight(tree[u].right) + 1;
    return height[u] = (h1 > h2 ? h1 : h2);
}

int getSibling(int u){
    if(tree[u].parent == NIL) return NIL;
    if(tree[tree[u].parent].left != u && tree[tree[u].parent].left != NIL) return tree[tree[u].parent].left;
    if(tree[tree[u].parent].right != u && tree[tree[u].parent].right != NIL) return tree[tree[u].parent].right;
    return NIL;
}

void print(int u){
    printf("node %d: ", u);
    printf("parent = %d, ", tree[u].parent);
    printf("sibling = %d, ", getSibling(u));
    int deg = 0;
    if(tree[u].left != NIL) deg++;
    if(tree[u].right != NIL) deg++;
    printf("degree = %d, ", deg);
    printf("depth = %d, ", depth[u]);
    printf("height = %d, ", height[u]);
    if(tree[u].parent == NIL){
        printf("root\n");
    }else if(tree[u].left == NIL && tree[u].right == NIL){
        printf("leaf\n");
    }else{
        printf("internal node\n");
    }
}

int main(){
    int v,l,r,root=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        tree[i].parent = NIL;
    }
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&v,&l,&r);
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
    setDepth(root,0);
    setHeight(root);
    for(int i=0;i<n;i++){
        print(i);
    }
    return 0;
}