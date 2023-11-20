#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

struct Ret{
    int cost;
    vector<int> path;
    Ret(int c, vector<int> p){
        cost = c;
        path = p;
    }
};

vector<vector<pair<int, int> > > adj; 
unordered_map<string, int> stringMap;
unordered_map<int, string> intMap;

vector<string> extract(string input){
    string s1="", s2="", s3="", s4="";
    stringstream ss(input);
    getline(ss, s1, ':');
    char tmp;
    while(stringMap.count(s2) == 0){
        ss.get(tmp);
        s2 += tmp;
    }
    ss >> s3;
    ss >> s4;

    vector<string> output(4);
    output[0] = s1; output[1] = s2; output[2] = s3; output[3] = s4;
    return output;
}

Ret dijkstra(int n, int start, int end){
    vector<int> dist(n, 0x7fffffff), loc(n,-1);
    vector<bool> checked(n, false);

    dist[start] = 0; // start pos
    for(int i = 0 ; i < n ; i++){
        
        //find minimum path
        int v = -1;
        for(int j = 0 ; j < n ; j++){
            if(!checked[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if(dist[v] == 0x7fffffff)
            break;

        checked[v] = true;

        //calculate next path
        for(int j = 0 ; j < adj[v].size() ; j++){
            int to = adj[v][j].first;
            int len = adj[v][j].second;

            if(dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                loc[to] = v;
            }
        }
    }

    vector<int> path;
    for (int l = end; l != start; l = loc[l])
        path.push_back(l);
    reverse(path.begin(), path.end());
    
    return Ret(dist[end],path);
}

void solve(int n){
    adj.clear();
    intMap.clear();
    stringMap.clear();

    adj.assign(n ,vector<pair<int, int> >());
    string str;
    cin.ignore();
    for(int i = 0 ; i < n ; i++){
        getline(cin, str);
        
        stringMap.insert({str,i});
        intMap.insert({i,str});
    }

    string s;
    int p;
    cin >> p;
    cin.ignore();
    for(int i = 0 ; i < p ; i++){
        getline(cin,s);
        vector<string> ext = extract(s);

        adj[stringMap[ext[0]]].push_back(make_pair(stringMap[ext[1]],stoi(ext[2])));
        if(ext[3] != ""){
            adj[stringMap[ext[1]]].push_back(make_pair(stringMap[ext[0]],stoi(ext[3])));
        }
    }

    Ret to = dijkstra(n, stringMap["office"], stringMap["hall"]);
    Ret back = dijkstra(n, stringMap["hall"], stringMap["office"]);

    cout << to.cost + back.cost << "\n";
    cout << "office";
    for(int i = 0 ; i < to.path.size() ; i++)
        cout << " -> " << intMap[to.path[i]];
    for(int i = 0 ; i < back.path.size() ; i++)
        cout << " -> " << intMap[back.path[i]];
    cout << "\n\n";

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    while(cin >> t){
        solve(t);
    }
    return 0;
}