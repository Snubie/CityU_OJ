#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
typedef long long ll;
using namespace std;

ll solve(){
    ll n, m, c;
    scanf("%lld %lld %lld",&n, &m, &c);
    ll ans = n * (m - 1);

    vector<int> reserved(c * 2);
    for(int i = 0 ; i < c * 2 ; i++){
        scanf("%d",&reserved[i]);
    }

    set<pair<int, int> > list;
    for(int i = 0 ; i < c ; i++){
        int row = reserved[i];
        int seat = reserved[c + i];
        if(list.find(make_pair(row,seat - 1)) == list.end() && seat - 1 != 0)
            ans--;
        if(list.find(make_pair(row,seat + 1)) == list.end() && seat + 1 != m + 1)
            ans--;
        list.insert(make_pair(row, seat));
    }

    return ans;    
}

int main(){
    int t, i = 1;
    scanf("%d",&t);
    while(t--){
        ll ans = solve();
        printf("Case #%d: %lld\n", i, ans);
        i++;
    }
    return 0;
}