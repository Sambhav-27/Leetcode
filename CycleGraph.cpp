
// undirected
// if we reach a node again and it is not the parent of the node then there is a cycle i.e. two different paths to a node
// this doesn't work for multi edges

unordered_map<int, vector<int>> gr;

bool isCyclic(int v, int parent) {
	visited[v] = 1;

	for(auto child: gr[v]) {

		if(visited[child] && child != parent) {
			return 1;
		}


		if(!visited[child]) {
			if (isCyclic(child, v)) {
				return 1;
			}
		}
	}
	return 0;
}


// directed
// two different path to a node doesn't mean there is a cycle. That's why we need to keep track of all elements seen in cur recursion stack
// if seen in same recurStack and is visited again that means there is a cycle.
// this same algo cannot be used for undirected graph because we need to keep track of parent. a simaple graph A<->B will call it as cycle with this algo

bool isCyclic(int v) {
	visited[v] = 1;
	recurStack[v] = 1;

	for(auto child: gr[v]) {

		if(visited[child] && recurStack[child]) {
			return 1;
		}

		if (!visited[child]) {
			if(isCyclic(child)) {
				return 1;
			}
		}
	}

	recurStack[v] = 0;
	return 0;
}
