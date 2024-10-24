#include<iostream>
#include<queue>
using namespace std;

vector<pair<int,int>> graph[1001];
int dist[1001];
int N,M,a,b,x,y,K,customer;
const int MAX = 987654321;


void fillMAX(){
    for(int i = 0; i<1001; i++){
        dist[i]= MAX;
    }
}

void dijkstra(int root){
    priority_queue<pair<int,int>> pq;
    dist[root]=0;
    pq.push({0,root});
    while(!pq.empty()){
        int curTime = -pq.top().first;
        int curNode = pq.top().second;
        pq.pop();
        
        if(curTime > dist[curNode]) continue;

        for(int i = 0; i<graph[curNode].size(); i++){
            int nextTime = curTime + graph[curNode][i].first;
            int nextNode = graph[curNode][i].second;

            if(nextTime < dist[nextNode]){
                dist[nextNode] = nextTime;
                pq.push({-nextTime,nextNode});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i<M; i++){
            cin >> a >> b >> x >> y;
            graph[a].push_back({x,b});
            graph[b].push_back({y,a});
        }
            
        int answer = -1;
        cin >> K;
        for(int i = 0; i < K; i++){
            int customer, fromOne, totalDist;
            cin >> customer;
            fillMAX();
            dijkstra(1);
            fromOne = dist[customer];
            
            fillMAX();
            dijkstra(customer);
            totalDist = fromOne + dist[1];

            answer = max(answer, totalDist);
        }

        cout << answer << '\n';

        //clear
        for(int i = 0; i<=N;i++){
            graph[i].clear();
        }
    }
}