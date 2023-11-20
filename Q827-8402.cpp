#include <cstdio>
#include <algorithm>
#define MAX 100005
typedef long long ll;
using namespace std;

class MinHeap{
    public:
    int size;
    ll arr[MAX];
    MinHeap(){
        size = 0;
    }
    void swap(int i1, int i2){
        ll t = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = t;
    }

    void push(ll n){
        arr[size] = n;
        int tsize = size;
        while(tsize > 0 && arr[tsize] < arr[(tsize-1)/2]){
            swap(tsize, (tsize-1)/2);
            tsize = (tsize-1)/2;
        }
        size++;
    }
    ll pop(){
        if(size == 0) return 0;
        
        ll rr = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = 0;
        size--;

        int tsize = 0;
        while(tsize*2+1 < size){
            int index = tsize*2+1;
            if(index+1 < size && arr[index+1] < arr[index])
                index++;
            if(arr[index] <= arr[tsize])
                swap(tsize,index);
            else
                break;
            tsize = index;
        }
        return rr;
    }
};

int n, m, seed;

// edited a bit for suiting my heap
void generateArray(ll* arr, int n, int m, int seed) {
    unsigned x = seed;
    for (int i = 0; i < n; i++) {
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    arr[i] = x % m + 1;
    }
}

/* from cwksc
for(int i = 0 ; i < m ; i++){
    if(counting[i] >= 2){
        counting[i << 1] += counting[i] >> 1;
        n -= counting[i] >> 1;
        counting[i] %= 2;
    }
} 
*/

ll combine(ll a, ll b){ 
    return a > b ? max(a,2*b) : max(b,2*a); 
}

void solve(int n, int m, int seed){
    MinHeap heap;

    generateArray(heap.arr,n,m,seed);
    heap.size = n;
    sort(heap.arr,heap.arr+n);

    while(heap.size != 1){
        ll n1 = heap.pop();
        ll n2 = heap.pop();
        heap.push(combine(n1,n2));
    }
    ll ans = heap.pop();
    printf("%lld\n", ans);
}

int main(){
    int n, m, seed;
    while(scanf("%d %d %d",&n, &m, &seed) != EOF){
        solve(n,m,seed);
    }
    return 0;
}