#include <cstdio>
#include <vector>
#include <algorithm>
#define MAX 100005
typedef long long ll;
using namespace std;

class Node{
    public:
    vector<int> sub;
    vector<ll> length;
    vector<ll> tlength;
};

Node* arr[MAX]; 
ll maxdist = 0;

ll maxpath(Node* node, Node* from){
    if(node->sub.empty())
        return 0;

    ll maxd = 0;
    for(int i = 0 ; i < node->sub.size() ; i++){
        if(arr[node->sub[i]] == from)
            continue;
        if(node->tlength[i] == -1){
            node->tlength[i] = node->length[i] + maxpath(arr[node->sub[i]],node);
        }
        maxd = max(maxd,node->tlength[i]);
    }
    return maxd;
}

void build(int n){
    int root = 0;
    for(int i = 1 ; i <= n ; i++){
        arr[i] = new Node();
    }
    
    for(int i = 1 ; i < n ; i++){
        int sor, dis; ll length;
        scanf("%d %d %lld",&sor,&dis,&length);
        if(root == 0 || root == dis){
            root = sor;
        }
        arr[sor]->sub.push_back(dis);
        arr[sor]->length.push_back(length);
        arr[sor]->tlength.push_back(-1);

        arr[dis]->sub.push_back(sor);
        arr[dis]->length.push_back(length);
        arr[dis]->tlength.push_back(-1);
    }
        
    for(int i = 1 ; i <= n ; i++){

        maxpath(arr[root],arr[root]);
        ll max1 = 0, max2 = 0;
        for(int j = 0 ; j < arr[i]->sub.size() ; j++){
            ll path = arr[i]->tlength[j];
            if(path > max1){
                max2 = max1;
                max1 = path;
            }
            else if (path > max2){
                max2 = path;
            }
        }
        maxdist = max(maxdist, max1+max2);
    }
    printf("%lld\n",maxdist);
}

int main(){
    int n;
    scanf("%d",&n);
    build(n);
}