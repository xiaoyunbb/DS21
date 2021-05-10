void dfs(vector<vector<long>> &tr, vector<vector<long>> &res, long const from, long const root){
    for(auto &tar: tr[from]){
        if(tr[tar].empty()){
            res[root].push_back(tar);
        }
        else{
            dfs(tr, res, tar, root);
        }
    }
    return;
}

long CalculateGangAsset(long n, long root_id, vector<vector<long>> edges, vector<long> assets) {
    vector<vector<long>> e(n);
    for(auto &i: edges){
        e[i[0]].push_back(i[1]);
    }
    
    vector<vector<long>> a(n);
    for(auto i = 0; i < n; i++){
        dfs(e, a, i, i);
    }
    vector<long> tot(n, 0);
    for(auto i = 0; i < a.size(); i++){
        if(a[i].empty()) tot[i] += assets[i];
        for(auto j = 0; j < a[i].size(); j++){
            if(!a[i].empty()) tot[i] += assets[a[i][j]];
        }
    }
    sort(tot.begin(), tot.end());
    
    return tot[n - 1];
}
