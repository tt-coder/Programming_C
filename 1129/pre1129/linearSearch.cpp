#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;
int cnt = 0;
list <int> v;

void deleteList(int key){
   for(list<int>::iterator it = v.begin();it != v.end();it++){
        if(*it == key){
            v.erase(it);
            break;
        }
   } 
}

void printList(){
    for(list<int>::iterator it = v.begin();it != v.end();it++){
        printf("%d\n", *it);
    }
}

void linearSearch(int a[], int n, int value){
    for(int i=0;i<n;i++){
        if(a[i] == value){
            cnt++;
            deleteList(value);
        }
    }
}

int main(){
    int n,q,value;
    int a[10005];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d",&value);
        v.push_front(value);
        linearSearch(a,n,value);
    }
    printList();
    if(q-cnt == 0) printf("\n");
    printf("%d\n",q-cnt);
    return 0;
}