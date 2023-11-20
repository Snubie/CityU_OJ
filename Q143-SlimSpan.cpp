#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

class Edge{
    public:
    int from, to, dist;
    
    Edge(int f, int t, int d){
        from = f;
        to = t;
        dist = d;
    }
};

vector<int> dset;
vector<int> lock;
vector<Edge> edgelist;

int find(int d){
    if(dset[d] == -1)
        return d;
    return dset[d] = find(dset[d]); 
}

bool join(int a, int b){
    int ga = find(a);
    int gb = find(b);
    if(ga != gb){
        dset[gb] = ga;
        return true;
    }
    return false;
}

bool compare(const Edge &a, const Edge &b){
    return a.dist < b.dist;
} 

int mst(int n){

    sort(edgelist.begin(), edgelist.end(), compare);
    int size = edgelist.size(), ans = 0x7fffffff;

    for(int i = 0 ; i < size ; i++){
        int time = n - 1, tmp = -1;
        dset = vector<int>(n+5, -1);

        for(int j = i ; j < size ; j++){
            Edge edge = edgelist[j];
            bool flag = join(edge.from,edge.to);

            if(flag){
                time--;
                if(time == 0){
                    ans = min(ans, edgelist[j].dist - edgelist[i].dist);
                    break;
                }
            }
        }
    }

    return ans;
}

void solve(int n, int m){

    edgelist = vector<Edge>();

    for(int i = 0 ; i < m ; i++){
        int a , b , w;
        scanf("%d %d %d",&a ,&b, &w);
        edgelist.push_back(Edge(a-1, b-1, w));
    }

    int ans = mst(n);
    if(ans != 0x7fffffff){
        printf("%d\n",ans);
    }else{
        printf("-1\n");
    }
}

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) && (n != 0 || m != 0)){
        solve(n, m);
    }
    return 0;
}