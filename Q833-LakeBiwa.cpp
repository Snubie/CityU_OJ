#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 250005
using namespace std;

class DSet{
public:
    vector<int> s;
    int gp;

    DSet(int size){
        s = vector<int>(size+1, -1);
        gp = 0;
    }   

    int Find(int i) { 
        if(i == s[i])
            return i;
        s[i] = Find(s[i]);
        return s[i]; 
    }

    void conn(int i, int j) {
        int gi = Find(i);
        int gj = Find(j);
        if (gi != gj) {
            s[gj] = gi;
            gp--;
        }            
    }

    int count() {
        return gp;
    } 
};

int n, m, T;
DSet set(MAX);
vector<int> land(MAX,0);

int solve(vector<int> arr){
    int size = arr.size();
    for(int i = 0 ; i < size ; i++){
        int loc = arr[i];
        set.s[loc] = loc;
        set.gp++;

        if((loc-1)%m > 0 && set.s[loc-1] != -1){
            set.conn(loc,loc-1); 
        }
        if((loc-1)%m < m-1 && set.s[loc+1] != -1){
            set.conn(loc,loc+1);
        }
        if(loc > m && set.s[loc-m] != -1){
            set.conn(loc,loc-m);
        }
        if(loc <= m * (n-1) && set.s[loc+m] != -1){
            set.conn(loc,loc+m);
        }
    }
    return set.count();
}

int main(){
    scanf("%d %d",&n, &m);
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 1 ; j <= m ; j++){
            scanf("%d",&land[i*m+j]);
        }
    }

    scanf("%d",&T);
    vector<int> time(T,0);
    vector<int> ans(T,0);
    vector<vector<int> > store(T);

    for(int i = 0 ; i < T ; i++){
        scanf("%d",&time[i]);
    }
    
    // binary search + insert O(n*m*log(T))
    for(int i = 1 ; i <= n * m ; i++){
        if(land[i] > time[0]){
            int index = upper_bound(time.begin(),time.end(),land[i]-1) - time.begin();
            store[index-1].push_back(i);
        }
    }

    // solving by layer, overall O(n*m)?
    for(int i = T - 1 ; i >= 0 ; i--){
        ans[i] = solve(store[i]);
    }

    for(int i = 0 ; i < T ; i++){
        if(i != 0)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}