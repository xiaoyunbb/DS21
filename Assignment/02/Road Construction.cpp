void dfs(vector<vector<pair<long, long>>> &ei, vector<long> &A, vector<vector<pair<long, bool>>> &visit, long from, long root){
    for(auto tar = 0; tar < ei[from].size(); tar++){
        if(!visit[from][tar].second){
            A[root] += ei[from][tar].second;
            visit[from][tar].second = 1;
            for(auto &e : visit[visit[from][tar].first]){
                if(e.first == from) e.second = 1;
            }
            dfs(ei, A, visit, visit[from][tar].first, root);
        }
    }
    return;
}

vector<long> CalculateCosts(long n, long m, vector<vector<long>> roads) {
    // Write your code here
    vector<vector<pair<long, long>>> edge(n);
    vector<vector<pair<long, bool>>> vis(n);
    vector<long> a(n);
    vector<bool> used(n);
    vector<long> output;
    
    for(auto &e: roads){
        long tmp1 = e[0], tmp2 = e[1], tmp3 = e[2];
        used[tmp1] = 1;
        used[tmp2] = 1;
        edge[tmp1].push_back(make_pair(tmp2, tmp3));
        vis[tmp1].push_back(make_pair(tmp2, 0));
        edge[tmp2].push_back(make_pair(tmp1, tmp3));
        vis[tmp2].push_back(make_pair(tmp1, 0));
    }
    
    for(auto i = 0; i < n; i++){
        dfs(edge, a, vis, i, i);
    }
    
    for(auto i = 0; i < a.size(); i++){
        if(a[i] != 0){
            output.push_back(a[i]);
        }
    }
    for(auto e: used){
        if(e == false) output.push_back(0);
    }
    sort(output.begin(), output.end());
    
    return output;
}
