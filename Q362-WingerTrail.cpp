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
    vector<int> parent(n);

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

int solve(int l, int w, int n, int d){
    adj = vector<vector<int> >(n*2+2, vector<int>(n*2+2, 0));

    // node capacity
    for(int i = 1 ; i <= n ; i++){
        adj[i][n+i] = 1;  // i = in, n+i = out
        adj[n+i][i] = 1;
    }

    vector<pair<int, int> > coor; 
    for(int i = 1 ; i <= n ; i++){
        int x, y;
        scanf("%d %d",&x, &y);
        if(y - d <= 0)
            adj[0][i] = 1;
        if(y + d >= w)
            adj[n+i][2*n+1] = 1;

        for(int j = 0 ; j < coor.size() ; j++){
            // detect two circle intercept
            int px = coor[j].first - x;
            int py = coor[j].second - y;
            if(px * px + py * py <= d * d * 4){
                adj[n+i][j+1] = 1;
                // adj[j+1][n+i] = 1;

                adj[n+j+1][i] = 1;
                // adj[i][n+j+1] = 1;
            }
        }
        coor.push_back(make_pair(x, y));
    }

    return maxflow(0, 2*n+1, 2*n+2);
}

int main(){
    int l, w, n, d, i = 1;
    while(scanf("%d %d %d %d",&l, &w, &n, &d) && l != 0){
        int ans = solve(l, w, n, d);
        printf("Case %d: %d\n", i++, ans);
    }
    return 0;
}