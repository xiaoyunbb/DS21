vector<long> KthElements(long k, long n, vector<long> a) {
    // Write your code here
    
    vector<long> output;
    priority_queue<long, vector<long>, less<long>> temp1;
    
    for(int i = 0; i < k; i++){
        temp1.push(a[i]);
    }
    output.push_back(temp1.top());
    
    for(int i = k; i < n; i++){
        if(a[i] < temp1.top()){
            temp1.pop();
            temp1.emplace(a[i]);
        }
        output.push_back(temp1.top());
    }
    
    return output;
}
