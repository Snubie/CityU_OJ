#include <cstdio>
#include <cstring>
typedef long long ll;
using namespace std;

char cells[105];

bool isHealthy(int start, int end){
    if(start > end) // empty
        return false;
    if(start == end) // 1 char
        return cells[start] == 'A';

    if(cells[end-1] == 'A' && cells[end] == 'B')
        return isHealthy(start, end-2);
    if(cells[start] == 'B' && cells[end] == 'A')
        return isHealthy(start+1, end-1);
    return false;
}

void solve(int l){
    if(cells[l-1] == 'A' && cells[l] == 'B'){
        if(isHealthy(0,l-2))
            printf("FULLY-GROWN\n");
        else
            printf("MUTANT\n");
    } 
    else if(cells[0] == 'B' && cells[l] == 'A'){
        if(isHealthy(1,l-1))
            printf("MUTAGENIC\n");
        else
            printf("MUTANT\n");
    }
    else
        printf("MUTANT\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",&cells);
        if(strlen(cells) == 1){
            if(cells[0] == 'A')
                printf("SIMPLE\n");
            else
                printf("MUTANT\n");
        }else{
            solve(strlen(cells)-1);
        }
    }
    return 0;
}