#include <cstdio>
#include <cmath>
#include <deque>
#include <utility>
#include <algorithm>
using namespace std;

double getAngle(pair<int, int> origin, pair<int, int> extend){
    return atan((extend.second-origin.second)/(double)(extend.first-origin.first));
}

double getDistance(pair<int, int> A, pair<int, int> B){
    long long len = (long long)(A.first - B.first) * (A.first - B.first);
    len += (long long)(A.second - B.second) * (A.second - B.second);
    return sqrt(len);
}

pair<int, int> start;
bool polarSort(pair<int, int> A, pair<int, int> B){
    double angleA = getAngle(start, A);
    double angleB = getAngle(start, B);
    if(angleA != angleB)
        return angleA < angleB;
    //compare distance
    return getDistance(start,A) < getDistance(start,B);
}

bool isCounterClockwise(pair<int, int> start, pair<int, int> mid, pair<int, int> end){
    long long valueA = (long long)(mid.second - start.second) * (end.first - mid.first);
    long long valueB = (long long)(mid.first - start.first) * (end.second - mid.second);
    return valueA <= valueB;
}

void solve(){
    int N;
    scanf("%d",&N);

    deque<pair<int, int> > coor(N);
    deque<pair<int, int> > ans;

    for(int i = 0 ; i < N ; i++){
        scanf("%d %d",&coor[i].first,&coor[i].second);
    }
    sort(coor.begin(), coor.end());

    // sorting (anti clockwise)
    start = coor.front();
    coor.pop_front();

    sort(coor.begin(), coor.end(), polarSort);
    coor.push_front(start);

    // find duplicate(?)
    for(int i = 1 ; i < N - 1 ; i++){
        if(getAngle(coor[0],coor[i]) == getAngle(coor[0],coor[i+1])){
            coor.erase(coor.begin()+i);
            i--; N--;
        }
    }

    //push first three into answer
    ans.push_back(coor.front());
    coor.pop_front();
    ans.push_back(coor.front());
    coor.pop_front();
    ans.push_back(coor.front());
    coor.pop_front();

    //algo
    while(!coor.empty()){
        while(!isCounterClockwise(ans[ans.size()-2],ans.back(),coor.front())){
            ans.pop_back();
        }
        ans.push_back(coor.front());
        coor.pop_front();
    }

    printf("%d\n",ans.size());
    while(!ans.empty()){
        printf("%d %d\n",ans.front().first,ans.front().second);
        ans.pop_front();
    }
}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i++)
        solve();
    return 0;
}