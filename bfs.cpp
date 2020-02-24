#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > adj;
vector<bool>used;
vector<int>d, p;
/*
void bfs(int s){
    queue<int>q;
    q.push(s);
    used[s]=true;
    p[s]=-1;
    d[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<adj[x].size();i++){
            if(!used[adj[x][i]]){
                used[adj[x][i]]=true;
                q.push(adj[x][i]);
                d[adj[x][i]]=d[x]++;
                p[adj[x][i]]=x;

            }
        }
    }
}
*/
void bfs(int s){
    queue<int>q;
    q.push(s);
    used[s]=true;
    p[s]=-1;
    d[s]=0;

    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int u:adj[x]){
            if(!used[u]){
                used[u]=true;
                q.push(u);
                d[u]=d[x]++;
                p[u]=x;

            }
        }
    }
}


int main()
{

}
