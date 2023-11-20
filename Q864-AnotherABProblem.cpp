#include <cstdio>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(int n){
    vector<int> arr(n+5);
    unordered_map<long long, long long> map; // value, count

    for(int i = 1 ; i <= n; i++){
        scanf("%d", &arr[i]);
        map[arr[i] - i]++;
    }

    long long ans = 0;
    for(auto it = map.begin(); it != map.end(); it++){
        ans += (it->second * (it->second - 1) / 2);
    }
    printf("%lld\n", ans);
}

int main(){
    int t, n;
    scanf("%d",&t);
    for(int i = 0 ; i < t ; i++){
        scanf("%d",&n);
        solve(n);
    }
    return 0;
}