#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

void solve(string str){
    stack<long long> list;
    stringstream ss(str);
    char value;
    while(ss >> value){
        if(value >= '0' && value <= '9'){
            list.push((long long)(value-'0'));
        }else if(value == '+' || value == '-' || value == '*'){
            long long b = list.top();
            list.pop();
            long long a = list.top();
            list.pop();
            long long res = 0;
            if(value == '+'){
                res = a + b;
            }else if(value == '*'){
                res = a * b;
            }else{
                res = a - b;
            }
            list.push(res);
        }
    }
    cout << list.top() << "\n";
}

int main(){
    string str;
    while(getline(cin, str)){
        solve(str);
    }
    return 0;
}