#include<iostream>
using namespace std;

int main(){
    string a;
    long long answer = 0;
    cin >> a;

    for(int i = 0; i<=a.size(); i++){
        long long tmp = 1;
        for(int k = 0; k<i; k++){
            tmp = tmp * 2;
        }
        answer += tmp;
    }
    cout << answer <<'\n';
}
