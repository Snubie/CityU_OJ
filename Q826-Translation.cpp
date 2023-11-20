#include <cstdio>
#include <deque>
using namespace std;

void solve(int m, int n){
    deque<int> dic(m,-1);
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        int check;
        scanf("%d",&check);

        bool flag = true;
        for(int j = 0 ; j < m && flag ; j++){
            if(dic[j] == check)
                flag = false;
        }

        if(flag){
            dic.pop_front();
            dic.push_back(check);
            count++;
        }
    }
    printf("%d\n",count);
}

int main(){
    int m, n;
    scanf("%d %d",&m, &n);
    solve(m, n);
    return 0;
}