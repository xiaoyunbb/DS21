string CheckIfConnected(long nodes_size, vector<vector<long>> edges, long x, long y) {
    // Write your code here
    vector<vector<long>> E(nodes_size);
    for(auto vec: edges){
        long from = vec[0];
        long to = vec[1];
        E[from].emplace_back(to);
        E[to].emplace_back(from);
    }
    
    vector<bool> used(nodes_size);
    stack<long> st;
    
    st.emplace(x);
    used[x] = 1;
    
    while(!st.empty()){
        long cur = st.top();
        st.pop();
        
        for(long e: E[cur]){
            if(!used[e]){
                st.emplace(e);
                used[e] = 1;
            }
        }
    }
    return used[y] ? "yes" : "no";
}

// alternative 1 (BFS) provided by TA 鄧晉杰
template <typename Graph, typename IsDiscovered>
void BFS
(
  Graph const &graph,
  IsDiscovered &is_discovered,
  long source
)
{
  std::deque<long> nodes;
  is_discovered[source] = true;
  nodes.emplace_back(source);
  while (!nodes.empty())
  {
    auto from {nodes.front()}; nodes.pop_front();
    for (auto to : graph[from])
    {
      if (!is_discovered[to])
      {
        is_discovered[to] = true;
        nodes.emplace_back(to);
      }
    }
  }
  return;
}

string CheckIfConnected
(
  long nodes_size,
  std::vector<std::vector<long>> edges,
  long x,
  long y
)
{
  std::vector<std::vector<long>> graph(nodes_size);
  for (auto edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_discovered(nodes_size, false);
  BFS(graph, is_discovered, x);
  if (is_discovered[y])
  {
    return "yes";
  }
  return "no";
}

// alternative 2 (DFS) provided by TA 鄧晉杰
template <typename Graph, typename IsVisited>
void DFS
(
  Graph const &graph,
  IsVisited &is_visited,
  long source
)
{
  std::deque<long> nodes;
  nodes.emplace_back(source);
  while (!nodes.empty())
  {
    auto from {nodes.back()};
    nodes.pop_back();
    if (!is_visited[from])
    {
      is_visited[from] = true;
      for (auto to : graph[from])
      {
        nodes.emplace_back(to);
      }
    }
  }
  return;
}

string CheckIfConnected
(
  long nodes_size,
  std::vector<std::vector<long>> edges,
  long x,
  long y
)
{
  std::vector<std::vector<long>> graph(nodes_size);
  for (auto edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_visited(nodes_size, false);
  DFS(graph, is_visited, x);
  if (is_visited[y])
  {
    return "yes";
  }
  return "no";
}

// alternative 3 (DFS - recursive version) provided by TA 鄧晉杰
/* note: this alternative is limited if depth of recursion is too large */
template <typename Graph, typename IsVisited>
void RecursiveDFS
(
  Graph const &graph,
  IsVisited &is_visited,
  long from
)
{
  is_visited[from] = true;
  for (auto to : graph[from])
  {
    if (!is_visited[to])
    {
      RecursiveDFS(graph, is_visited, to);
    }
  }
  return;
}

string CheckIfConnected
(
  long nodes_size,
  std::vector<std::vector<long>> edges,
  long x,
  long y
)
{
  std::vector<std::vector<long>> graph(nodes_size);
  for (auto edge : edges)
  {
    graph[edge[0]].emplace_back(edge[1]);
    graph[edge[1]].emplace_back(edge[0]);
  }
  std::vector<bool> is_visited(nodes_size, false);
  RecursiveDFS(graph, is_visited, x);
  if (is_visited[y])
  {
    return "yes";
  }
  return "no";
}
