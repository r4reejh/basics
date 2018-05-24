#include <bits/stdc++.h>
using namespace std;

void doWork();

int main(){
    int T;
    cin>> T;
    while(T--)
    doWork();
}

void doWork(){
    int S,C;
    cin>>S>>C;
    // init
    int seq[S];
    int s[S+C][S+C];

    int num_of_diff = 0;
    bool same_elements = false;
    for(int i=0;i<S;i++)
    cin>>seq[i];
    memcpy(s[0], seq, sizeof(seq));
    
    while(!same_elements && num_of_diff<S && S-num_of_diff>1){
        ++num_of_diff;
        int elem = 0;
        for(int i=0;i<S-num_of_diff;i++){
            s[num_of_diff][i] = s[num_of_diff-1][i+1] - s[num_of_diff-1][i];
            if(i==0)
            elem = s[num_of_diff][i];
            else{
                if(elem == s[num_of_diff][i]){
                    same_elements = true;
                }
                else{
                    same_elements = false;
                }
            }
        }
    }
    for(int i=num_of_diff; i>=1; i--){
        for(int j=0;j<S-i;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<"\n";
    }
}