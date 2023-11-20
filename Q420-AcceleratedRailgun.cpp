#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    double d;
    while(scanf("%lf",&d) && d != 0){

        long double px, py, vx, vy;
        scanf("%llf %llf %llf %llf",&px, &py, &vx, &vy);

        // check 1 : is (0,0) on y - py = (vy / vx) (x - px)

        // 0 - py = (vy / vx) (0 - px)
        // py = px (vy / vx)
        // py * vx = px * vy
        // py * vx - px * vy = 0

        bool f1 = fabs( py * vx - px * vy ) <= 1e-7; // floating point

        // check 2 : can pass through (0,0) before d

        bool f2 = false;
        double distance = sqrt(px * px + py * py); // (0,0) to (px, py)
        double direction = px * vx + py * vy;

        if(direction < 0){
            f2 = distance <= d;
        }else{
            f2 = (2 - distance) <= d; // reflect, 1 + (1 - distance)
        }

        if(f1 && f2)
            printf("possible\n");
        else
            printf("impossible\n");
    }
    return 0;
}