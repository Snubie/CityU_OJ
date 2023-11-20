#include <cstdio>
typedef long long ll;
using namespace std;

ll getweight(){
    ll wl, dl, wr, dr;
    scanf("%lld %lld %lld %lld", &wl, &dl, &wr, &dr);
    if(wl == 0)
        wl = getweight();
    if(wr == 0)
        wr = getweight();
    // if above check fail
    if(wl == 0 || wr == 0)
        return 0;
    
    return wl * dl == wr * dr ? wl + wr : 0;
}

bool solve(){
    ll wl, dl, wr, dr;
    scanf("%lld %lld %lld %lld", &wl, &dl, &wr, &dr);
    if(wl == 0)
        wl = getweight();
    if(wr == 0)
        wr = getweight();
    if(wl == 0 || wr == 0)
        return false;
    return wl*dl == wr*dr;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        bool ans = solve();
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
        if(t)
            printf("\n");
    }
    return 0;
}