#include <cstdio>
#include <cstdlib>
#include <cstring>

char button1[1][5] = {'.', ',' ,'!' ,'?' ,' '};
char button2[1][3] = {'a', 'b' ,'c'};
char button3[1][3] = {'d', 'e' ,'f'};
char button4[1][3] = {'g', 'h' ,'i'};
char button5[1][3] = {'j', 'k' ,'l'};
char button6[1][3] = {'m', 'n' ,'o'};
char button7[1][4] = {'p', 'q' ,'r', 's'};
char button8[1][3] = {'t', 'u' ,'v'};
char button9[1][4] = {'w', 'x' ,'y', 'z'};

int p[10];
int tmp;

void printS(){
    int a;
    if(tmp == 1){
        a = p[0] - 1;
        printf("%c\n",button1[1][a]);
    }else if(tmp == 2){
        a = p[1] - 1;
        printf("%c\n",button2[1][a]);
    }else if(tmp == 3){
        a = p[2] - 1;
        printf("%c\n",button3[1][a]);
    }else if(tmp == 4){
        a = p[3] - 1;
        printf("%c\n",button4[1][a]);
    }else if(tmp == 5){
        a = p[4] - 1;
        printf("%c\n",button5[1][a]);
    }else if(tmp == 6){
        a = p[5] - 1;
        printf("%c\n",button6[1][a]);
    }else if(tmp == 7){
        a = p[6] - 1;
        printf("%c\n",button7[1][a]);
    }else if(tmp == 8){
        a = p[7] - 1;
        printf("%c\n",button8[1][a]);
    }else if(tmp == 9){
        a = p[8] - 1;
        printf("%c\n",button9[1][a]);
    }
}

int main(){
    int n;
    char str[1050];
    char c;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        while(1){
            scanf("%c",&c);
            if(c == '0'){
                printS();
                break;
            }
            if(c == '1'){
                tmp = 1;
                p[0]++;
            }else if(c == '2'){
                tmp = 2;
                p[1]++;
            }else if(c == '3'){
                tmp = 3;
                p[2]++;
            }else if(c == '4'){
                tmp = 4;
                p[3]++;
            }else if(c == '5'){
                tmp = 5;
                p[4]++;
            }else if(c == '6'){
                tmp = 6;
                p[5]++;
            }else if(c == '7'){
                tmp = 7;
                p[6]++;
            }else if(c == '8'){
                tmp = 8;
                p[7]++;
            }else if(c == '9'){
                tmp = 9;
                p[8]++;
            }
        }
    }
}