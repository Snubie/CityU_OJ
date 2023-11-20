#include <cstdio>
#include <cstring>
using namespace std;

void solve(int n, int m, int q){
    int board[n][m];  
    for(int i = 0 ; i < n ; i++){
        for (int j = 0; j < m; j++){
            scanf("%d", &board[i][j]);
        }
    }

    int r1, c1, r2, c2, h, w;
    for(int i = 0 ; i < q ; i++){
        scanf("%d %d %d %d %d %d",&r1,&c1,&r2,&c2,&h,&w);

        //offset of array
        r1 -= 1; c1 -= 1;
        r2 -= 1; c2 -= 1;

        for(int j = 0 ; j < h ; j++){
            int temparr[w];
            memcpy(temparr, board[r1+j]+c1, w*sizeof(int));
            memmove(board[r1+j]+c1, board[r2+j]+c2, w*sizeof(int));
            memmove(board[r2+j]+c2, temparr, w*sizeof(int));
        }
    }

    for(int i = 0 ; i < n ; i++){
        for (int j = 0 ; j < n ; j++){
            if(j != 0)
                printf(" ");
            printf("%d", board[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, m, q;
    while(scanf("%d %d %d",&n, &m, &q) != EOF)
        solve(n,m,q);
    return 0;
}