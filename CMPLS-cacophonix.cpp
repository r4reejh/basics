/* cacoponix submission of CMPLS on SPOJ
 * @ https://github.com/cacophonix/SPOJ/blob/master/CMPLS.cpp
 * this was AC on SPOJ
 */ 


#include <bits/stdc++.h>
using namespace std;

int seq[101][101];

int main() {
	int T, S, C, i, j;
	cin>>T;
	while(T--) {
		cin>>S>>C;
		for(i = 0; i < S; i++) 
            cin>>seq[0][i];

		for(i = 1; i < S; i++){
            for(j = 0; j < S-i; j++)
			seq[i][j] = seq[i-1][j+1] - seq[i-1][j];
        }
		for(i = 1; i <= C; i++) 
        seq[S-1][i] = seq[S-1][i-1];
		for(i = S-2; i >= 0; i--){
            for(j = S-i; j < S-i+C; j++)
			seq[i][j] = seq[i+1][j-1] + seq[i][j-1];
        }
		cout<<seq[0][S]<<" ";
		for(i = 1; i < C; i++) 
        cout<<seq[0][S+i]<<" ";
		cout<<"\n";
	}
	return 0;
}