#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
typedef long long ll;
using namespace std;

bool compare(const pair<int, string> &a, const pair<int, string> &b){
    return a.second < b.second;
}

void solve(){
    string str;
    cin >> str;

    int len = str.size();
    vector<pair<int, string> > suffixArray(len);
    
    //lazy n^2 log n suffix array implement
    for(int i = 0 ; i < len ; i++){
        string pattern = str.substr(i, len-i);
        suffixArray[i] = make_pair(i, pattern);
    }
    sort(suffixArray.begin(), suffixArray.end(), compare);

    // LCP
    vector<int> lcpArray(len, 0), rank(len, 0);
    for(int i = 0; i < len ; i++) {
        rank[suffixArray[i].first]=i;
    }
        
    int k = 0;
    for(int i = 0; i < len ; i++){
        if(rank[i] == len-1) {
            k=0;
            continue;
        }

        int j = suffixArray[rank[i]+1].first;
        while( i + k < len && j + k < len && str[i + k]==str[j + k])
            k++;

        lcpArray[rank[i]]=k;
        if(k > 0)
            k--;
    }

    int key = 0, value = 0, total = 0;
    for(int i = 0 ; i < len ; i++){
        if(lcpArray[i] > value){
            key = i;
            value = lcpArray[i];

            total = 1;
            for(int j = i - 1; j >= 0 ; j--){
                if(suffixArray[j].second.substr(0,value) == suffixArray[i].second.substr(0,value))
                    total++;
                else
                    break;
            }
            for(int j = i + 1; j < len ; j++){
                if(suffixArray[j].second.substr(0,value) == suffixArray[i].second.substr(0,value))
                    total++;
                else
                    break;
            }
        }
    }

    if(value == 0)
        cout << "No repetitions found!\n";
    else
        cout << suffixArray[key].second.substr(0,value) << " " << total << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}