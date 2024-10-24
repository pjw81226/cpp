#include<iostream>
using namespace std;

#define MOD 1000000007
int arr[10000001];

int main(){
    int T;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    for(int i = 4; i<=10000000; i++){
        arr[i] = (((arr[i-1]+arr[i-2])%MOD)+arr[i-3])%MOD;
    }

    cin >> T;
    while(T--){
        int a;
        cin >> a;
        cout << arr[a] << '\n';
    }
}