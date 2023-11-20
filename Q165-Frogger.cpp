#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
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
vector<pair<int, int> > stoneloc;
vector<Edge> edgelist;

int find(int d){
    if(d == dset[d])
        return d;
    return dset[d] = find(dset[d]); 
}

void join(int a, int b){
    int ga = find(a);
    int gb = find(b);
    if(ga != gb){
        dset[gb] = ga;
    }
}

bool compare(const Edge &a, const Edge &b){
    return a.dist < b.dist;
} 

double mst(int n){

    sort(edgelist.begin(), edgelist.end(), compare);
    int i = 0, min = 0x7fffffff;
    while(find(0) != find(1)){
        Edge e = edgelist[i];
        
        if (e.to > e.from) swap(e.from, e.to);

        join(e.from, e.to);
        min = e.dist;
        i++;
    }
    return sqrt(min);
}

double solve(int n){

    dset = vector<int>(n);
    stoneloc = vector<pair<int, int> >(n);
    edgelist = vector<Edge>();

    for(int i = 0 ; i < n ; i++){

        dset[i] = i;

        scanf("%d %d", &stoneloc[i].first, &stoneloc[i].second);
        for(int j = 0 ; j < i ; j++){
            int d1 = (stoneloc[i].second - stoneloc[j].second);
            int d2 = (stoneloc[i].first - stoneloc[j].first);
            int dist = d1 * d1 + d2 * d2;
            edgelist.push_back(Edge(j, i, dist));
        }
    }
    return mst(n);
}

int main(){
    
    int n, i = 1;
    while(scanf("%d",&n) != EOF){
        if(n == 0) break;
        double ans = solve(n);
        printf("Scenario #%d\n",i);
        printf("Frog Distance = %.3f\n",ans);
        printf("\n");
        i++;
    }
    return 0;
}