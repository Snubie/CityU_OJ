#include <cstdio>
#include <vector>
#define MAX 1005
using namespace std;

class Station{
public:
    int level;
    vector<int> inBetween;

    Station(){
        level = 1;
    }

    void addBetween(int s){
        inBetween.push_back(s);
    }
};

int n, m;
vector<Station> stations(MAX);
// topological order
vector<vector<bool> > bgraph(MAX,vector<bool>(MAX,false));
vector<bool> dfscheck(MAX,false);
vector<int> order;

// use for topological order
int dfs(int index){
    if(dfscheck[index]){
        return stations[index].level;
    }
    dfscheck[index] = true;

    for(int i = 0 ; i < stations[index].inBetween.size() ; i++){
        int slevel = dfs(stations[index].inBetween[i]) + 1;
        if(slevel > stations[index].level)
            stations[index].level = slevel;
    }

    order.push_back(index);
    return stations[index].level;
}

void build(){
    for(int i = 1 ; i <= m ; i++){
        int temp;
        int start = 1;
        vector<int> t;
        vector<int> nt;
        scanf("%d",&temp);
        for(int j = 0 ; j < temp ; j++){
            int value;
            scanf("%d",&value);
            t.push_back(value);
        }
        //graph plotting
        int index = 1, ntsize = 0;
        for(int j = t[0] + 1; j < t[temp-1] ; j++){
            while(j != t[index]){
                nt.push_back(j);
                j++;
                ntsize++;
            }
            index++;
        }
        for(int j = 0 ; j < ntsize ; j++){
            for(int k = 0 ; k < temp ; k++){
                bgraph[nt[j]][t[k]] = true;
            }
        }
    }

    // change bgraph to conn graph
    for(int j = 1 ; j <= n ; j++){
        for(int k = 1 ; k <= n ; k++){
            if(bgraph[j][k])
                stations[j].addBetween(k);
        }
    }

    // topological order & calculate
    for(int i = 1 ; i <= n ; i++){
        if (!dfscheck[i])
            dfs(i);
    }

    int max = 0;
    for(int i = 0 ; i < n ; i++){
        max = stations[order[i]].level > max ? stations[order[i]].level : max;
    }
    printf("%d\n",max);
}

int main(){
    scanf("%d %d",&n,&m);
    build();
    return 0;
}