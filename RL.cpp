#include<stack>
#include<iostream>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        int h, q, c;
        stack<string> answer;
        
        cin >> h >> q;
        for(int i = 0; i<q; i++){
            cin >> c;
            while(c != 1){
                if(c%2 == 1){
                    c = c/2;
                    answer.push("R");
                }
                else{
                    c = c/2;
                    answer.push("L");
                }   
            }

            while(!answer.empty()){
                cout << answer.top();
                answer.pop();
            }
            cout << '\n';
        }
    }
}