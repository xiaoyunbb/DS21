long LaunchDonations(vector<long> savings, vector<long> moneys) {
    // Write your code here
    priority_queue<long, vector<long>, greater<long>> s;
    auto N = moneys.size();
    
    for(auto i: savings){
        s.emplace(i);
    }
    
    for(auto i = 0; i < N; i++){
        long temp = s.top() + moneys[i];
        s.pop();
        s.emplace(temp);
    }
    
    while(s.size() > 1){
        s.pop();
    }
    
    return s.top(); 
}
