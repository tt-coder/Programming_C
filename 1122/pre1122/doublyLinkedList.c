#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int key;
    Node *prev, *next;
};

Node *nil;

void init(){ // 起点の生成
    nil = (Node*)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

void insert(int key){
    Node *x = (Node*)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    nil->next->prev = x;
    nil->next = x;
    x->prev = nil;
}

Node* listSearch(int key){
    Node* cur = nil->next;
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }
    return cur;
}

void deleteNode(Node *t){
    if(t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
    free(t);
}

void deleteFirst(){
    deleteNode(nil->next);
}

void deleteLast(){
    deleteNode(nil->prev);
}

void deleteKey(int key){
    deleteNode(listSearch(key));
}

void printList(){
    Node* cur = nil->next;
    int isf = 0;
    while(1){
        if(cur == nil) break;
        if(isf++ > 0) printf(" ");
        printf("%d", cur->key);
        cur = cur->next;
    }
    printf("\n");
}

int main(void){
    int n,key,i,size = 0;
    char com[20];
    scanf("%d",&n);
    init();
    for(i=0;i<n;i++){
        scanf("%s %d", com, &key);
        if(com[0] == 'i'){
            insert(key);
        }else if(com[0] == 'd'){
            deleteKey(key);
        }
    }
}