#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;

struct Point{
    int x, y;
};
struct Line{
    Point a, b;
};

int orienitation(Point a, Point b, Point c){
    int val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if(val == 0)
        return 0;
    return val > 0 ? 1 : -1;
}

bool onSegment(Point a, Point b, Point c){
    return (b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y));
}

bool intersect(Line l1, Line l2){
    int l1a = orienitation(l1.a, l1.b, l2.a);
    int l1b = orienitation(l1.a, l1.b, l2.b);
    int l2a = orienitation(l2.a, l2.b, l1.a);
    int l2b = orienitation(l2.a, l2.b, l1.b);

    if(l1a != l1b && l2a != l2b)
        return true;
    if(l1a == 0 && onSegment(l1.a, l2.a, l1.b))
        return true;
    if(l1b == 0 && onSegment(l1.a, l2.b, l1.b))
        return true;
    if(l2a == 0 && onSegment(l2.a, l1.a, l2.b))
        return true;
    if(l2b == 0 && onSegment(l2.a, l1.b, l2.b))
        return true;
    return false;
}

void solve(){
    int m;
    scanf("%d",&m);
    vector<Line> list(m);
    for(int i = 0 ; i < m ; i++){
        scanf("%d %d %d %d", &list[i].a.x, &list[i].a.y, &list[i].b.x, &list[i].b.y);
    }

    vector<bool> noInter(m, true);
    for(int i = 0 ; i < m ; i++){
        for(int j = i + 1 ; j < m ; j++){
            if(intersect(list[i],list[j])){
                noInter[i] = false;
                noInter[j] = false;
            }
        }
    }

    int count = 0;
    for(int i = 0 ; i < m ; i++)
        count += noInter[i]; 

    printf("%d\n",count);
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}