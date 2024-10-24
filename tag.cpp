#include<iostream>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        string a, tag="";
        stack<string> tagStack;
        cin >> a;
        int flag = false; //태그가 열리면 true

        for(int i = 0; i<a.size(); i++){
            if(a[i] == '<'){
                if(a[i+1] == '/'){
                    tagStack.pop();
                }
                else{
                    flag = true;
                    tag+="</";
                }
            }
            else if(a[i] == '>' && flag){
                tag+=">";
                tagStack.push(tag);
                tag = "";
                flag = false;
            }
            else if(flag){
                tag += a[i];
            }
        }

        while(!tagStack.empty()){
            cout << tagStack.top();
            tagStack.pop();
        }
        cout << '\n';
    }
}
