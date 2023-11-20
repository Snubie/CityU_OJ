#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;

struct Point{
    int x, y;
    Point(int _x = 0, int _y = 0){
        x = _x; y = _y;
    }
};
struct Line{
    Point a, b;
    Line(Point _a = Point(), Point _b = Point()){
        a = _a; b = _b;
    }
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
    Line l;
    scanf("%d %d %d %d", &l.a.x, &l.a.y, &l.b.x, &l.b.y);
    Point tl, br;
    scanf("%d %d %d %d", &tl.x, &tl.y, &br.x, &br.y);
    Point tr(br.x, tl.y), bl(tl.x, br.y);

    Line l1(tl, tr), l2(tl, bl), l3(br, tr), l4(br, bl), l5(tl, br), l6(tr, bl);

    bool flag = false;
    flag = intersect(l, l1);
    flag = !flag ? intersect(l, l2): flag;
    flag = !flag ? intersect(l, l3): flag;
    flag = !flag ? intersect(l, l4): flag;
    flag = !flag ? intersect(l, l5): flag;
    flag = !flag ? intersect(l, l6): flag;

    if(flag)
        printf("T\n");
    else
        printf("F\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}