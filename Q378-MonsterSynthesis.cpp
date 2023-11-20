#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

class State{
    public:
    int loc, curr, minl, maxl;
    State(int l = 0, int c = 0, int mi = 0, int ma = 0){
        loc = l;
        curr = c;
        minl = mi;
        maxl = ma;
    }

    bool operator< (const State &a) const{
        return curr > a.curr;
    }
};

vector<int> cost, level;
vector<vector<pair<int, int> > > adj; 

void solve(int m, int n){

    adj = vector<vector<pair<int, int> > >(n+1);
    cost = vector<int>(n+1, 0);
    level = vector<int>(n+1, 0);

    int minv = 0x7fffffff;

    for(int i = 1 ; i <= n ; i++){
        int p , l , x;
        scanf("%d %d %d",&p, &l, &x);

        cost[i] = p;
        level[i] = l;

        for(int j = 0 ; j < x ; j++){
            int t , v;
            scanf("%d %d", &t, &v);
            adj[t].push_back(make_pair(i, v));
        }
    }

    priority_queue<State> q;
    for(int i = 1 ; i <= n ; i++){
        q.push(State(i, cost[i], level[i], level[i]));
    }

    // bfs priority queue
    while(!q.empty()){
        State s = q.top(); q.pop();
        if(s.loc == 1){
            printf("%d\n", s.curr);  
            return;
        }
        for(int i = 0 ; i < adj[s.loc].size() ; i++){
            int loc = adj[s.loc][i].first;
            int price = adj[s.loc][i].second;

            if(abs(s.maxl - level[loc]) <= m && abs(s.minl - level[loc]) <= m){
                q.push(State(loc, s.curr + price, min(s.minl, level[loc]), max(s.maxl, level[loc])));
            }
        }
    }
}

int main(){
    int m, n;

    while(scanf("%d %d",&m, &n) != EOF){
        solve(m, n);
    }
    return 0;
}