#include<iostream>
using namespace std;

int gcd(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        int timer[10];

        for(int i = 0; i<N; i++){
            cin >> timer[i];
        }

        long long answer= timer[0];
        for(int i = 1; i<N; i++){
            answer = answer * timer[i] /gcd(answer, timer[i]);
        }
        
        cout << answer <<'\n';
    }
}