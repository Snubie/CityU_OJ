#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
typedef long long ll;
using namespace std;

// give dp tag when it is related to string
// and I wanna die

char str[100005];
int table[100005];

void solve(){
    string s(str);
    string srev = s; 
    reverse(srev.begin(), srev.end());
    int l = s.length();

    //prefix function
    table[0] = 0;
    for(int i = 1 ; i < l ; i++){
        int j = table[i - 1];
        while (j > 0 && srev[i] != srev[j])
            j = table[j - 1];
        if (srev[i] == srev[j])
            j++;
        table[i] = j;
    }

    // KMP
    int i = 0, j = 0;
    while(i < l){
        if(s[i] == srev[j]){
            i++;
            j++;
        }else{
            if(j > 0)
                j = table[j - 1];
            else
                i++;
        }
    }

    str[l - j] = '\0';
    printf("%s",str);
    printf("%s\n",srev.c_str());
}

int main(){
    while(scanf("%s",str) != EOF){
        solve();
    }
    return 0;
}