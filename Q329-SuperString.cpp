#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

char s1[1005], s2[1005];
int dp[1005][1005];

void solve(){
    scanf("%s", s1);
    scanf("%s", s2);
    memset(dp,0,sizeof(dp));

    int l1 = strlen(s1), l2 = strlen(s2);

    // base case
    for(int i = 0 ; i <= l1 ; i++){
        dp[0][i] = i;
    }
    for(int i = 0 ; i <= l2 ; i++){
        dp[i][0] = i;
    }

    for(int i = 1 ; i <= l1 ; i++){
        for(int j = 1 ; j <= l2 ; j++){
            if(s1[i - 1] == s2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = min(
                    dp[i - 1][j] + 1,
                    dp[i][j - 1] + 1
                );
            }
        }
    }
    printf("%d\n",dp[l1][l2]);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}