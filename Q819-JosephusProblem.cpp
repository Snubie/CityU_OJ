#include <iostream>
#include <vector>
using namespace std;

void solve(int m, int n){
    vector<int> list;
    for(int i = 0 ; i < m ; i++){
        list.push_back(i+1);
    }

    while(list.size()){
        vector<int> tmp;
        int size = list.size();
        tmp.assign(list.begin() ,list.begin()+((n-1)%size));
        list.erase(list.begin() ,list.begin()+((n-1)%size));
        cout << list[0];
        if(size>1) cout << " ";
        list.erase(list.begin());
        list.insert(list.end(),tmp.begin(),tmp.end());
    }
    cout << "\n";
}

int main(){
    int m, n;
    cin >> m >> n;
    solve(m, n);
    return 0;
}