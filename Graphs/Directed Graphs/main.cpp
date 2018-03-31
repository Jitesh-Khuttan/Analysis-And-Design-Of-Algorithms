#include <bits/stdc++.h>
#include "graph.h"
using namespace std;

int main()
{
	int vertices,choice,u,v,weight;
	char sentinal='y';
	bool result;
	Graph G;
	cout<<"\n\tEnter The Number Of Vertices: ";
	cin>>vertices;
	G.createGraph(vertices);
	while(1)
	{
		cout<<"\n\t1.Insert An Edge\n\t2.Delete An Edge\n\t3.Traverse A Graph\n\t4.DFS\n\t5.BFS\n\t6.Detect Cycle\n\t7.Minimum Spanning Tree Using Prims\n\t8.Minimum Spanning Tree Using Kruskals\n\t9.Single Source Shortest Path(Dijkstras)\n\t10.DFID\n\t11.Exit\n\t";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\n\tEnter a vertex to insert an edge from: ";
				cin>>u;
				cout<<"\n\tEnter a vertex to insert an edge to: ";
				cin>>v;
//				cout<<"\n\tEnter the weight of an edge: ";
//				cin>>weight;
				G.insertEgde(u,v,0);
				break;
			case 2:
				cout<<"\n\tEnter a vertex to delete an edge from: ";
				cin>>u;
				cout<<"\n\tEnter a vertex to delete an edge to: ";
				cin>>v;
				G.deleteEdge(u,v);
				break;
			case 3:
				G.traverseGraph();
				break;
			case 4:
				cout<<"\n\tEnter The Source Node: ";
				cin>>v;
				G.DFS(v);
				break;
			case 5:
				cout<<"\n\tEnter The Source Node: ";
				cin>>v;
				G.BFS(v);
				break;
			case 6:
				cout<<"\n\tEnter The Source Node";
				cin>>v;
				result = G.detectCycle(v);
				if(result == true)
					cout<<"\n\tCycle Exists!";
				else
					cout<<"\n\tCycle Does Not Exists!";
				break;
			case 7:
				cout<<"\n\tEnter The Source Node";
				cin>>v;
				G.MSTprim(v);
				break;
			case 8:
				G.MSTkruskal();
				break;
			case 9:
				cout<<"\n\tEnter The Source Node";
				cin>>v;
				G.dijkstras(v);
				break;
			case 10:
				int depth;
				cout<<"\n\tEnter The Source Node: ";
				cin>>v;
				cout<<"\n\tEnter The Depth: ";
				cin>>depth;
				G.DFID(v,depth);
				break;
			case 11:
				exit(1);
		}
	}
}
