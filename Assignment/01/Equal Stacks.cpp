int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    //create three stacks that stores the sum(height) of the integer for each array. 
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;
    
    int s1_h = 0, s2_h = 0, s3_h = 0;
    
    for(int i = h1.size() - 1; i >=0; i--){
        s1_h += h1[i];
        s1.push(s1_h);
    }
    for(int i = h2.size() - 1; i >=0; i--){
        s2_h += h2[i];
        s2.push(s2_h);
    }
    for(int i = h3.size() - 1; i >=0; i--){
        s3_h += h3[i];
        s3.push(s3_h);
    }
    while(1){
        if(s1.empty() || s2.empty() || s3.empty()) return 0;
        
        s1_h = s1.top();
        s2_h = s2.top();
        s3_h = s3.top();
        
        if(s1_h == s2_h && s2_h == s3_h) return s1_h; //when the heights are the same
        
        if(s1_h >= s2_h && s1_h >= s3_h) s1.pop(); //when the first one is the highest
        else if(s2_h >= s1_h && s2_h >= s3_h) s2.pop(); //when the second one is the highest
        else s3.pop(); //else
        
    }
}

// alternative 1 provided by TA 鄧晉杰
template <typename H, typename Stack>
int SetStack (H const &h, Stack &stack)
{
  int current_height {0};
  for (auto iterator {h.rbegin()}; iterator != h.rend(); ++iterator)
  {
    stack.push(*iterator);
    current_height += stack.top();
  }
  return current_height;
}

int equalStacks
(
  std::vector<int> h1,
  std::vector<int> h2,
  std::vector<int> h3
)
{
  std::stack<int> stack_1;
  std::stack<int> stack_2;
  std::stack<int> stack_3;
  auto current_height_1 {SetStack(h1, stack_1)};
  auto current_height_2 {SetStack(h2, stack_2)};
  auto current_height_3 {SetStack(h3, stack_3)};
  while
  (
    (current_height_1 != current_height_2)
    ||
    (current_height_2 != current_height_3)
  )
  {
    if
    (
      !stack_1.empty()
      &&
      (current_height_1 >= current_height_2)
      &&
      (current_height_1 >= current_height_3)
    )
    {
      current_height_1 -= stack_1.top();
      stack_1.pop();
    }
    else if
    (
      !stack_2.empty()
      &&
      (current_height_2 >= current_height_1)
      &&
      (current_height_2 >= current_height_3)
    )
    {
      current_height_2 -= stack_2.top();
      stack_2.pop();
    }
    else if (!stack_3.empty())
    {
      current_height_3 -= stack_3.top();
      stack_3.pop();
    }
  }
  return current_height_1;
}

// alternative 2 provided by TA 鄧晉杰
int equalStacks
(
  std::vector<int> h1,
  std::vector<int> h2,
  std::vector<int> h3
)
{
  auto current_height_1 {std::accumulate(h1.begin(), h1.end(), 0)};
  auto current_height_2 {std::accumulate(h2.begin(), h2.end(), 0)};
  auto current_height_3 {std::accumulate(h3.begin(), h3.end(), 0)};
  size_t index_1 {0};
  size_t index_2 {0};
  size_t index_3 {0};
  while
  (
    (current_height_1 != current_height_2)
    ||
    (current_height_2 != current_height_3)
  )
  {
    if
    (
      (index_1 != h1.size())
      &&
      (current_height_1 >= current_height_2)
      &&
      (current_height_1 >= current_height_3)
    )
    {
      current_height_1 -= h1[index_1];
      ++index_1;
    }
    else if
    (
      (index_2 != h2.size())
      &&
      (current_height_2 >= current_height_1)
      &&
      (current_height_2 >= current_height_3)
    )
    {
      current_height_2 -= h2[index_2];
      ++index_2;
    }
    else if (index_3 != h3.size())
    {
      current_height_3 -= h3[index_3];
      ++index_3;
    }
  }
  return current_height_1;
}

// alternative provided by TA 李旺陽
int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {
    reverse(h1.begin(), h1.end());
    reverse(h2.begin(), h2.end());
    reverse(h3.begin(), h3.end());
    int s1 = accumulate(h1.begin(), h1.end(), 0);
    int s2 = accumulate(h2.begin(), h2.end(), 0);
    int s3 = accumulate(h3.begin(), h3.end(), 0);
    // note std::accumulate = init+a1+a2+a3+...+an

    while ( !(s1==s2&&s1==s3) ) {
        int mx = max({s1, s2, s3});
        if (s1 == mx) {
            s1-=h1.back();
            h1.pop_back();
        }
        if (s2 == mx) {
            s2-=h2.back();
            h2.pop_back();
        }
        if (s3 == mx) {
            s3-=h3.back();
            h3.pop_back();
        }
    }
    return s1;
}
