#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n){
    vector<int> list;

    for(int i = 0 ; i < n ; i++){
        int number;
        scanf("%d",&number);

        auto it = lower_bound(list.begin(),list.end(),number);
        list.insert(it,number);

        if(i%2==0)
            printf("%d\n", list[i/2]); 
    }
}

int main(){
    int n;
    scanf("%d",&n);
    solve(n);
    return 0;
}