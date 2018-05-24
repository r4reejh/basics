/*
 * FCTRL problem on spoj
 * https://brilliant.org/wiki/trailing-number-of-zeros/
 * i *= 5 is 0.10 AC
 * */

#include <bits/stdc++.h>
#define long long ll
using namespace std;

int main(){
    int T, C, i, nOz;
    cin>>T;
    while(T--){
        cin>>C;
        i = 5;
        nOz = 0;
        while(i<=C){
            nOz += C/i;
            i *= 5;
        }
        cout<<nOz<<endl;
    }
    return 0;
}