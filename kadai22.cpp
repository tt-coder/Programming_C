#include <iostream>
#define MAX  200000
using namespace std;

int main(){
    int n,count=0;
    int a[MAX];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]<a[j]){
                count++;
            }
        }
    }
    cout << count << endl;
}