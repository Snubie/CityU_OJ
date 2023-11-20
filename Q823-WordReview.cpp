#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;

void solve(int n){
    map<string, int> wordcount; // word, count
    //vector<string> wordlist(n);
    string wordlist[n];

    for(int i = 0 ; i < n ; i++){
        char str[12];
        scanf("%s",str);
        string ss(str);
        wordcount.insert({ss, 0}); 
        wordlist[i] = ss;
    }

    int m; 
    int count = 0, min = -1;
    scanf("%d",&m);
    string wordloc[m];
    vector<int> wordindex;
    int acword = 0;

    for(int i = 0 ; i < m ; i++){
        char str[12];
        scanf("%s",str);
        string ss(str);
        if(wordcount.find(str) != wordcount.end()){
            if(!wordcount[str]){
                count++;
                wordcount[str]++;
                if(min == -1)
                    min = i;
            }
            wordindex.push_back(i);
            acword++;
        }
        wordloc[i] = str; 
    }

    int dist = 1e6;
    if(count>1){
        map<string, int> tcount; // word, count
        for(int i = 0 ; i < n ; i++){
            tcount.insert({wordlist[i],0});
        }

        int cc = 1, pstart = 0, pend = 0;
        tcount[wordloc[wordindex[0]]]++;

        while(pstart < acword && pend < acword){
            if(cc != count){
                pend++;
                if(pend >= acword)
                    break;

                tcount[wordloc[wordindex[pend]]]++;
                if(tcount[wordloc[wordindex[pend]]] == 1)
                    cc++;

            }else{
                int gap = wordindex[pend] - wordindex[pstart] + 1;
                dist = gap < dist ? gap : dist;
                
                tcount[wordloc[wordindex[pstart]]]--;
                if(tcount[wordloc[wordindex[pstart]]] == 0)
                    cc--;

                pstart++;
            }
        }
    }else{
        dist = count;
    }

    printf("%d\n%d\n",count,dist);
}

int main(){
    int n ;
    while(scanf("%d",&n) != EOF){
        solve(n);
    }
    return 0;
}