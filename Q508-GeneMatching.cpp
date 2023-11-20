#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Suffix{
    int index = 0, rank = 0, nrank = 0;

    void update(int i, int r, int n){
        index = i ; rank = r ; nrank = n;
    }

    bool operator< (Suffix const &s) const{
        if(rank == s.rank)
            return nrank < s.nrank;
        return rank < s.rank;
    }
};

vector<int> suffixArr(string str){
    int len = str.size();
    vector<int> out(len);
    vector<Suffix> suff(len);

    for(int i = 0 ; i < len ; i++){
        out[i] = str[i];
    }

    int cnt = 1;
    for(int i = 1 ; (1 << i) < len ; i <<= 1){

        for (int j = 0 ; j < len ; j++) {
            suff[j].update(j, out[j], i + j < len ? out[i + j] : -1);
        }

        sort(suff.begin(), suff.end());

        for(int j = 0 ; j < len ; j++){
            if(j > 0 && suff[j].rank == suff[j - 1].rank && suff[j].nrank == suff[j - 1].nrank)
                out[suff[j].index] = out[suff[j - 1].index];
            else
                out[suff[j].index] = j;
        }
    }

    for(int i = 0 ; i < len ; i++)
        out[i] = suff[i].index;

    return out;
}

vector<int> lcpArr(string str, vector<int> suffix){
    int len = str.size();

    vector<int> out(len, 0), rank(len, 0);
    for(int i = 0; i < len ; i++) {
        rank[suffix[i]] = i;
    }
        
    int k = 0;
    for(int i = 0; i < len ; i++){
        if(rank[i] == len-1) {
            k=0;
            continue;
        }

        int j = suffix[rank[i]+1];
        while( i + k < len && j + k < len && str[i + k] == str[j + k])
            k++;

        out[rank[i]]=k;
        if(k > 0)
            k--;
    }

    return out;
}

void solve(){
    string str;
    cin >> str;

    int len = str.size();
    vector<int> suffix = suffixArr(str);
    vector<int> lcp = lcpArr(str, suffix);
    vector<string> suffixlist(len);

    for(int i = 0 ; i < len ; i++){
        suffixlist[i] = str.substr(suffix[i]);
    }
    cout << "My algo\n";
    for(int i = 0 ; i < len ; i++){
        cout << suffixlist[i] << "\n";
    }

    sort(suffixlist.begin(), suffixlist.end());
    cout << "sort\n";
    for(int i = 0 ; i < len ; i++){
        cout << suffixlist[i] << "\n";
    }

    // int m;
    // cin >> m;
    // for(int i = 0 ; i < m ; i++){
    //     string pattern;
    //     cin >> pattern;
        
    //     auto lb = lower_bound(suffixlist.begin(), suffixlist.end(), pattern);
    //     auto ub = upper_bound(suffixlist.begin(), suffixlist.end(), pattern);

    //     cout << (ub - lb) << "\n";
    // }

    // for(int i = 0 ; i < len ; i++){
    //     cout << suffixlist[i] << "\n";
    // }

}


int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
