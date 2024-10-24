#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int parent[1001];
int result;
priority_queue<pair<int,pair<int,int>>> edges; //발전소 0번은 가상의 노드 

int getParent(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = getParent(parent[x]);
}
void unionParent(int a, int b){
    parent[getParent(b)] = getParent(a);
}
bool checkParent(int a , int b){
    return getParent(a) == getParent(b);
}

void kruskal(){
    while(!edges.empty()){
        if(!checkParent(edges.top().second.first, edges.top().second.second)){
            unionParent(edges.top().second.first, edges.top().second.second);
            result += (-edges.top().first);
        }
        edges.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    while (T--){
        int N, weight; 
        result = 0;
        parent[0] = 0;
        
        cin >> N;
        for(int i = 1; i<=N; i++){
            cin >> weight;
            edges.push({-weight,{0,i}});
            parent[i] = i;
        }

        for(int i = 1; i<=N; i++){
            for(int k = 1; k<=N; k++){
                cin >> weight;
                if(i == k) 
                    continue;
                edges.push({-weight,{i,k}});
            }
        }

        kruskal();
        cout << result << '\n';

    }
}