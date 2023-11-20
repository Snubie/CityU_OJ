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

int solve(int n){
    adj = vector<vector<int> >(n+1, vector<int>(n+1, 0));

    int start, end, num;
    scanf("%d %d %d",&start, &end, &num);

    for(int i = 1 ; i <= num ; i++){
        int s, e, flow;
        scanf("%d %d %d",&s, &e, &flow);

        adj[s][e] += flow;
        adj[e][s] += flow;
    }

    return maxflow(start, end, n);
}

int main(){
    int t;
    int i = 1;
    while(scanf("%d",&t) && t != 0){
        int ans = solve(t);
        printf("Network %d\n",i);
        printf("The bandwidth is %d.\n\n",ans);
        i++;
    }
    return 0;
}