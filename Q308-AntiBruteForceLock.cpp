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
    if(d == dset[d])
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

    int ans = 0;
    int time = n - 1;

    sort(edgelist.begin(), edgelist.end(), compare);
    int i = 0;
    while(time){
        Edge e = edgelist[i];
        bool flag = join(e.from, e.to);
        if(flag){
            time--;
            ans += e.dist;
        }
        i++;
    }
    return ans;
}

void solve(){
    int n, minv = 0x7fffffff;
    scanf("%d",&n);

    dset = vector<int>(505);
    lock = vector<int>();
    edgelist = vector<Edge>();

    for(int i = 0 ; i < n ; i++){

        dset[i] = i;

        char a, b, c, d;
        int va, vb, vc, vd;
        int num = 0, temp = 0, dif = 0;
        scanf(" %c%c%c%c",&a,&b,&c,&d);

        va = a - '0';
        vb = b - '0';
        vc = c - '0';
        vd = d - '0';

        num += va * 1000 + vb * 100 + vc * 10 + vd;

        temp += min(va, 10 - va);
        temp += min(vb, 10 - vb);
        temp += min(vc, 10 - vc);
        temp += min(vd, 10 - vd);
        minv = min(temp, minv);

        lock.push_back(num);

        for(int j = 0 ; j < i ; j++){
            int dist = 0;
            int diff = 0;

            diff = abs((lock[j] / 1000) - va);
            dist += min(diff,10 - diff);

            diff = abs(((lock[j] / 100) % 10) - vb);
            dist += min(diff,10 - diff);

            diff = abs(((lock[j] / 10) % 10) - vc);
            dist += min(diff,10 - diff);

            diff = abs((lock[j] % 10) - vd);
            dist += min(diff,10 - diff);

            edgelist.push_back(Edge(i, j, dist));
        }
    }
    
    int ans = mst(n);
    printf("%d\n", ans + minv);
}

int main(){
    
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}