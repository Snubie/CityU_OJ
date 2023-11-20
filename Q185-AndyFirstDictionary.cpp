#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string lines, words;
    set<string> dict;
    while(getline (cin,lines)){

        int size = lines.size();
        for(int i = 0 ; i < size ; i++){
            if(lines[i] >= 'A' && lines[i] <= 'Z'){
                lines[i] = (lines[i] - 'A' + 'a');
            }else if(lines[i] >= 'a' && lines[i] <= 'z'){

            }else{
                lines[i] = ' ';
            }
        }

        stringstream ss(lines);
        while(ss >> words){
            dict.insert(words);
        }
    }

    for(auto it = dict.begin(); it != dict.end() ; it++){
        cout << *it << "\n";
    }
    
    return 0;
}