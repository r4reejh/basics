#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;


bitset<100000000> b;

int naive_prime(int x){
    if(x>=2){
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0)
                cout<<"Not Prime"<<endl;
                return 0;
        }
        cout<<"Prime"<<endl;
        return 0;
    } else {
        cout<<"Not Prime";
        return 0;
    }
}


/* Sieve of Eratosthenes */
int sieve(ll x,ll k){
    for(ll i=2;i<=k;i++){
        if(!b[i]){
            for(ll j=i*i; j<=k;j+=i){
                b[j]=1;
            }
        }
    }

    for(ll i=2;i<=k;i++){
        if(b[i]==0)
        cout<<i<<" ";
    }
    cout<<"\n";
    return 0;
}

int main(){
    ll l,h;
    cin>>l>>h;
    int x =sieve(l,h);
    return x;
}