#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 1005
using namespace std;

vector<int> map[MAX];
vector<int> loc;
vector<int> arrive(MAX,0);
bool visited[MAX];
int k, n, m, c = 0;

void dfs(int start){
    arrive[start]++;
    if(arrive[start] == k)
        c++;
    visited[start] = true;
    for(int i = 0 ; i < map[start].size() ; i++)
        if(!visited[map[start][i]])
            dfs(map[start][i]);
}

void solve(int k, int n, int m){

    for(int i = 0 ; i < k ; i++){
        int temp;
        scanf("%d",&temp);
        loc.push_back(temp);
    }

    for(int i = 0 ; i < m ; i++){
        int t1, t2;
        scanf("%d %d",&t1, &t2);
        map[t1].push_back(t2);
    }

    for(int i = 0 ; i < k ; i++){
        memset(visited, false, MAX * sizeof(bool));
        dfs(loc[i]);
    }

    printf("%d\n",c);  
}

int main(){
    scanf("%d %d %d",&k, &n, &m);
    solve(k, n, m);
    return 0;
}