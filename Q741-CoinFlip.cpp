#include <cstdio>
#include <cstring>
using namespace std;

bool board[100][10];
int row[100];
int n , m;
int ans;

void flip(int c){
    for(int i = 0 ; i < n ; i++){
        row[i] += board[i][c] ? -1 : 1 ;
        board[i][c] = !board[i][c];
    }
}

void count(){
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        count += row[i] > m - row[i] ? row[i] : m - row[i];
    }
    if(count > ans)
        ans = count;
}

void solve(int i){
    if( i < m ){
        solve(i+1);
        flip(i);
        count();
        solve(i+1);
    }
}

void build(int n, int m){
    for(int i = 0 ; i < n ; i++){
        char temp[11];
        scanf("%s",temp);
        for (int j = 0; j < m; j++){
            board[i][j] = temp[j] == '1';
            if(board[i][j])
                row[i]++;
        }
    }
    solve(0);
    printf("%d\n", ans);
}

int main(){
    while(scanf("%d %d",&n, &m) != EOF){
        ans = 0;
        memset(row, 0, 100*sizeof(int));
        build(n,m);
    }
    return 0;
}