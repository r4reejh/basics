#include <bits/stdc++.h>
using namespace std;

/*
Priority of operators not necessary

TEST CASES:
IP: ((a+b)*(z+x))
OP: ab+zx+*

IP: ((a+t)*((b+(a+c))^(c+d)))
OP: at+bac++cd+^
*/



char st[400];
int top=-1;

int main(){
    int T;
    cin>>T;
    while(T--){
        string expr;
        cin>>expr;
        string out="";
        for(int i=0;i<expr.length();i++){
            char c = expr[i];
            if(c == '('){
                st[++top] = c;
            } else if(c == ')'){
                while(st[top]!='(')
                out+=st[top--];
                top--;
            } else if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^' || c=='%'){
                st[++top]=c;
            } else {
                out+=c;
            }
        }
        while(top>=0){
            out+=st[top--];
        }
        cout<<out<<endl;
    }
}

