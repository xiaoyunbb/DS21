long WinScore(vector<long> HaruUraraAbility, vector<long> TokaiTeioAbility) {
    // Write your code here
    long sum = 0;
    auto N = HaruUraraAbility.size();
    vector<long> H;
    vector<long> T;
    H.assign(HaruUraraAbility.begin(), HaruUraraAbility.end());
    T.assign(TokaiTeioAbility.begin(), TokaiTeioAbility.end());
    sort(H.begin(), H.end());
    sort(T.begin(), T.end());
    
    long it = 0;
    
    for(auto i = 0; i < N; i++){
        for(auto j = it; j < N; j++){
            if(H[i] <= T[j]){
                it = j;
                sum += it;
                break;
            }
            else if(H[i] > T[j] && j == N - 1){
                sum += N;
                break;
            }
        }
    }
    
    return sum;
}
