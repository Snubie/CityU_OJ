#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 5005
typedef long long ll;
using namespace std;

// dinic implementation
class Edge{
    public:
    int from, to;
    ll cap, flow;
    Edge(int f = 0, int t = 0, ll c = 0){
        from = f ; to = t ; cap = c;
        flow = 0;
    }
};

vector<Edge*> edges;
vector<vector<int>> adj;
int nodes, ec,  cnt;
int src, sink;
int level[MAX], ptr[MAX];

void addEdge(int from, int to, ll cap){
    edges.push_back(new Edge(from, to, cap));
    adj[from].push_back(ec++);

    edges.push_back(new Edge(to, from, 0));
    adj[to].push_back(ec++);
}

bool bfs() {
    queue<int> q;
    memset(level, -1, sizeof(level));
    q.push(src);
    level[src] = 0;
    cnt = 0;

    while(!q.empty()){
        int v = q.front(); q.pop();
        cnt++;
        for(int i = 0 ; i < adj[v].size() ; i++){
            int id = adj[v][i];
            int to = edges[id]->to;

            if(level[to] == -1 && edges[id]->flow < edges[id]->cap){
                q.push(to);
                level[to] = level[v] + 1;
            }
        }
    }
    return level[sink] != -1;
}

ll dfs(int v, ll flow){
    if(!flow || v == sink)
        return flow;

    for( ; ptr[v] < adj[v].size() ; ptr[v]++){

        int id = adj[v][ptr[v]];
        int to = edges[id]->to;

        if(level[to] != level[v] + 1)
            continue;

        ll nflow = dfs(to, min(flow, edges[id]->cap - edges[id]->flow));
        if (nflow) {
            edges[id]->flow += nflow;
            edges[id^1]->flow -= nflow;
            return nflow;
        }
    }
    return 0;
}

ll maxflow(){
    ll flow = 0;
    while(bfs()){
        memset(ptr, 0, sizeof(ptr));
        flow += dfs(src, 0x7fffffff);
    }
    return flow;
}

void solve(int n, int m){

    nodes = n + 2;
    ec = 0;
    src = 0;
    sink = n + 1;
    edges.clear();
    adj = vector<vector<int> >(nodes);

    ll sum = 0, tmp = 0;

    for(int i = 1 ; i <= n ; i++){
        scanf("%lld", &tmp);
        if(tmp > 0){
            sum += tmp;
            addEdge(src,i,tmp);
        }else{
            addEdge(i,sink,-1 * tmp);
        }
    }

    for(int i = 0 ; i < m ; i++){
        int from, to;
        scanf("%d %d",&from, &to);
        addEdge(from, to, 0x7fffffff);
    }

    ll ans = maxflow();
    printf("%d %lld\n", cnt - 1, sum - ans);
}

int main(){
    int n, m;
    while(scanf("%d %d",&n, &m) != EOF){
        solve(n, m);
    }
    return 0;
}