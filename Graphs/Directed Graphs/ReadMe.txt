This is code is both for directed and undirected graphs (implemented using Adjacency List Representation).

If you enter the number of nodes in a graph to be (say 6). Then the numbering of nodes goes like this (0,1,2,3,4,5).

So to enter an edge from one node to another, enter the node number in range [0,totalNodes-1]. (In above case [0-5]).

To make the graph undirected(i.e. insert edges both ways), goto	

void Graph :: insertEgde(int u,int v,int weight)

funtion in file graph.cpp and uncomment the last two lines 

//adjlist[v].insertNode(u,weight); 
//totalEdges++;