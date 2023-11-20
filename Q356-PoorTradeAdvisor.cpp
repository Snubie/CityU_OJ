#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

class Edge{
    public:
    int start, end, dist;
    Edge(int s, int e, int d){
        start = s;
        end = e;
        dist = d;
    }
};

bool compare(const Edge &a, const Edge &b){
    return b.dist < a.dist;
} 

vector<int> dset;
vector<int> num;
vector<Edge> edgelist;

int find(int a){
    if(dset[a] == a)
        return a;

    return dset[a] = find(dset[a]);
}

int join(int a, int b){
    int i = find(a);
    int j = find(b);
    if(i != j){
        dset[j] = i;
        num[i] += num[j];
        return num[i];
    }
    return -1;
}

void solve(int n, int m){
    dset = vector<int>(n+5);
    num = vector<int>(n+5,1);
    edgelist = vector<Edge>();

    int ans = 0, tmp = 0;

    for(int i = 0 ; i < n+1 ; i++){
        dset[i] = i;
    }

    for(int i = 0 ; i < m ; i++){
        int s, e, d;
        scanf("%d %d %d",&s, &e, &d);
        edgelist.push_back(Edge(s, e, d));
    }

    sort(edgelist.begin(), edgelist.end(), compare);

    Edge maxEdge = edgelist[0];
    for(int i = 0 ; i < m && edgelist[i].dist == maxEdge.dist ; i++){
        tmp = join(edgelist[i].start, edgelist[i].end);
        ans = max(ans, tmp);
    }

    printf("%d\n",ans);
}


int main(){
    int n, m;
    while(scanf("%d %d",&n, &m) && (n != 0 || m != 0)){
        solve(n, m);
    }
}