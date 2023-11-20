#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Record{
    int time;
    int year;
    string phone;
    bool important;
};

void solve(int n){
    vector<Record> rlist(n);
    for(int i = 0 ; i < n ; i++){
        int m, d, h, mm;
        char s[17], im;
        scanf("%d:%d:%d:%d %s %c",&m, &d, &h, &mm, s, &im);
        rlist[i].time = m * 31 * 24 * 60 + d * 24  * 60 + h * 60 + mm;
        rlist[i].phone = string(s);
        rlist[i].important = im == '+';
    }

    rlist[0].year = 0;
    for(int i = 1 ; i < n ; i++){
        rlist[i].year = rlist[i-1].year + (rlist[i-1].time >= rlist[i].time);
    }
    

    vector<int> dp(n, 0);
    int end = -1, start = -1, curr = rlist[n-1].year;
    for (int i = n - 1; i >= 0; i--) {
        if (end == -1 && rlist[i].year == curr)
            dp[i] = 1;
        else
            dp[i] = n - i;

        if (end == -1 && (rlist[i].important || rlist[i].year != curr))
            end = i;
        if (rlist[i].important)
            start = i;
    }

    for (int i = end; i >= start; i--) {
        for (int j = i + 1; j < n; j++) {
            if (rlist[i].year == rlist[j].year){
                dp[i] = min(dp[i], dp[j] + 1);
                if (rlist[j].important)	
                    break;
            }else if (rlist[i].time >= rlist[j].time && rlist[j].year - rlist[i].year == 1){
                dp[i] = min(dp[i], dp[j] + 1);
                if (rlist[j].important)	
                    break;
            }else
                break;
        }
    }

    printf("%d\n", dp[start]);
}

int main(){
    int n;
    while(scanf("%d",&n) && n != 0)
        solve(n);
    return 0;
}