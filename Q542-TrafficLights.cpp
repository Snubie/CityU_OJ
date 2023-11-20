#include <cstdio>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

void print(int time){
    int h = time / 3600;
    int m = (time / 60) % 60;
    int s = time % 60;
    printf("%02d:%02d:%02d\n",h,m,s);
}

void solve(vector<int> lights, int size){
    vector<int> time(size);
    int step = lights[0] * 2;
    int t = step;
    bool found = false;
    while(t <= 18000){ // 5 hrs
        for(int i = 0 ; i < size ; i++){
            time[i] = t % (lights[i] * 2);
        }
        for(int i = 0 ; i < lights[0] - 5 ; i++){
            int count = 0;
            for(int j = 0 ; j < size ; j++){
                if((time[j] + i) % (lights[j] * 2) < (lights[j] - 5))
                    count++;
            }
            if(count == size){
                found = true;
                t += i;
                break;
            }
        }

        if(found)
            break;
        else
            t += step;
    }
    if(found)
        print(t);
    else
        printf("Signals fail to synchronise in 5 hours\n");
}

int main(){
    vector<int> lights;
    int temp;
    while(scanf("%d",&temp) != EOF){
        if(temp == 0){
            int size = lights.size();
            if(size){
                sort(lights.begin(),lights.end());
                solve(lights, size);
                lights.clear();
            }
        }else
            lights.push_back(temp);
    }
    return 0;
}