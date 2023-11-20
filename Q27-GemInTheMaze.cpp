#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;

class Node{
    public:
    int to;
    int val;

    Node(){
        to = 0;
        val = 0;
    }
    void addTo(int n){
        to = n;
    }
};

vector<Node*> loc(305);
vector<bool> visited;

int dfs(int v) {
    if(visited[v])
        return 0;
    
    visited[v] = true;
    return dfs(loc[v]->to) + 1;
}

void solve(){
    int a, b, c, n;
    scanf("%d %d %d %d",&a, &b, &c, &n);

    for(int i = 0 ; i < n ; i++){
        loc[i] = new Node();
        loc[i]->addTo((a*i*i+b*i+c)%n);
    }
    int max = 0;
    for(int i = 0 ; i < n ; i++){
        visited = vector<bool>(305,false);
        int gem = dfs(i);
        max = gem > max ? gem : max;
    }
    printf("%d\n",max);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}