#include<iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int x, y, cost=0 , count3=0 , count6=0, count9=0, uselessnumber = 0;
        string c;
        cin >> x >> y >> c;

        for(int i = 0; i<c.size();i++){
            if(c[i] == '3' || c[i] == '6' || c[i] == '9'){
                if(c[i] == '3') count3++;
                if(c[i] == '6') count6++;
                if(c[i] == '9') count9++;

                if(uselessnumber * x < x+y){
                    cost += (uselessnumber * x);
                }
                else{
                    cost+= (x+y);
                }
                uselessnumber=0;
            }
            else{
                uselessnumber +=1;
            }
        }

        if(uselessnumber * x < x+y){
            cost += (uselessnumber * x);
        }
        else{
           cost+= (x+y);
        }

        int made = min(count3,min(count6,count9));
        cout << cost << " " << made <<'\n';
    }
}