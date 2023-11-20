#include <cstdio>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;

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
    vector<int> parent(n+1);

    while(true){
        int nflow = bfs(start, end, parent);
        if(nflow == -1)
            break;
        
        flow += nflow;
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

void solve(int n, int p){
    adj = vector<vector<int> >(n+p+2, vector<int>(n+p+2, 0));
    int totalsum = 0;

    for(int i = 1 ; i <= p ; i++){
        adj[0][i] = 1;
    }

    for(int i = 1 ; i <= n ; i++){
        int flow;
        scanf("%d", &flow);
        adj[p+i][n+p+1] = flow;
        totalsum += flow;
    }

    for(int i = 1 ; i <= p ; i++){
        int size;
        scanf("%d", &size);
        for(int j = 0 ; j < size ; j++){
            int type;
            scanf("%d", &type);
            adj[i][p+type] = 1;
        }
    }

    int ans = maxflow(0, n+p+1, n+p+2);
    if(ans == totalsum)
        printf("1\n");
    else
        printf("0\n");
}

int main(){
    int n, p;
    while(scanf("%d %d",&n, &p) && n != 0 && p != 0){
        solve(n, p);
    }
    return 0;
}