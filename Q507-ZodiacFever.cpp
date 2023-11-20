#include <cstdio>
#include <vector>
#include <utility>
#include <set>
typedef long long ll;
using namespace std;

class State{
    public:
    int room;
    int dist;
    int lock_num;

    State(){
        room = dist = lock_num = 0;
    }

    State(int a, int b, int c){
        room = a;
        dist = b;
        lock_num = c;
    }

    bool operator<(const State &s) const{
        return dist < s.dist;
    }
};

vector<pair<int, int> > map[1050]; // loc, dist
vector<pair<char, int> > trap(1050, make_pair(0,0));
multiset<State> q;
int checked[1050][20] = {0};
int _true = 1;

int update(int locknum, char op, int change){
    int result = locknum;
    if(op == '+')
        result += change;
    if(op == '-')
        result += 12 - (change % 12);
    if(op == '*')
        result *= change;
    if(op == '=')
        result = change;
    return result % 12 == 0 ? 12 : result % 12;
}

int path_find(int treasure, int openpos){
    while(!q.empty()){
        State s = *q.begin(); q.erase(q.begin());

        if(s.room == treasure && s.lock_num == openpos)
            return s.dist;

        if(checked[s.room][s.lock_num] == _true)
            continue;
        checked[s.room][s.lock_num] = _true;

        for(int i = 0 ; i < map[s.room].size() ; i++){
            pair<int, int> a = map[s.room][i];
            int locknum = update(s.lock_num, trap[a.first].first, trap[a.first].second);
        
            q.insert(State(a.first, s.dist + a.second, locknum));
        }
    }
    return -1;
}

void solve(int room, int path, int traps, int entrance, int initpos, int treasure, int openpos){
    
    for(int i = 0 ; i < path ; i++){
        int r1, r2, dist;
        scanf("%d %d %d",&r1, &r2, &dist);
        map[r1].push_back({r2, dist});
        map[r2].push_back({r1, dist});
    }

    for(int i = 0 ; i < traps ; i++){
        int r, val;
        char op;
        scanf(" %d %c %d",&r, &op, &val);
        trap[r].first = op;
        trap[r].second = val;
    }
    q.insert(State(entrance, 0, initpos));
    int res = path_find(treasure, openpos);
    if(res >= 0)
        printf("%d\n",res);
    else
        printf("Pray!\n");

}

int main(){
    int room, path, traps, entrance, initpos, treasure, openpos;
    while(scanf("%d %d %d %d %d %d %d", &room, &path, &traps, &entrance, &initpos, &treasure, &openpos) != EOF){
        
        solve(room, path, traps, entrance, initpos, treasure, openpos);

        _true++;
        q.clear();
        trap = vector<pair<char, int> >(1050, make_pair(0,0));
        for(int i = 0 ; i < 1050 ; i++){
            map[i].clear();
        }
    }
    return 0;
}