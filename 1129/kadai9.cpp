#include <cstdio>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int cnt = 0;
list <string> v;

void removeList(string key){
   for(list<string>::iterator it = v.begin();it != v.end();it++){
        if(*it == key){
            v.erase(it);
            break;
        }
   } 
}

void findList(string key){
    int flag = 0;
    for(list<string>::iterator it = v.begin();it != v.end();it++){
        if(*it == key){
            printf("yes\n");
            flag = 1;
            break;
        }
    }
    if(flag == 0) printf("no\n");
}

int main(){
    int n;
    string command;
    string str;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> command >> str;
        if(command == "add"){
            v.push_front(str);
        }else if(command == "remove"){
            removeList(str);
        }else if(command == "find"){
            findList(str);
        }
    }
}