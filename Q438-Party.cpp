#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int input;
        scanf("%d",&input);
        if(input > 1)
            printf("%d\n",input-2);
        else
            printf("%d\n",0);
    }
    return 0;
}