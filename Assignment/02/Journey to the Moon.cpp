long long dfs(vector<vector<long long>> &ei, vector<bool> &visited, long long tar){
    if(visited[tar] == true) return 0;
    visited[tar] = true;
    long long count = 1;
    for(auto i = 0; i < ei[tar].size(); ++i){
        count += dfs(ei, visited, ei[tar][i]);
    }
    return count;
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    int p = astronaut.size();
    vector<bool> vis(n);
    vector<vector<long long>> edge(n);
    
    for(auto i = 0; i < p; i++){
        edge[astronaut[i][0]].push_back(astronaut[i][1]);
        edge[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    
    long long sum = 0, as = 0;
    for(auto i = 0; i < n; ++i){
        if(!vis[i]){
            long long c = dfs(edge, vis, i);
            sum = sum + (as * c);
            as += c;
        }
    }
    return sum;
}
