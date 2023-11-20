#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int dp[6][8000] = {0};
int values[6] = {0,1,5,10,25,50};

int solve(int now, int layer){
    if(now < 0)
        return 0;
    if(layer == 0)
        return dp[0][now];
    if(dp[layer][now])
        return dp[layer][now];
    return dp[layer][now] = solve(now, layer-1) + solve(now-values[layer], layer);
}

int main(){

    int t;

    // base case
    for(int i = 0 ; i < 6 ; i++){
        dp[i][0] = 1;
    }
    
    while(scanf("%d",&t) != EOF){

        solve(t, 5);
        printf("%d\n",dp[5][t]);
    }
    return 0;
}