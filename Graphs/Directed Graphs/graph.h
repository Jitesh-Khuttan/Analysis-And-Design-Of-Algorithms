#ifndef GRAPH
#define GRAPH

#include "linkedlist.h"
#include "node.h"
#include "queue.h"
#include <bits/stdc++.h>
using namespace std;

			/* ********************************************************* */
								/*Graph Class*/


class Graph
{
	private:
		LinkedList *adjlist;
		Queue Q;
		int vertices,totalIncludedVertices,totalEdges;
		int *child,*minWeight;
		int edges;
		bool *visited,*inqueuestate,*included,*finished;
		bool backedge;
		typedef struct 
		{	
			int from,to,weight;
		}KruskalWeights;
		void DFStraversal(int);
		void DFIDtraversal(int,int);
		void BFStraversal(int);
		void Cycle(int);
		void prims();
		void kruskal();
		static int compare(KruskalWeights,KruskalWeights);
	public:
		Graph();
		void createGraph(int);
		void insertEgde(int,int,int);
		void deleteEdge(int,int);
		void traverseGraph();
		void DFS(int);
		void DFID(int,int);
		void BFS(int);
		bool detectCycle(int);
		void MSTprim(int);
		void MSTkruskal();
		void dijkstras(int v);
};

#endif
