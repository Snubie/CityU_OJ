#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;

int dp[1005][50];
vector<int> price;
vector<int> weight; 

int main(){
    int t;
    scanf("%d",&t);
    while(t--){

        memset(dp,0,sizeof(dp));
        price.clear();
        weight.clear();

        int n , g , p , w , mw, ans = 0; 
        scanf("%d",&n);
        for(int i = 0 ; i < n ; i++){
            scanf("%d %d", &p, &w);
            price.push_back(p);
            weight.push_back(w);
        }

        for(int i = 1 ; i <= n; i++){
            for(int j = 1 ; j <= 30; j++){
                if(j < weight[i - 1])
                    dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i - 1][j - weight[i - 1]]+price[i - 1]
                    );
                }
            }    
        }

        scanf("%d",&g);
        for(int i = 0 ; i < g ; i++){
            scanf("%d", &mw);;
            ans += dp[n][mw];
        }
        printf("%d\n",ans);
    }
    return 0;
}