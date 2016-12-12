#include <iostream>
#include <queue>
using namespace std;

string b1 = ".,!? ";
string b2 = "abc";
string b3 = "def";
string b4 = "ghi";
string b5 = "jkl";
string b6 = "mno";
string b7 = "pqrs";
string b8 = "tuv";
string b9 = "wxyz";

string str,ans = "";

int cnt[10],tmp;

void countInit(){
    for(int i=0;i<10;i++){
        cnt[i] = 0;
    }
}

void printChar(){
    int p;
    if(tmp == 1){
        ans += b1[--cnt[1]];
    }else if(tmp == 2){
        ans += b2[--cnt[2]];
    }else if(tmp == 3){
        ans += b3[--cnt[3]];
    }else if(tmp == 4){
        ans += b4[--cnt[4]];
    }else if(tmp == 5){
        ans += b5[--cnt[5]];
    }else if(tmp == 6){
        ans += b6[--cnt[6]];
    }else if(tmp == 7){
        ans += b7[--cnt[7]];
    }else if(tmp == 8){
        ans += b8[--cnt[8]];
    }else if(tmp == 9){
        ans += b9[--cnt[9]];
    }
}

void button(){
    int len = str.size();
    for(int i=0;i<len;i++){
        char c = str[i];
            if(c == '0'){
                if(tmp != 0) printChar();
                tmp = 0;
                countInit();
            }else if(c == '1'){
                tmp = 1;
                cnt[1]++;
                if(cnt[1] == 6) cnt[1] = 1;
            }else if(c == '2'){
                tmp = 2;
                cnt[2]++;
                if(cnt[2] == 4) cnt[2] = 1;
            }else if(c == '3'){
                tmp = 3;
                cnt[3]++;
                if(cnt[3] == 4) cnt[3] = 1;
            }else if(c == '4'){
                tmp = 4;
                cnt[4]++;
                if(cnt[4] == 4) cnt[4] = 1;
            }else if(c == '5'){
                tmp = 5;
                cnt[5]++;
                if(cnt[5] == 4) cnt[5] = 1;
            }else if(c == '6'){
                tmp = 6;
                cnt[6]++;
                if(cnt[6] == 4) cnt[6] = 1;
            }else if(c == '7'){
                tmp = 7;
                cnt[7]++;
                if(cnt[7] == 5) cnt[7] = 1;
            }else if(c == '8'){
                tmp = 8;
                cnt[8]++;
                if(cnt[8] == 4) cnt[8] = 1;
            }else if(c == '9'){
                tmp = 9;
                cnt[9]++;
                if(cnt[9] == 5) cnt[9] = 1;
            }
    }
}

int main(){
    int n;
    queue <string> q;
    cin >> n;
    for(int i=0;i<n;i++){
        countInit();
        cin >> str;
        button();
        q.push(ans);
        //cout << ans << endl;
        ans = "";
    }
    for(int i=0;i<n;i++){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}