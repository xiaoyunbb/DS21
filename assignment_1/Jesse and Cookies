int cookies(int k, vector<int> A) {
    int res = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    
    for(auto i: A) q.emplace(i);
    
    while(q.size() > 1 && q.top() < k){
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        q.emplace(a + 2 * b);
        res++;
    }
    return q.top() >= k ? res : -1;
}

// alternative 1 provided by TA 鄧晉杰
int cookies (int k, vector<int> A)
{
  int number_operations {0};
  std::make_heap(A.begin(), A.end(), std::greater<int>{});
  while
  (
    (A.size() != 1)
    &&
    (A.front() < k)
  )
  {
    auto first_min {A.front()};
    std::pop_heap(A.begin(), A.end(), std::greater<int>{});
    A.pop_back();
    auto second_min {A.front()};
    std::pop_heap(A.begin(), A.end(), std::greater<int>{});
    A.pop_back();
    A.emplace_back(first_min + 2 * second_min);
    std::push_heap(A.begin(), A.end(), std::greater<int>{});
    ++number_operations;
  }
  if (A.front() < k)
  {
    return -1;
  }
  return number_operations;
}

// alternative 2 provided by TA 鄧晉杰
int cookies (int k, vector<int> A)
{
  int number_operations {0};
  std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
  for (auto const &a : A)
  {
    min_heap.push(a);
  }
  while
  (
    (min_heap.size() != 1)
    &&
    (min_heap.top() < k)
  )
  {
    auto first_min {min_heap.top()}; min_heap.pop();
    auto second_min {min_heap.top()}; min_heap.pop();
    min_heap.push(first_min + 2 * second_min);
    ++number_operations;
  }
  if (min_heap.top() < k)
  {
    return -1;
  }
  return number_operations;
}
