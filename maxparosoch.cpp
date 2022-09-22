#include <bits/stdc++.h>

using namespace std;
const int ogranichenie_na_kolvo_vershin = 50;
vector<int> match(ogranichenie_na_kolvo_vershin,-1);
vector<bool>used(ogranichenie_na_kolvo_vershin);
bool dfs(vector<vector<int>>& g, int v){
    if(used[v]){return false;}
    used[v] = true;
    for(int u:g[v]){
        if(match[u]==-1 || dfs(g,match[u])){
            match[u] = v;
            return true;
        }
    }
    return false;
}
vector<int> max_parosochetanie (vector<vector<int>> g, int n){
    for(int v = 0;  v < n; ++v){
        fill(used.begin(),used.end(),false);
        bool t = dfs(g,v);
    }
    vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(match[i]==-1) continue;
        ans.push_back(match[i]);
    }
    return ans;
}
