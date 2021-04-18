vector<long> TopKIntegerSequence(vector<vector<long>> matrix) {
    vector<long> ans;
    priority_queue<long, vector<long>, greater<long>> q;
    
    for(auto &row: matrix){
        for(auto i: row){
            q.emplace(i);
        }
        ans.push_back(q.top());
        q.pop();
    }
    return ans;
}

// alternative 1 provided by TA 鄧晉杰
std::vector<long> TopKIntegerSequence (std::vector<std::vector<long>> matrix)
{
  std::vector<long> top_k_integer_sequence;
  std::vector<long> min_heap;
  auto compare {std::greater<long>{}};
  for (auto const &row : matrix)
  {
    for (auto const &entry : row)
    {
      min_heap.emplace_back(entry);
      std::push_heap(min_heap.begin(), min_heap.end(), compare);
    }
    top_k_integer_sequence.emplace_back(min_heap.front());
    std::pop_heap(min_heap.begin(), min_heap.end(), compare);
    min_heap.pop_back();
  }
  return top_k_integer_sequence;
}

// alternative 2 provided by TA 鄧晉杰
std::vector<long> TopKIntegerSequence (std::vector<std::vector<long>> matrix)
{
  std::vector<long> top_k_integer_sequence;
  std::priority_queue<long, std::vector<long>, std::greater<long>> min_heap;
  for (auto const &row : matrix)
  {
    for (auto const &entry : row)
    {
      min_heap.push(entry);
    }
    top_k_integer_sequence.emplace_back(min_heap.top());
    min_heap.pop();
  }
  return top_k_integer_sequence;
}
