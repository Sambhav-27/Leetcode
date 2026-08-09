/*

disjkistra only works for non negative weights.
it gives shortest distance from source node to all other nodes.

Different from bfs in 2 aspects-
1. Use min heap to process closer neighbors first
2. BFS marks node as visited when it first sees it. Dijkistra marks as visited when it's popped from min heap.

In a standard BFS, once you see a node, you mark it as "visited" immediately so you never push it to the queue again.
In Dijkstra, you cannot do that. Because weights vary, you might find a node early via a long path, 
and then find a much shorter path to that same node later.
Therefore, you update its distance and push it into the min-heap again. A node is only truly finalized when it 
is popped out of the min-heap, not when it is pushed in



*/


#define N 100000
#define INF 1e6

struct Edge {
	int id; // this is more like a target node
	int weight;

	Edge(int t, int w) {
		id = t;
		weight = w;
	}
};


struct comp{
	bool operator() (const Edge &a, const Edge &b) {
		return a.weight > b.weight;
	}
};

unordered_map<int, vector<Edge>> gr;
priority_queue<Edge, vector<Edge>, comp> q; // min heap

vector<bool> visited(N);

vector<int> dist(N, INF);


int dijkistra(int src, int target) {

	q.push(Edge(src, 0));
	dist[src] = 0;


	while(!q.empty()) {
		Edge parent = q.top(); q.pop();


		if(visited[parent.id]) {
			continue;
		}
		visited[parent.id] = 1; // only mark visited when it's popped

		for(auto child : gr[parent.id]) {

			if(!visited[child.id] && dist[parent.id] + child.weight < dist[child.id]) {
				dist[child.id] = dist[parent.id] + child.weight;
				q.push(Edge(child.id, dist[child.id])); // push the new weight
			}
			
		}
		
	}

	return dist[target];

}
