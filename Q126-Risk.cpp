#include <cstdio>
#include <vector>
#include <deque>
typedef long long ll;
using namespace std;

vector<vector<int> > adj = vector<vector<int> >(21);

// dist = 1, no dijkstra needed
int bfs(int a, int b){
    deque<int> q, lvl;
    vector<bool> visited(20,false);
    q.push_back(a);
    lvl.push_back(0);
    visited[a] = true;
    while(!q.empty()){
        for(int i = 0 ; i < adj[q[0]].size() ; i++){
            int index = adj[q[0]][i];
            if(index == b)
                return lvl[0]+1;
            
            if(!visited[index]){
                visited[index] = true;
                q.push_back(index);
                lvl.push_back(lvl[0]+1);
            }
        }
        q.pop_front();
        lvl.pop_front();
    }
    return -1;
}

int main(){
    int firstele, testset = 1;
    while(scanf("%d",&firstele) != EOF){

        for(int i = 0 ; i < firstele ; i++){
            int dist;
            scanf("%d",&dist);
            adj[1].push_back(dist);
            adj[dist].push_back(1);
        }
        
        for(int i = 2 ; i < 20 ; i++){
            int num;
            scanf("%d",&num);
            for(int j = 0 ; j < num ; j++){
                int dist;
                scanf("%d",&dist);
                adj[i].push_back(dist);
                adj[dist].push_back(i);
            }
        }

        int n;
        scanf("%d",&n);
        printf("Test Set #%d\n",testset);
        for(int i = 0 ; i < n ; i++){
            int a, b;
            scanf("%d %d",&a,&b);
            printf("%2d to %2d: %d\n",a,b,bfs(a,b));
        }

        printf("\n");
        adj = vector<vector<int> >(21);
        testset++;
    }
    return 0;
}