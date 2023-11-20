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
    return a.dist < b.dist;
} 

vector<int> dset;
vector<Edge> edgelist;

int find(int a){
    if(dset[a] == a)
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

void solve(int n, int m){
    dset = vector<int>(n+5);
    edgelist = vector<Edge>();
    vector<int> unused;

    for(int i = 0 ; i < n+1 ; i++){
        dset[i] = i;
    }

    for(int i = 0 ; i < m ; i++){
        int s, e, d;
        scanf("%d %d %d",&s, &e, &d);
        edgelist.push_back(Edge(s, e, d));
    }

    sort(edgelist.begin(), edgelist.end(), compare);
    int city = n;
    ll min = 0;
    for(int i = 0 ; i < m ; i++){
        if(city == 1){
            unused.push_back(edgelist[i].dist);
            continue;
        }
        bool res = join(edgelist[i].start, edgelist[i].end);
        if(res){
            min += edgelist[i].dist;
            city--;
        }else{
            unused.push_back(edgelist[i].dist);
        }
    }

    if(city == 1){
        printf("Min cost: %d\n",min);
        sort(unused.begin(), unused.end());
        for(int i = 0 ; i < unused.size() ; i++){
            if(i != 0)
                printf(" ");
            printf("%d",unused[i]);
        }
        printf("\n");
    }else
        printf("\\(^o^)/ pray to god\n");
}


int main(){
    int n, m;
    while(scanf("%d %d",&n, &m) && (n != 0 || m != 0)){
        solve(n, m);
    }
    return 0;
}