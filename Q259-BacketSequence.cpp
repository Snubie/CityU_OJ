#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

char s[105], tmp[105];
int dp[105][105];

int solvedp(int start, int end){
    if(dp[start][end])
        return dp[start][end];
    if(start > end)
        return 0;
    if(start == end)
        return dp[start][end] = 2;
    if(start + 1 == end)
        return dp[start][end] = (s[start] == '(' && s[end] == ')') || (s[start] == '[' && s[end] == ']') ? 2 : 4;

    int minvalue = 0x7fffffff;

    if((s[start] == '(' && s[end] == ')') || (s[start] == '[' && s[end] == ']'))
        minvalue = solvedp(start+1, end-1)+2;

    for(int i = start ; i < end ; i++){
        minvalue = min(
            minvalue,
            solvedp(start,i) + solvedp(i+1,end)
        );
    }

    return dp[start][end] = minvalue;
}

void solve(){
    memset(dp,0,sizeof(dp));
    //scanf("%s",s);
    
    int len = strlen(s);
    printf("%d\n", solvedp(0,len-1));
}

int main(){
    // who will know you need to into input like this 
    // if you dont search from internet
    int t;
    char s[105], tmp[105];
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(tmp);
        gets(s);
        solve();
        if(t)
            printf("\n");
    }
    return 0;
}