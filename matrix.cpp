#include<iostream>
using namespace std;

#define MOD 1000000007
void matrixMult(long long x[2][2], long long y[2][2]){
    long long temp[2][2];
    temp[0][0] = ((x[0][0]*y[0][0])%MOD + (x[0][1]*y[1][0])%MOD)%MOD;
    temp[0][1] = ((x[0][0]*y[0][1])%MOD + (x[0][1]*y[1][1])%MOD)%MOD;
    temp[1][0] = ((x[1][0]*y[0][0])%MOD + (x[1][1]*y[1][0])%MOD)%MOD;
    temp[1][1] = ((x[1][0]*y[0][1])%MOD + (x[1][1]*y[1][1])%MOD)%MOD;

    x[0][0] = temp[0][0];
    x[0][1] = temp[0][1];
    x[1][0] = temp[1][0];
    x[1][1] = temp[1][1];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, N;
    long long M[2][2];
    long long answer[2][2];
    cin >> T;

    while (T--) {
        cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1] >> N;
        answer[0][0] = answer[1][1] = 1; answer[0][1] = answer[1][0] = 0;

        while(N>0){
            if( N%2 == 1){
                matrixMult(answer,M);
            }
            matrixMult(M,M);
            N= N/2;
        }
        cout << answer[0][0] << " " << answer[0][1] << '\n' << answer[1][0] << " "<< answer[1][1]<<'\n';
    }
}