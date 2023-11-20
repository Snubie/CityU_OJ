#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

struct Pad{
    double color;
    int x, y, r;
};

bool intercept(Pad a, Pad b){
    double x = a.x - b.x, y = a.y - b.y, r = a.r + b.r;
    return x * x + y * y <= r * r;
}

vector<vector<int> > adj;

int bfs(int start, int end, vector<int> &parent){
    fill(parent.begin(), parent.end(), -1);
    parent[start] = -2;

    queue<int> q;
    q.push(start);
    q.push(0x7fffffff);

    while(!q.empty()){
        int current = q.front(); q.pop();
        int flow = q.front(); q.pop();

        for(int i = 0 ; i < adj[current].size() ; i++){
            if(parent[i] == -1 && adj[current][i]){
                parent[i] = current;
                int nflow = min(flow, adj[current][i]);
                if(i == end)
                    return nflow;
                q.push(i);
                q.push(nflow);
            }
        }
    }

    return -1;
}

int maxflow(int start, int end, int n){
    int flow = 0;
    vector<int> parent(n);

    while(true){
        int nflow = bfs(start, end, parent);
        if(nflow == -1)
            break;
        
        flow += nflow;
        if(flow >= 2)
            break;

        int current = end;
        while(current != start){
            int prev = parent[current];
            adj[prev][current] -= nflow;
            adj[current][prev] += nflow;
            current = prev;
        }
    }

    return flow;
}

void solve(){
    int n;
    scanf("%d",&n);

    adj = vector<vector<int> >(n, vector<int>(n, 0));
    vector<Pad> padlist(n);
    int sindex = 0, tindex = 0;

    for(int i = 0 ; i < n ; i++){
        scanf("%lf %d %d %d",&padlist[i].color, &padlist[i].x,  &padlist[i].y,  &padlist[i].r);
        if(padlist[i].color == 400)
            sindex = i;
        if(padlist[i].color == 789)
            tindex = i;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = i + 1 ; j < n ; j++){
            if(intercept(padlist[i],padlist[j])){
                if(padlist[i].color < padlist[j].color){
                    adj[i][j] = 1;
                }else{
                    adj[j][i] = 1;
                }
            }
        }
    }

    int ans = maxflow(sindex, tindex, n);
    if(ans >= 2)
        printf("Game is VALID\n");
    else
        printf("Game is NOT VALID\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}