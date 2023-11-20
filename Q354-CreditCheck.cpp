#include <cstdio>
using namespace std;

int sep(int num){
    return num%10+num/10;
}

int calc(int num){
    int val = sep((num / 1000) * 2);
    val += num / 100 % 10;
    val += sep((num / 10 % 10) * 2);
    val += num % 10;
    return val;
}

void solve(){
    int total = 0;
    for(int i = 0 ; i < 4 ; i++){
        int temp;
        scanf("%d",&temp);
        total += calc(temp);
    }

    if(total % 10 == 0)
        printf("Valid\n");
    else
        printf("Invalid\n");
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}