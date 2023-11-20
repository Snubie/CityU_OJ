#include <cstdio>
typedef long long ll;

bool isInsideWall(ll wx, ll wy, ll wr, ll x, ll y){
    ll dx = wx - x;
    ll dy = wy - y;
    return dx * dx + dy * dy < wr * wr; 
}

ll wx[3000], wy[3000], wr[3000];

int main(){
    int n , q;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        scanf("%lld %lld %lld",&wx[i], &wy[i], &wr[i]);
    }
    scanf("%d",&q);
    for(int i = 0 ; i < q ; i++){
        ll a , b , c , d, count = 0;
        scanf("%lld %lld %lld %lld",&a, &b, &c, &d);
        for(int j = 0 ; j < n ; j++){
            bool f1 = isInsideWall(wx[j],wy[j],wr[j],a,b);
            bool f2 = isInsideWall(wx[j],wy[j],wr[j],c,d);
            if(f1 ^ f2)
                count++;
        }
        printf("%lld\n",count);
    }
    return 0;
}
