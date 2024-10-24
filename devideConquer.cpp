#include<iostream>
using namespace std;

string problem;
string answer ="";
void devideConquer(int left, int right){
    if(left == right){
        answer += problem[left];
        return;
    }
    bool flag = false;
    for(int i = left; i<right; i++){
        if(problem[i] != problem[i+1]){
            flag = true;
        }
    }
    
    if(flag){
        answer += "B";
        int mid = (left + right)/2;
        devideConquer(left,mid);
        devideConquer(mid+1, right);
        return;
    }

    answer += problem[left];
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        cin >> problem;
        devideConquer(0, problem.size()-1);
        cout << answer << '\n';
        answer = "";
    }
}
