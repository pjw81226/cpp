#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        int score[30];
        int homework[30];
        int teamscore[30];  
        int N, M, teamcount;

        cin >> N >> M;
        for(int i = 0; i <N; i++){
            cin >> score[i];
        }
        for(int i = 0; i< M; i++ ){
            cin >> homework[i];
        }

        for(int i = 0; i< M; i++){
            cin >> teamcount;
            int bastard =987654231;
            char student;
            for(int k = 0; k<teamcount; k++){
                cin >> student;
                bastard = min(bastard, score[student-'A']);
            }
            teamscore[i] = homework[i] * bastard;
        }

        for(int i = 0; i< M; i++){
            cout << teamscore[i] << ' ';
        }
        cout << '\n';
    }
}