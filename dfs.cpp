#include<bits/stdc++.h>
using namespace std;

map<int,int>vis;
map<int,map<int,int> > path;

//void itaDFS(int s){
//
//    stack<int>st;
//    st.push(s);
//    vis[s]=1;
//    while(!st.empty()){
//        int t=st.top();
//        st.pop();
//
//        for(int i=0;i<path[t].size();i++){
//            if(!vis[path[t][i]]){
//                st.push(path[t][i]);
//                vis[path[t][i]]=1;
//            }
//        }
//    }
//
//}

void itaDFS(int s){
    stack<int>st;
    st.push(s);
    vis[s]=1;

    while(!st.empty()){
        int t=st.top();
        st.pop();

        for(int u:path[t]){
            if(!vis[u]){
                st.push(u);
                vis[u]=1;
            }
        }

    }

}

void recDFS(int s){
    vis[s]=1;

    for(int u:path[s]){
        if(!vis[u])
            dfs(u);
    }

}


int main()
{

}
