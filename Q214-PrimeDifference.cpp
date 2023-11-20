#include <cstdio>
#include <vector>
#include <algorithm>
#define LIMIT 1299709 + 1
using namespace std;

int ans[200000] = {}, cnt = 0;
bool checked[LIMIT] = {};
void prime(){

    int i;
    for(i = 2 ; i * i < LIMIT ; i++){
        if(!checked[i]){
            ans[cnt++] = i;
            for(int j = i * i ; j < LIMIT ; j += i){
                checked[j] = true;
            }
        }
    }

    for( ; i < LIMIT ; i++){
        if(!checked[i])
            ans[cnt++] = i;
    }

}
int main(){
    prime();
    int n;
    while(scanf("%d",&n) && n != 0){
        auto it = lower_bound(ans, ans+cnt, n);
        if(n == *it)
            printf("0\n");
        else
            printf("%d\n", *it - *(it - 1));
    }
}