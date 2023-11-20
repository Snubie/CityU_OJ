#include <cstdio>
#include <vector>
#include <algorithm>
#define LIMIT 1000005
using namespace std;

int prime[LIMIT] = {}, cnt = 0;
bool checked[LIMIT] = {};
void primeSiege(){
    int i;
    for(i = 2 ; i * i < LIMIT ; i++){
        if(!checked[i]){
            prime[cnt++] = i;
            for(int j = i * i ; j < LIMIT ; j += i){
                checked[j] = true;
            }
        }
    }

    for( ; i < LIMIT ; i++){
        if(!checked[i])
            prime[cnt++] = i;
    }
}

void solve(int a, int b){
    int asum = 0, bsum = 0, abig = 1, bbig = 1;
    for(int i = 0 ; prime[i] <= a ; i++){
        if(a % prime[i] == 0){
            asum += prime[i];
            abig = prime[i];
       }
    }
    for(int i = 0 ; prime[i] <= b ; i++){
        if(b % prime[i] == 0){
            bsum += prime[i];
            bbig = prime[i];
        }
    }

    asum = asum * -1 + abig * 2;
    bsum = bsum * -1 + bbig * 2;

    if(asum > bsum)
        printf("a\n");
    else
        printf("b\n");

}

int main(){
    primeSiege();
    int a, b;
    while(scanf("%d %d",&a, &b) && a != 0 && b != 0){
        solve(a, b);
    }
    return 0;
}