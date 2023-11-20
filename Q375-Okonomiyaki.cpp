#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

class State{
    public:
    int a, b, c, d, step;

    State(){
        a = b = c = d = 0;
        step = 0;
    }

    State(int a, int b, int c, int d, int step){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
        this->step = step;
    }

    bool match(int t){
        return a == t || b == t || c == t || d == t;
    }
};

queue<State*> q;
int visited[30][30][30][30];
int _true = 0;

void handle(int a, int b, int c, int d, int t){
    if(visited[a][b][c][d] != _true){
        visited[a][b][c][d] = _true;
        q.push(new State(a, b, c, d, t));
    }
}

void solve(int a, int b, int c, int d, int t){
    q = queue<State*>();
    _true++;
    handle(0,0,0,0,0);
    while(!q.empty()){
        State* s = q.front();
        q.pop();

        //refill
        if(s->match(t)){
            printf("%d\n",s->step);
        	return;
        }

        int nstep = s->step+1;
        handle(0, s->b, s->c, s->d, nstep);
        handle(s->a, 0, s->c, s->d, nstep);
        handle(s->a, s->b, 0, s->d, nstep);
        handle(s->a, s->b, s->c, 0, nstep);
        
        handle(a, s->b, s->c, s->d, nstep);
        handle(s->a, b, s->c, s->d, nstep);
        handle(s->a, s->b, c, s->d, nstep);
        handle(s->a, s->b, s->c, d, nstep);

        int na, nb, nc, nd;

        // A-> BCD
        nb = min(s->a+s->b, b);
        nc = min(s->a+s->c, c);
        nd = min(s->a+s->d, d);
        handle(s->a+s->b-nb, nb, s->c, s->d, nstep);
        handle(s->a+s->c-nc, s->b, nc, s->d, nstep);
        handle(s->a+s->d-nd, s->b, s->c, nd, nstep);

        // B-> ACD
        na = min(s->b+s->a, a);
        nc = min(s->b+s->c, c);
        nd = min(s->b+s->d, d);
        handle(na, s->b+s->a-na, s->c, s->d, nstep);
        handle(s->a, s->b+s->c-nc, nc, s->d, nstep);
        handle(s->a, s->b+s->d-nd, s->c, nd, nstep);

        // C ->ABD
        na = min(s->c+s->a, a);
        nb = min(s->c+s->b, b);
        nd = min(s->c+s->d, d);
        handle(na, s->b, s->c+s->a-na, s->d, nstep);
        handle(s->a, nb, s->c+s->b-nb, s->d, nstep);
        handle(s->a, s->b, s->c+s->d-nd, nd, nstep);
        
        //D->ABC
        na = min(s->d+s->a, a);
        nb = min(s->d+s->b, b);
        nc = min(s->d+s->c, c);
        handle(na, s->b, s->c, s->d+s->a-na, nstep);
        handle(s->a, nb, s->c, s->d+s->b-nb, nstep);
        handle(s->a, s->b, nc, s->d+s->c-nc, nstep);
    }

    printf("-1\n");
}

int main(){
    int a, b, c, d, t;
    while(scanf("%d %d %d %d %d",&a, &b, &c, &d, &t) != EOF){
        solve(a, b, c, d, t);
    }
    return 0;
}