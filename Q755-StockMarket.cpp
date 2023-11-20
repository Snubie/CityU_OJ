#include <cstdio>
#include <vector>
using namespace std;
struct Bar{
    int value;
    int lcount;
    int rcount;
};

void solve(){
    int N;
    long long max = 0;
    scanf("%d", &N);
    vector<Bar> arr(N);

    scanf("%d", &arr[0].value);
    for(int i = 1 ; i < N ; i++){
        scanf("%d",&arr[i].value);

        // lcount
        if(arr[i].value > arr[i-1].value)
            arr[i].lcount = 0;
        else if(arr[i].value == arr[i-1].value)
            arr[i].lcount = arr[i-1].lcount + 1;
        else{
            for(int j = i - 1 ; j >= 0 ; j--){
                if(arr[i].value <= arr[j].value){
                    arr[i].lcount += arr[j].lcount + 1;
                    j -= arr[j].lcount;
                }
                else
                    break;
            }
        }
    }

    arr[N-1].rcount = 0;
    for(int i = N - 2; i >= 0 ; i--){
        //rcount 
        if(arr[i].value > arr[i+1].value)
            arr[i].rcount = 0;
        else if(arr[i].value == arr[i+1].value)
            arr[i].rcount = arr[i+1].rcount + 1;
        else{
            for(int j = i + 1 ; j < N ; j++){
                if(arr[i].value <= arr[j].value){
                    arr[i].rcount += arr[j].rcount + 1;
                    j += arr[j].rcount;
                }
                else
                    break;
            }
        }
        //find max
        long long value = (long long)arr[i].value * (arr[i].lcount + arr[i].rcount + 1);
        max = value > max ? value : max;
    }
    printf("%lld\n", max);

}

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0 ; i < T ; i++)
        solve();
    return 0;
}