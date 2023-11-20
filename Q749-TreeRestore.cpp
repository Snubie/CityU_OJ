#include <cstdio>
#include <vector>
using namespace std;

vector<int> solve(vector<int> preorder, vector<int> inorder){
    int size = preorder.size();
    if( size <= 1){
        return preorder; // base
    }
    int root = preorder[0], index;
    for(index = 0 ; index < size ; index++){
        if(inorder[index] == root)
            break;
    }

    vector<int> p1, p2, i1, i2, answer, temp;
    p1.assign(preorder.begin()+1,preorder.begin()+1+index);
    p2.assign(preorder.begin()+1+index,preorder.end());

    i1.assign(inorder.begin(),inorder.begin()+index);
    i2.assign(inorder.begin()+1+index,inorder.end());

    temp = solve(p1, i1);
    answer.insert(answer.end(), temp.begin(), temp.end());
    temp = solve(p2, i2);
    answer.insert(answer.end(), temp.begin(), temp.end());
    answer.push_back(root);
    return answer;

}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N, temp;
        vector<int> preorder;
        vector<int> inorder;
        scanf("%d",&N);
        for(int i = 0 ; i < N ; i++){
            scanf("%d", &temp);
            preorder.push_back(temp);
        }
        for(int i = 0 ; i < N ; i++){
            scanf("%d", &temp);
            inorder.push_back(temp);
        }

        vector<int> result = solve(preorder,inorder);
        for(int i = 0 ; i < N ; i++){
            if( i != 0 )
                printf(" ");
            printf("%d",result[i]);
        }
        printf("\n");
    }
    return 0;
}