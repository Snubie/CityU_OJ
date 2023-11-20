#include <cstdio>
#include <vector>
typedef long long ll;
using namespace std;

class Node{
    public:
    ll ppl;
    Node *lnode, *rnode, *tnode;
    ll count;
    Node(){
        count = 0;
        ppl = 0; lnode = 0; rnode = 0; tnode = 0;
    };
};

Node *nodes[5005];
void solve(Node *node, Node *tree, Node *from, int layer){
    node->count += tree->ppl * (layer + 1);
    if(tree->lnode && tree->lnode != from)
        solve(node, tree->lnode, tree, layer+1);
    if(tree->rnode && tree->rnode != from)
        solve(node, tree->rnode, tree, layer+1);
    if(tree->tnode && tree->tnode != from)
        solve(node, tree->tnode, tree, layer+1);
}

void build(int n){
    for(int i = 0 ; i < n ; i++){
        nodes[i] = new Node();
    }
    Node *root = nodes[0];
    for(int i = 0 ; i < n ; i++){
        int l, r; 
        ll ppl;
        scanf("%lld %d %d",&ppl, &l, &r);
        nodes[i]->ppl = ppl;
        nodes[i]->lnode = nodes[l-1];
        nodes[i]->rnode = nodes[r-1];
        if(l)
            nodes[l-1]->tnode = nodes[i];
        if(r)
            nodes[r-1]->tnode = nodes[i];
    }
    for(int i = 0 ; i < n ; i++){
        if(nodes[i]->tnode)
            solve(nodes[i], nodes[i]->tnode, nodes[i], 0);
        if(nodes[i]->lnode)
            solve(nodes[i], nodes[i]->lnode, nodes[i], 0);
        if(nodes[i]->rnode)
            solve(nodes[i], nodes[i]->rnode, nodes[i], 0);
    }

    ll minppl = nodes[0]->count;
    for(int i = 0; i < n ; i++){
        ll total = nodes[i]->count;
        minppl = total < minppl ? total : minppl;
    }
    printf("%lld\n",minppl);
}

int main(){
    int n;
    scanf("%d",&n);
        build(n);
    return 0;
}