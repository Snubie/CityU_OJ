#include <cstdio>
#include <unordered_map>
using namespace std;

void solve(int n, int C){
    unordered_map<int, int> map; // value, count
    long long count = 0;

    for(int i = 0 ; i < n ; i++){
        int value;
        scanf("%d", &value);
        map[value]++;
    }

    for(auto it : map){
        int findnum = it.first - C;
        count += ((long long) it.second * map[findnum]);
    }

    printf("%lld\n", count);
}

int main(){
    int n, C;
    while(scanf("%d %d",&n, &C) != EOF)
        solve(n,C);
    return 0;
}