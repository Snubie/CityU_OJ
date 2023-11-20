#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#define RANGE 100005
using namespace std;

int type[RANGE];

void solve(int n){
    queue<int> shiptime;
    queue<vector<int> > shiptype;
    // vector<int> ppltype;
    int ans = 0;
    memset(type, 0, RANGE * sizeof(int));
    for(int i = 0 ; i < n ; i++){
        int time, ppl;
        scanf("%d %d",&time, &ppl);

        vector<int> shiplist;
        for(int j = 0 ; j < ppl ; j++){
            int temp;
            scanf("%d",&temp);

            type[temp]++;
            shiplist.push_back(temp);
            if(type[temp] == 1)
                ans++;
        }

        while(!shiptime.empty() && shiptime.front() <= time - 86400){
            vector<int> list = shiptype.front();
            int size = list.size();
            for(int j = 0 ; j < size ; j++){
                type[list[j]]--;
                if(!type[list[j]])
                    ans--;
            }
            shiptime.pop();
            shiptype.pop();
        }
        shiptime.push(time);
        shiptype.push(shiplist);
        printf("%d\n",ans);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}