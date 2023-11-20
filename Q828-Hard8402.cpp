/* Last Version
 */
#include <cstdio>

int i, n, m, seed, leftover = 0;
unsigned char *counting;
void generateArray(int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 0; i < n; i++) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;
        counting[x % m + 1]++;
    }
}

int main(){
    scanf("%d %d %d",&n, &m, &seed);

    counting = new unsigned char[m+1]{};
    generateArray(n,m,seed);
    m >>= 1;
    for(i = 0 ; i <= m ; i++){
        if(leftover && counting[i]){
            if(leftover > i){
                counting[leftover]++;
                counting[i]--;
            }
            leftover = 0;
            n--;
        }
        if(counting[i] >= 2){
            counting[i << 1] += counting[i] >> 1;
            n -= counting[i] >> 1;
        }
        if(counting[i] & 1)
            leftover = i << 1;
    }
    while(leftover){
        if(counting[i]){
            counting[leftover]++;
            counting[i]--;
            n--;
            break;
        }
        i++;
    }

    int l = 2*n-1, pow = 0, sub = 0;
    while(l - sub - (2 << pow) >= 0){
        sub += 2 << pow;
        pow++;
    }

    int loc = l-sub, loccount = 0;
    while(true){
        loccount += counting[i];
        if(loccount >= loc){
            break;
        }
        i++;
    }
    printf("%lld\n",((long long)i)<<pow);
    return 0;
}