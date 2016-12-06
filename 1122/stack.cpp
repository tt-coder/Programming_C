#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    int a,b;
    char s[100];
    while(scanf("%s",s) != EOF){
        if(s[0] == '+'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a+b);
        }else if(s[0] == '-'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(b-a);
        }else if(s[0] == '*'){
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            st.push(a*b);
        }else{
            st.push(atoi(s));
        }
    }
    printf("%d\n",st.top());
}