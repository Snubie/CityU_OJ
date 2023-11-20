#include <iostream>
#include <vector>
#include <bitset>
typedef long long ll;
using namespace std;

//braindead on this question now....

int main(){
    vector<int> mem(40,0);
    int count = 0;
    string op;
    while(cin >> op){
        for(int i = 0 ; i < 8 ; i++){
            mem[count] += (op[i] - '0') * (1 << (7-i));
        }
        count++;

        if(count == 32){
            int accu = 0, pc = 0;
            while(true){
                int cmds = (mem[pc] & 224) >> 5;
                int adds = mem[pc] & 31;

                pc++;
                if(pc == 32) 
                    pc = 0;

                if(cmds == 0){
                    mem[adds] = accu;
                }else if(cmds == 1){
                    accu = mem[adds];
                }else if(cmds == 2){
                    if(accu == 0)
                        pc = adds;
                }else if(cmds == 3){
                    //
                }else if(cmds == 4){
                    accu--;
                    if(accu == -1)
                        accu = 255;
                }else if(cmds == 5){
                    accu++;
                    if(accu == 256)
                        accu = 0;
                }else if(cmds == 6){
                    pc = adds;
                }else if(cmds == 7){
                    for(int i = 128 ; i > 0 ; i /= 2){
                        cout << ((accu & i) != 0);
                    }
                    cout << "\n";
                    break;
                }
                
            }
            // reinit
            count = 0;
            mem = vector<int>(40,0);
        }
    }
    return 0;
}