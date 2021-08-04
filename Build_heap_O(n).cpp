priority_queue<int> q{v.begin(), v.end())

buildHeap(vector<int> v) {
	
  for(i=v.size()-1; i>=0; --)
	heapify(v, i) // heapify downards
}

This is O(n) and not nlogn;

Heap is a complete binary tree;

Leaf nodes are at height 0;

total nodes at height h = ceil(n/2^(h+1))

1 node at height h takes h operations in heapify

thus, total operations for all nodes at height h = ceil(n/(2^(h+1)) * h


Total operation across all nodes = sum[ceil(n/(2^(h+1)) * h] for h belongs [0, logn]

= n/2 sum[ h/(2^h)] for h belongs to [0, logn]

<= n/2 sum[h/(2^h)] for h belongs to [0, INF]

<= n;


cause sum[h/(2^h)] for h belongs to [0, INF} is 2. It is an hp. proof in cormen
