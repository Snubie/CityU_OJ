#include <cstdio>
#include <cstring>

unsigned char dp[51][51][51][51];
bool visited[51][51][51][51];
char arr[51][51];

int max(int a, int b){
    return a > b ? a : b;
}

bool isDonut(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2 ; i++)
        if(arr[y1][i] == '.' || arr[y2][i] == '.')
            return false;
    
    for(int i = y1; i <= y2 ; i++)
        if(arr[i][x1] == '.' || arr[i][x2] == '.')
            return false;

    return true;
}

int solve(int x1, int y1, int x2, int y2){
    if(x2 - x1 + 1 < 3 || y2 - y1 + 1 < 3)
        return 0;
    if(visited[x1][y1][x2][y2])
        return dp[x1][y1][x2][y2];
    
    if(isDonut(x1,y1,x2,y2)){
        visited[x1][y1][x2][y2] = true;
        return dp[x1][y1][x2][y2] = solve(x1 + 1 , y1 + 1 , x2 - 1 , y2 - 1) + 1;
    }else{
        int a = solve(x1 + 1 , y1 , x2 , y2);
        int b = solve(x1 , y1 + 1 , x2 , y2);
        int c = solve(x1 , y1 , x2 - 1 , y2);
        int d = solve(x1 , y1 , x2 , y2 - 1);

        visited[x1][y1][x2][y2] = true;
        return dp[x1][y1][x2][y2] = max(max(a,b), max(c,d));
    }
}

int main(){

    int t, i = 1;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d",&n);

        for(int i = 0 ; i < n ; i++){
            scanf("%s",arr[i]);
        }

        int len = strlen(arr[0]);

        memset(dp, 0, sizeof(dp));
        memset(visited, 0, sizeof(visited));
        solve(0, 0, len-1, n-1);
        printf("Case #%d: %d\n",i++ , dp[0][0][len-1][n-1]);
    }

    return 0;
}