#include<unordered_map>
#include<iostream>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        unordered_map<string, int> playerScore1; //name, score;
        unordered_map<string, int> playerScore2; //name, score;
        string entry1[11];
        string entry2[11];

        int n, team1score, team2score, prevteam1score = 0, prevteam2score = 0;
        int team1Count = 0, team2Count = 0;
        string goalPlayer;
        
        cin >> n;
        for(int i = 0; i<n; i++){
            cin >> team1score >> team2score >> goalPlayer;
            if(team1score > prevteam1score){
                if(playerScore1[goalPlayer] == 0){
                    entry1[team1Count] = goalPlayer;
                    team1Count++;
                }
                playerScore1[goalPlayer] += (team1score - prevteam1score);
                prevteam1score = team1score;
            }   
            else{
                if(playerScore2[goalPlayer] == 0){
                    entry2[team2Count] = goalPlayer;
                    team2Count++;
                }
                playerScore2[goalPlayer] += (team2score - prevteam2score);
                prevteam2score = team2score;
            }
        }

        string mvp;
        int maxScore = 0;
        if(team1score > team2score){
            for(int i = 0; i < team1Count; i++){
                if(maxScore < playerScore1[entry1[i]]){
                    mvp = entry1[i];
                    maxScore = playerScore1[entry1[i]];
                }
            }
        }
        else{
            for(int i = 0; i < team2Count; i++){
                if(maxScore < playerScore2[entry2[i]]){
                    mvp = entry2[i];
                    maxScore = playerScore2[entry2[i]];
                }
            }
        }
        cout << mvp << " " << maxScore << '\n';
    }
}