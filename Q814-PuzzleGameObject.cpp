#include <cstdio>
#define MAX 1002
using namespace std;

struct Node{
    int value;
    Node *right, *down;
    Node() { 
        value = -1;
        right = NULL; 
        down = NULL; 
    }
};

Node board[MAX][MAX];

Node* find(int top, int left){
    Node* loc = &board[0][0];
    while(--top){
        loc = loc->down;
    }
    while(--left){
        loc = loc->right;
    }
    return loc;
}

int main(){
    for(int i = 0 ; i < MAX - 1 ; i++){
        for(int j = 0 ; j < MAX - 1 ; j++){
            board[i][j].right = &board[i][j+1];
            board[i][j].down = &board[i+1][j];
        }
    }

    int n, m, q;
    Node *start;
    while(scanf("%d %d %d",&n, &m, &q) != EOF){ 

        for(int i = 1 ; i <= n ; i++){
            Node *rowstart = board[i][0].right;
            for(int j = 1 ; j <= m ; j++){
				scanf("%d", &rowstart->value);
                rowstart = rowstart->right;
            }
        }

        for(int i = 0 ; i < q ; i++){
            int r1, c1, r2, c2, h, w;
            scanf("%d %d %d %d %d %d",&r1 ,&c1 ,&r2 ,&c2 ,&h, &w);
                Node *block1 = find(r1, c1);
                Node *block2 = find(r2, c2);
                Node *tmp;

                Node *start1 = block1;
                Node *start2 = block2;

                for(int j = 0 ; j < w ; j++){
                    start1 = start1->right;
                    start2 = start2->right;

                    tmp = start1->down;
                    start1->down = start2->down;
                    start2->down = tmp;
                }

                for(int j = 0 ; j < h ; j++){
                    start1 = start1->down;
                    start2 = start2->down;

                    tmp = start1->right;
                    start1->right = start2->right;
                    start2->right = tmp;
                }

                start1 = block1;
                start2 = block2;

                for(int j = 0 ; j < h ; j++){
                    start1 = start1->down;
                    start2 = start2->down;

                    tmp = start1->right;
                    start1->right = start2->right;
                    start2->right = tmp;
                }

                for(int j = 0 ; j < w ; j++){
                    start1 = start1->right;
                    start2 = start2->right;

                    tmp = start1->down;
                    start1->down = start2->down;
                    start2->down = tmp;
                }
        }
        
        for(int i = 1 ; i <= n ; i++){
            Node *rowstart = board[i][0].right;
            printf("%d", rowstart->value);
            for(int j = 1 ; j < m ; j++){
                rowstart = rowstart->right;
                printf(" %d", rowstart->value);
            }
            printf("\n");
        }
    }
    return 0;
}