#include <cstdio>
#define MAX 100005
using namespace std;
typedef long long ll;

class Node{
    public:
    ll info;
    Node *lnode, *rnode;
    Node(ll i, Node *l = 0, Node *r = 0){
        info = i;
        lnode = l;
        rnode = r;
    }
};
class MinHeap{
    public:
    int size;
    Node* arr[MAX];
    MinHeap(){
        size = 0;
    }
    void swap(int i1, int i2){
        Node* t = arr[i1];
        arr[i1] = arr[i2];
        arr[i2] = t;
    }

    void push(Node* n){
        arr[size] = n;
        int tsize = size;
        while(tsize > 0 && arr[tsize]->info < arr[(tsize-1)/2]->info){
            swap(tsize, (tsize-1)/2);
            tsize = (tsize-1)/2;
        }
        size++;
    }
    Node* pop(){
        if(size == 0) return 0;
        
        Node* rr = arr[0];
        arr[0] = arr[size-1];
        arr[size-1] = 0;
        size--;

        int tsize = 0;
        while(tsize*2+1 < size){
            int index = tsize*2+1;
            if(index+1 < size && arr[index+1]->info < arr[index]->info)
                index++;
            if(arr[index]->info < arr[tsize]->info)
                swap(tsize,index);
            else
                break;
            tsize = index;
        }
        return rr;
    }
};

ll ans = 0;

void solve(Node* n, int layer){
    if(n->lnode)
        solve(n->lnode,layer+1);
    if(n->rnode)
        solve(n->rnode,layer+1);
    if(n->lnode == 0 && n->rnode == 0)
        ans += n->info * layer;

}
void build(int n){
    MinHeap heap;
    for(int i = 0 ; i < n ; i++){
        ll temp;
        scanf("%lld",&temp);
        heap.push(new Node(temp));
    }
    while(heap.size != 1){
        Node* n1 = heap.pop();
        Node* n2 = heap.pop();
        Node* n = new Node(n1->info+n2->info,n1,n2);
        heap.push(n);
    }
    ans = 0;
    Node *tmp = heap.pop();
    solve(tmp,0);
    printf("%lld\n",ans);
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        build(n);
    }
    return 0;
}