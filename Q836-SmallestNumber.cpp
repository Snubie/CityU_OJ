#include <cstdio>
using namespace std;

int main(){
    int n, input, min = 0;
    bool list[1000005] = {};
    scanf("%d",&n);
    for(int i = 0; i < n ; i++){
        scanf("%d",&input);
        if(input <= 1000005){
            list[input] = true;
            while(list[min])
                min++;
        }
    }
    printf("%d\n",min);
    return 0;
}