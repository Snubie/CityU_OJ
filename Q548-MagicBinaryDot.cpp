#include <cstdio>
typedef long long ll;
using namespace std;

void solve(ll a, ll b){
    if(b - a <= 1){
        printf("%lld\n",a|b);
        return;
    }

    ll max = a;
    ll pow2 = 1;

    while((pow2<<1) - 1 < b){
        pow2 <<= 1;
        ll tmp = a | (pow2-1);
        if(tmp >= a && tmp <= b-1)
            max = tmp|(tmp+1);
    }
        
    printf("%lld\n",max);
}

int main(){
    ll a, b;
    while(scanf("%lld %lld", &a, &b) != EOF){
        solve(a, b);
    }
    return 0;
}