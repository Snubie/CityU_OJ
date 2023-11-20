#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

// basically rewrite my Q272 
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

void solve(){
    int n;
    scanf("%d",&n);
    if(n == -1)
        scanf("%d",&n);

    vector<Point> coor(n-1);
    vector<Point> ans(n-1);

    for(int i = 0 ; i < n-1 ; i++){
        scanf("%d %d",&coor[i].x,&coor[i].y);
    }
    scanf("%d %d",&coor[0].x,&coor[0].y);

    // sorting 
    sort(coor.begin(), coor.end(), pointSort);
    start = coor[0];
    sort(coor.begin() + 1, coor.end(), polarSort);

    //push first three into answer
    for(int i = 0 ; i < 3 ; i++)
        ans[i] = coor[i];

    //algo
    int ptr = 3;
    for(int i = 3 ; i < n-1 ; i++){
        while(ptr > 1 && !orienitation(ans[ptr-2],ans[ptr-1],coor[i])){
            ptr--;
        }
        ans[ptr++] = coor[i];
    }

    printf("%d\n", ptr+1);
    int min = 0;
    for(int i = 1 ; i < ptr ; i++){
        if(ans[i].y < ans[min].y || (ans[i].y == ans[min].y && ans[i].x < ans[min].x)){
            min = i;
        }
    }
    
    printf("%d %d\n", ans[min].x, ans[min].y);
    for(int i = min + 1 ; i != min ; i = (i + 1) % ptr){
        printf("%d %d\n", ans[i].x, ans[i].y);
    }
    printf("%d %d\n", ans[min].x, ans[min].y);
}

int main(){
    int t, tmp;
    scanf("%d", &t);
    printf("%d\n", t);
    while(t--){
        solve();
        if(t)
            printf("-1\n");
    }
    return 0;
}