#ifndef GRAPH_ADT_
#define GRAPH_ADT_

template<typename T>
class GraphADT
{
public:

	// Checks if the graph is empty.
	
	virtual bool IsEmpty() const = 0;

	// Adds a new vertex to the graph.
	
	virtual bool AddVertex(const T& v) = 0;
	
	//Removes a vertex from the graph (if it is there).
	
	virtual bool RemoveVertex(const T& v) = 0;

	// Adds a new edge to the graph between "fromV" to "toV" with a default weighted edge of 1.
	virtual bool AddEdge(const T& fromV, const T& toV, int weight = 1) = 0;

	// Removes an edge from the graph knowing the source vertex and the destination vertex.
	virtual void RemoveEdge(const T& fromV, const T& toV) = 0;

	// Displays successors of a source node.
	virtual void DisplayNeighbors(const T& v) const = 0;

	// Checks if an edge exists from a source vertex to a destination vertex.
	virtual bool EdgeExists(const T& fromV, const T& toV) const = 0;

	// Checks if two nodes are connected back and forth.
	// returns True if an edge exists from v1 to v2 and an edge exists from v2 to v1.
	virtual bool IsAdjacent(const T& v1, const T& v2) const = 0;

	// Displays graph in a readable manner.
	virtual void PrintGraph() = 0;

	// Traverses the graph using DFS.
	
	virtual void DFS(const T& startV) const = 0;

	// Traverses the graph using BFS.
	
	virtual void BFS(const T& startV) const = 0;

	// Sorts the graph topologically.
	virtual void TopologicalSort() const = 0;

	// Destroys the graph and frees its assigned memory. */
	virtual ~GraphADT() { }
};

#endif