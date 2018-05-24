/*
 * Self solution for CMPLS
 * AC on SPOJ 0.04 seconds
 */ 


#include <bits/stdc++.h>
using namespace std;


int s[101][101];
int main(){
    int T,S,C,in,elem;
    bool flag, dFlag;
    cin>> T;
    while(T--){
        flag = false; 
        cin>>S>>C;
        for(int i=0;i<S;i++) cin>>s[0][i];
        in=0;
        while(!flag && S-(in+1)>0){
            in++; dFlag = false;
            for(int i=0;i<S-in;i++){
                s[in][i] = s[in-1][i+1] - s[in-1][i];
                if(i==0) elem = s[in][i];
                else{
                    if(!dFlag & elem == s[in][i]) flag = true;
                    else {flag = false;dFlag=true;}
                }
            }
        }

        for(int i=0;i<C;i++) s[in][S+i-in] = s[in][S+i-1-in];

        for(int i=in-1;i>=0;i--){
            for(int j=0;j<C;j++){
                s[i][S+j-i] = s[i][(S-1)+j-i] + s[i+1][S+j-i-1];
            }
        }

        for(int i=S;i<S+C;i++) cout<<s[0][i]<<" ";
        cout<<"\n";
    }
}