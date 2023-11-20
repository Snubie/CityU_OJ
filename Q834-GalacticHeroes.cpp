#include <cstdio>
#include <vector>
using namespace std;

class Ret{
public:
    int head;
    int dist;
    Ret(int h, int d){
        head = h;
        dist = d;
    }
};

class DSet{
public:
    vector<int> head;
    vector<int> tail;
    vector<int> dist;

    DSet(int sizes){
        head = vector<int>(sizes+1);
        tail = vector<int>(sizes+1);
        dist = vector<int>(sizes+1,0);
        for(int i = 1 ; i <= sizes ; i++){
            head[i] = i;
            tail[i] = i;
        }
    }   

    Ret find(int i) { 
        if(i == head[i]){
            return Ret(i,0);
        }

        Ret ret = find(head[i]);
        head[i] = ret.head;
        dist[i] = ret.dist + dist[i]; 
        return Ret(head[i],dist[i]); 
    }

    void conn(int i, int j) {
        int gi = find(i).head;
        int gj = find(j).head;

        if (gi != gj) {
            // update head
            head[gi] = tail[gj];
            tail[gj] = tail[gi];
            dist[gi] = 1;
        }
    }
    
    int checkdis(int i, int j){
        Ret gi = find(i);
        Ret gj = find(j);
        if (gi.head != gj.head) {
            return -1;
        }else{
            int res = gi.dist - gj.dist;
            return res > 0 ? res - 1 : -1 * res - 1;
        }
    }
};
     
int main(){
    DSet set(30000);
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        char f;
        int t1, t2;
        scanf(" %c %d %d",&f,&t1,&t2);
        if(f == 'M')
            set.conn(t1,t2);
        else{
            int res = set.checkdis(t1,t2);
            printf("%d\n", res);
        }
    }
}