// Cプログラム
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, st[1000];

void push(int x){
    st[++top] = x;
}

int pop(){
    top--;
    return st[top+1];
}

void show(){
    int i;
    for(i=1;i<top+1;i++){
        if(i>1) printf(" ");
        printf("%d",st[i]);
    }
    printf("\n");
}

int main(void){
    int a,b;
    char s[100];
    while(scanf("%s",s) != EOF){
            if(s[0] == '+'){
                a = pop();
                b = pop();
                push(a+b);
                show();
            }else if(s[0] == '-'){
                b = pop();
                a = pop();
                push(b-a);
                show();
            }else if(s[0] == '*'){
                a = pop();
                b = pop();
                push(a*b);
                show();
            }else if(s[0] == '='){
                break;
            }else{
                push(atoi(s));
                show();
            }
    }
    return 0;
}