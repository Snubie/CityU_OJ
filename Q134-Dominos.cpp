#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;

class Node{
    public:
    vector<int> to;

    Node(){
    }

    void addNode(int loc){
        to.push_back(loc);
    }
};

vector<Node*> list(10005);
vector<bool> visited;
int ans;

void dfs(int v) {
    if(visited[v])
        return;
    
    visited[v] = true;
    ans++;
    for(int i = 0 ; i < list[v]->to.size() ; i++){
        dfs(list[v]->to[i]);
    }
}

void solve(){
    ans = 0;
    int n, m, l;
    scanf("%d %d %d", &n, &m, &l);

    visited = vector<bool>(n+1, false);
    for(int i = 1 ; i <= n ; i++){
        list[i] = new Node();
    }

    for(int i = 0 ; i < m ; i++){
        int from, to;
        scanf("%d %d",&from, &to);
        list[from]->addNode(to);
    }

    for(int i = 0 ; i < l ; i++){
        int temp;
        scanf("%d",&temp);
        dfs(temp);
    }
    printf("%d\n",ans);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}