#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Edge{
    int from, to, dist;
};

bool compare(const Edge &a, const Edge &b){
    return b.dist < a.dist;
}

vector<int> dset;
vector<Edge> edgelist;

int find(int a){
    if(dset[a] == -1)
        return a;
    return dset[a] = find(dset[a]);
}

bool join(int a, int b){
    int i = find(a);
    int j = find(b);
    if(i != j){
        dset[j] = i;
        return true;
    }
    return false;
}

int mst(int n){

    sort(edgelist.begin(), edgelist.end(), compare);

    int times = n - 1, ans = -1;
    
    for(int i = 0 ; i < edgelist.size() ; i++){
        bool flag = join(edgelist[i].from, edgelist[i].to);

        if(flag){
            times--;
            if(times == 0){
                return edgelist[i].dist;
            }
        }
    } 
    return 0;
}

int solve(){
    int n , m;
    scanf("%d %d",&n, &m);

    dset = vector<int>(n+5, -1);
    edgelist = vector<Edge>(m);

    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d",&edgelist[i].from, &edgelist[i].to, &edgelist[i].dist);
    }  

    return mst(n);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++){
        int ans = solve();
        printf("Case #%d: %d\n",i+1,ans);
    }
    return 0;
}