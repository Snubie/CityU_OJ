#include <cstdio>
#include <vector>
#define MAX 1005
using namespace std;

class DSet{
public:
    vector<int> s;
    int size;

    DSet(int sizes){
        size = sizes;

        s = vector<int>(size+1);
        for(int i = 1 ; i <= size ; i++){
            s[i] = i;
        }
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
            if(gj < gi){
                int t = gi; gi = gj; gj = t; //swap
            }
            s[gj] = gi;    
        }            
    }

    int count() {
        int ans = 0;
        for (int i = 1; i <= size; i++) {
            if (i == s[i]) 
                ans++;
        }
        return ans;
    } 
};
     
int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    DSet set(n);
    vector<int> enemy[n+1];
    
    for(int i = 0 ; i < m ; i++){
        char f;
        int t1, t2;
        scanf(" %c %d %d",&f,&t1,&t2);
        if(f == 'F'){
            set.conn(t1,t2);
        }else{
            enemy[t1].push_back(t2);
            enemy[t2].push_back(t1);
        }
    }

    for(int i = 1 ; i <= n ; i++){
        int size = enemy[i].size();
        for(int j = 0 ; j < size - 1 ; j++){
            set.conn(enemy[i][j],enemy[i][j+1]);
        }
    }

    printf("%d\n",set.count());
    return 0;
}