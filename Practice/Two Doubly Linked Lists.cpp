vector<long> PerformOperationsOnLists(vector<vector<long>> operations) {
    // Write your code here
    vector<list<long>> L(2);
    
    for(auto const& ops : operations){
        switch(ops[0]){
            case 0:{
                auto id = ops[1];
                auto pos = ops[2];
                auto val = ops[3];
                auto ptr = L[id].begin();
                
                advance(ptr, pos);
                L[id].insert(ptr, val);
                break;
            }
            case 1:{
                auto id = ops[1];
                auto pos = ops[2];
                auto ptr = L[id].begin();
                
                advance(ptr, pos);
                L[id].erase(ptr);
                break;
            }
            case 2:{
                auto idTo = ops[1];
                auto posTo = ops[2];
                auto idFrom = ops[3];
                auto posFrom = ops[4];
                auto ptrTo = L[idTo].begin();
                auto ptrFrom = L[idFrom].begin();
                
                advance(ptrTo, posTo);
                advance(ptrFrom, posFrom);
                L[idTo].splice(ptrTo, L[idFrom], ptrFrom, L[idFrom].end());
                break;
            }
        }
    }
    vector<long> res;
    for(auto i: L[0]) res.emplace_back(i);
    for(auto i: L[1]) res.emplace_back(i);
    return res;
}
