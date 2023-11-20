#include <cstdio>
#define MAX 100005
#define MOD 998244353
using namespace std;

int main(){
    int arr[MAX] = {};

    for(int i = 2 ; i < MAX ; i++){
        for(int j = i * 2 ; j < MAX ; j+=i){
            arr[j]++;   
        }
    }

    arr[1] = 1;
    int sum = arr[1];
    for(int i = 2 ; i < MAX ; i++){
        arr[i] = (arr[i] + sum + 2) % MOD;
        sum = (sum + arr[i]) % MOD;
    }

    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", arr[n]);
    }
    
    return 0;
}