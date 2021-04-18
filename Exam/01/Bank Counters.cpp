vector<long> SimulateBankCounters(long k, vector<vector<long>> instructions) {
    vector<long> output;
    vector<priority_queue<long, vector<long>, greater<long>>> counter(k);
    int gid = 1;
    
    auto m = instructions.size();
    
    for(auto i = 0; i < m; i++){
        long ops = instructions[i][0];
        if(ops == 1){
            int cid = instructions[i][1];
            
            counter[cid].emplace(gid);
            gid++;
        }
        else if(ops == 2){
            int cid = instructions[i][1];
            
            counter[cid].pop();
        }
        else if(ops == 3){
            int cidFrom = instructions[i][1];
            int cidTo = instructions[i][2];
            
            while(!counter[cidFrom].empty()){
                counter[cidTo].emplace(counter[cidFrom].top());
                counter[cidFrom].pop();
            }
        }
    }
    
    for(auto i = 0; i < k; i++){
        output.push_back((counter[i].empty()) ? -1 : counter[i].top());
    }
    return output;
}
