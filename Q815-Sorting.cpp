#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n){
    vector<int> list;
    list.push_back(0);
    list.push_back(n+1);
    for(int i = 0 ; i < n ; i++){
        int number;
        scanf("%d",&number);

        int loc = lower_bound(list.begin(),list.end(),number) - list.begin() - 1;

        printf("%d %d\n", list[loc], list[loc+1]);
        list.insert(list.begin()+loc+1,number);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    solve(n);
    return 0;
}