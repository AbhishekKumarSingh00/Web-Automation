#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n, m;
vector < pair <int, ll> > graph[1000000];
ll dist[1000000];
bool possible;
bool visited[1000000];

void dfs(int start){
    
    visited[start] = true;
    
    if(!possible){
        return;
    }
    
    vector < pair <int, ll> >::iterator itr;
    for(itr = graph[start].begin(); itr != graph[start].end(); itr++){
        int v = itr->first;
        int w = itr->second;
        if(visited[v]){
            if(dist[v] != dist[start]+w){
                possible = false;
                return;
            }
        } else {
            dist[v] = dist[start]+w;
            dfs(v);
        }
    }
    
}

int main(){
    
    cin >> t;
    
    while(t--){
        
        cin >> n >> m;
        
        for(int i = 0; i <= n; i++){
            visited[i] = false;
            graph[i].clear();
            dist[i] = -1;
        }
        while(m--){
            
            int u, v;
            ll w;
            cin >> u >> v >> w;
            
            graph[u].push_back(make_pair(v, w));
            graph[v].push_back(make_pair(u, -1*w));
        
        }
        
        possible = true;
        
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i);
            }
        }
        
        if(possible){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        
    }
    
    return 0;
    
}