#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

// GARBAGE QUESTION

char s[10000];

vector<vector<int> > adj;
vector<int> cost;

void dijkstra(int start, int end, int size){

    vector<int> dist(size, 0x7fffffff), loc(size,-1);
    vector<bool> checked(size, false);

    dist[start] = 0; // start pos
    for(int i = 0 ; i < size ; i++){
        
        //find minimum path
        int v = -1;
        for(int j = 0 ; j < size ; j++){
            if(!checked[j] && (v == -1 || dist[j] < dist[v]))
                v = j;
        }

        if(dist[v] == 0x7fffffff)
            break;

        checked[v] = true;

        //calculate next path
        for(int j = 0 ; j < adj[v].size() ; j++){
            if(adj[v][j] != 0 && adj[v][j] != -1){ 
                int to = j;
                int len = adj[v][j];

                if(dist[v] + len + cost[v] < dist[to]){
                    dist[to] = dist[v] + len + cost[v];
                    loc[to] = v;
                }
            }

        }
    }

    vector<int> path;
    for (int l = end; l != start; l = loc[l])
        path.push_back(l);
    reverse(path.begin(), path.end());

    printf("From %d to %d :\n", start+1, end+1);
    printf("Path: %d",start+1);
    for(int i = 0 ; i < path.size() ; i++){
        printf("-->%d",path[i]+1);
    }
    if(start != end)
        printf("\nTotal cost : %d\n", dist[end] - cost[start]);
    else
        printf("\nTotal cost : 0\n");
}

void solve(){
   fgets(s,10000,stdin);
   char* token = strtok(s, " ");
   vector<int> tmparr;
   int size =  0;
   while(token != NULL){
       tmparr.push_back(atoi(token));
       size++;
       token = strtok(NULL, " ");
   }

   adj = vector<vector<int> >(size, vector<int>(size));
   cost = vector<int>(size);

   adj[0] = tmparr;
   for(int i = 1 ; i < size ; i++){
       for(int j = 0 ; j < size ; j++){
           scanf("%d",&adj[i][j]);
       }
   }

   for(int i = 0 ; i < size ; i++){
        scanf("%d",&cost[i]);
   }
    
    getchar(); // remove \n

    char tmp[10000];
    fgets(tmp,10000,stdin);
    while(true){

        if(tmp[0] == '\n')
            break;
        else{
            char* inn = strtok(tmp," ");
            int start = atoi(inn);
            inn = strtok(NULL, " ");
            int end = atoi(inn);
            inn = strtok(NULL, " ");
            dijkstra(start-1, end-1, size);
        }

        if(fgets(tmp,10000,stdin) == NULL)
            break;
        else
            printf("\n");
    }
}

int main(){

    int t;
    scanf("%d", &t);
    getchar(); // remove first & second \n
    getchar(); 
    while(t--){
        solve();
    }

    return 0;
}