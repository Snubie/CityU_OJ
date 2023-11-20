#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
typedef long long ll;
using namespace std;

// basically reusing my Q556 buildpostfix function

int priority(char ch){
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '+' || ch == '-')
        return 1;
    return 0;
}

void buildPostfix(vector<char> in){
    stack<char> s;
    vector<char> out;
    for(int i = 0 ; i < in.size() ; i++){
        if(in[i] >= '0' && in[i] <= '9'){
            out.push_back(in[i]);
        }else if(in[i] == '('){
            s.push(in[i]);
        }else if(in[i] == ')'){
            while(s.top() != '('){
                out.push_back(s.top());
                s.pop();
            }
            s.pop();
        }else{
            while(!s.empty() && priority(in[i]) <= priority(s.top())){
                out.push_back(s.top());
                s.pop();
            }
            s.push(in[i]);
        }
    }
    while(!s.empty()){
        out.push_back(s.top());
        s.pop();
    }

    for(int i = 0 ; i < out.size() ; i++)
        cout << out[i];
    cout << "\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    string temp;
    cin >> t;
    getline(cin,temp); // remove "\n"
    getline(cin,temp); // remove "\n"
    while(t--){
        vector<char> in;
        while(getline(cin, temp)){
            if(temp.size())
                in.push_back(temp[0]);
            else
                break;
        }
        buildPostfix(in);

        if(t)
            cout << "\n";
    }

    return 0;
}