#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define LIMIT 1000001
typedef unsigned long long ull;
using namespace std;

//vector<int> prime;
int prime[80000] = {}, cnt = 0;
bool checked[LIMIT] = {};
void primeSieve(){
    int i;
    checked[0] = checked[1] = true;
    for(i = 2 ; i * i < LIMIT ; i++){
        if(!checked[i]){
            prime[cnt++] = i;
            for(int j = i * i ; j < LIMIT ; j += i){
                checked[j] = true;
            }
        }
    }

    for( ; i < LIMIT ; i++){
        if(!checked[i]){
            //prime.push_back(i);
            prime[cnt++] = i;
        }
    }
}

bool isPrime(int value){
    if(value <= 1000000)
        return !checked[value];

    int sqt = sqrt(value);
    for(int i = 0 ; prime[i] <= sqt ; i++){
        if(value % prime[i] == 0)
            return false;
    }
    return true;
}


int main(){
    primeSieve();
    int n;
    while(scanf("%d",&n) != EOF){
        if(n == 1){
            printf("%d is not the sum of two primes!\n", n);
            continue;
        }   
        if(n & 1){
            if(isPrime(n - 2))
                printf("%d is the sum of 2 and %d.\n",n ,n - 2);
            else
                printf("%d is not the sum of two primes!\n", n);
        }else{
            bool flag = true;
            for(int i = (n - 1) / 2 ; i >= 0 ; i--){
                if(isPrime(i) && isPrime(n - i)){
                    printf("%d is the sum of %d and %d.\n", n, i, n - i);
                    flag = false;
                    break;
                }
            }
            if(flag){
                printf("%d is not the sum of two primes!\n", n);
            }
        }
    }
    return 0;
}