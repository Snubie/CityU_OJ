#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Point{
    ll x, y;
};

double getAngle(Point a, Point b){
    return (b.y-a.y)/(double)(b.x-a.x);
}

ll getDistance(Point a, Point b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

Point start;
bool pointSort(Point a, Point b){
    if(a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool polarSort(Point a, Point b){
    double angleA = getAngle(start, a);
    double angleB = getAngle(start, b);
    if(angleA != angleB)
        return angleA < angleB;
    return getDistance(start,a) < getDistance(start,b);
}

int orienitation(Point a, Point b, Point c){
    return (b.y - a.y) * (c.x - b.x) < (b.x - a.x) * (c.y - b.y);
}

ll area(vector<Point> list, int length) {
    ll res = 0;
    for(int i = 0 ; i < length - 1 ; i++){
        res += (list[i].x - list[i+1].x) * (list[i].y + list[i+1].y);
    }
    res += (list[length - 1].x - list[0].x) * (list[0].y + list[length - 1].y);
    return res < 0 ? -1 * res : res;
}

long double solve(int n){
    vector<Point> coor(n), ans(n);

    for(int i = 0 ; i < n ; i++)
        scanf("%d %d",&coor[i].x,&coor[i].y);

    ll ogarea = area(coor, n);

    sort(coor.begin(), coor.end(), pointSort);
    start = coor[0];
    sort(coor.begin() + 1, coor.end(), polarSort);

    for(int i = 0 ; i < 3 ; i++)
        ans[i] = coor[i];

    int ptr = 3;
    for(int i = 3 ; i < n ; i++){
        while(ptr > 1 && !orienitation(ans[ptr-2],ans[ptr-1],coor[i])){
            ptr--;
        }
        ans[ptr++] = coor[i];
    }

    ll hullarea = area(ans, ptr);
    
    return (long double)ogarea / hullarea;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n, i = 1;
    while(scanf("%d", &n) && n != 0){
        double answer = solve(n);
        printf("Tile #%d\n",i++);
        printf("Wasted Space = %.2lf %%\n\n" , (1 - answer) * 100 );
    }
    return 0;
}