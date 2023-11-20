#include <cstdio>
#include <cmath>
#include <set>
#define LIMIT 105
typedef unsigned long long ull;
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


int getl(int num){
    int count = 0;
    for(ull max = 0 - 1; max > 0 ; max /= num)
        count++;
    return count;
}

int main(){
    primeSiege();

    set<ull> list;
    for(int i = 2 ; i < 65536 ; i++){
        ull base = i;
        ull pow = i;
        int size = getl(base);

        for(int j = 2 ; j < size ; j++){
            if(pow * base < pow) // overflow
                break;

            pow *= base;
            if(checked[j])
                list.insert(pow);
        }
    }
    printf("1\n");
    for(auto it = list.begin() ; it != list.end() ; it++){
        printf("%llu\n",*it);
    }
    return 0;
}