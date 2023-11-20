#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;

ll b, p, m;

ll solve(ll b, ll p, ll m){
    if(p == 1){
        return b;
    }else{
        ll ret = solve(b, p/2, m);
        ret = (ret * ret) % m;

        if (p & 1){
            return (ret * b) % m;
        }
        return ret;
    }
}

int main(){
    while(scanf(" %lld %lld %lld",&b ,&p, &m) != EOF){
        ll ans = solve(b, p, m);
        printf("%lld\n", ans);
    }
    return 0;
}