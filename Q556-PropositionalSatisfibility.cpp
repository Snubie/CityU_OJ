#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <stack>
#include <unordered_map>
typedef long long ll;
using namespace std;

int priority(char ch){
    if(ch == '!')
        return 3;
    if(ch == '&')
        return 2;
    if(ch == '+')
        return 1;
    return 0;
}

vector<char> buildPostfix(vector<char> in){
    stack<char> s;
    vector<char> out;
    for(int i = 0 ; i < in.size() ; i++){
        if(in[i] >= 'a' && in[i] <= 'z'){
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
    return out;
}

bool solvePostfix(unordered_map<char, bool> bf, vector<char> postfix){
    stack<bool> stack;
    for(int i = 0 ; i < postfix.size() ; i++){
        if(postfix[i] >= 'a' && postfix[i] <= 'z'){
            stack.push(bf[postfix[i]]);
        }else if(postfix[i] == '!'){
            bool val = stack.top();
            stack.pop();
            stack.push(!val);
        }else if(postfix[i] == '&'){
            bool val1 = stack.top();
            stack.pop();
            bool val2 = stack.top();
            stack.pop();
            stack.push(val1 && val2);
        }else if(postfix[i] == '+'){ 
            bool val1 = stack.top();
            stack.pop();
            bool val2 = stack.top();
            stack.pop();
            stack.push(val1 || val2);
        }
    }
    return stack.top();
}

bool solve(unordered_map<char, bool> bf, vector<char> postfix){
    long long size = 1 << bf.size();
    for(int i = 0 ; i < size ; i++){
        bool flag = solvePostfix(bf,postfix);
        if(flag)
            return true;
        
        for(auto it = bf.begin(); it != bf.end() ; it++){
            it->second = !it->second;
            if(it->second)
                break;
        }        
    }
    
    return false;
}

int main(){
    char input[105];
    while(fgets(input,105,stdin) != NULL){
        vector<char> in;
        unordered_map<char, bool> bf;
        for(int i = 0 ; input[i] ; i++){
            if(input[i] != ' ' && input[i] != '\n'){
                if(input[i] >= 'a' && input[i] <= 'z')
                    bf.insert({input[i], false});
                in.push_back(input[i]);
            }
        }      

        //build postfix
        vector<char> postfix = buildPostfix(in);
        bool ans = solve(bf, postfix);
        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}