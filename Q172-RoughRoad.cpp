#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector<vector<pair<int, int> > > adj; 

int dijkstra(int n){
    vector<int> dist(n, 0x7fffffff), loc(n,-1);
    vector<bool> checked(n, false);

    dist[0] = 0; // start pos
    for(int i = 0 ; i < n ; i++){
        
        //find minimum path
        int v = -1;
        for(int j = 0 ; j < n ; j++){
            if(!checked[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if(dist[v] == 0x7fffffff)
            break;

        checked[v] = true;

        //calculate next path
        for(int j = 0 ; j < adj[v].size() ; j++){
            int to = adj[v][j].first;
            int len = adj[v][j].second;

            if(dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                loc[to] = len;
            }
        }
    }

    return dist[(n / 2) - 1];
}

int solve(int n, int r){
    adj.clear();
    adj.assign(n * 2,vector<pair<int, int> >());

    int ans = 0;
    int st, en, len;
    for(int i = 0 ; i < r ; i++){
        scanf("%d %d %d", &st, &en, &len);

        adj[st].push_back(make_pair(en + n, len));
        adj[en + n].push_back(make_pair(st, len));

        adj[st + n].push_back(make_pair(en, len));
        adj[en].push_back(make_pair(st + n, len));
    }

    ans = dijkstra(2*n);
    return ans;
}

int main(){
    
    int n, r, i = 1;
    while(scanf("%d %d",&n, &r) != EOF){
        int ans = solve(n, r);
        printf("Set #%d\n",i);
        if(ans != 0x7fffffff){
            printf("%d\n",ans);
        }else{
            printf("?\n",ans);
        }
        i++;
    }
    return 0;
}