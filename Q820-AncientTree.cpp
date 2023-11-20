#include <cstdio>
#include <vector>
using namespace std;

class Node{
    public:
    int name;
    bool breakable;
    vector<Node*> sub;
    Node(){
        breakable = true;
    };
    Node(int n){
        name = n;
        breakable = true;
    }
};

int solve(int &count, Node* tree){
    for(int i = 0 ; i < tree->sub.size() ; i++){
        if(tree->sub[i]->breakable){
            tree->sub.erase(tree->sub.begin()+i);
            count++;i--;
        }else{
            solve(count, tree->sub[i]);
        }
    }
    return count;
}

void build(){
    int m, n, count = 0;
    Node base;
    scanf("%d %d",&m, &n);
    for(int i = 0 ; i < m + n ; i++){
        Node* tbase = &base;
        while(true){
            int temp;
            scanf("%d",&temp);
            if(temp != -1){
                int index = -1;
                for(int j = 0 ; index < 0 && j < tbase->sub.size() ; j++)
                    if(tbase->sub[j]->name == temp)
                        index = j;
                if(index < 0){
                    Node* nnode = new Node(temp);
                    tbase->sub.push_back(nnode);
                    if(i >= m){
                        tbase->breakable = false;
                        nnode->breakable = false;
                    }
                    tbase = nnode;
                }else{
                    if(i >= m)
                        tbase->breakable = false;
                    tbase = tbase->sub[index];
                }
            }else{
                break;
            }
        }
    }
    solve(count, &base);
    printf("%d\n",count);
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        build();
    }
    return 0;
}