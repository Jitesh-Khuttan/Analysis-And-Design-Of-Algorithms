#include<bits/stdc++.h>
using namespace std;

typedef struct
{
	int from,to,weight;
}Edge;

typedef struct 
{
	int edges,vertices;
	Edge *links;
}Graph;

Graph G,MST;
int *parent,mstWeight=0;

void createGraph()
{
	cout<<"\n\tEnter the number of vertices: ";
	cin>>G.vertices;
	cout<<"\n\tEnter the number of edges in a graph: ";
	cin>>G.edges;
	G.links = new Edge[G.edges];
	parent = new int[G.vertices];
}

int find(int v)
{
	if(parent[v] == -1)
		return v;
	return find(parent[v]);
}

void Union(int u,int v)
{
	int setofu,setofv;
	setofu = find(u);
	setofv = find(v);
	parent[setofu] = setofv;
}

bool compare(Edge E1,Edge E2)
{
	return(E1.weight < E2.weight);
}

bool kruskals()
{
	int counter,parentOfFrom,parentOfTo,offset;
	MST.links = new Edge[G.vertices-1];		//n-1 edges in the MST
	MST.vertices = G.vertices;
	MST.edges = 0;
	for(counter=0;counter<G.vertices;counter++)
	{
		parent[counter] = -1;
	}
	sort(G.links,G.links+G.vertices,compare);
	for(counter=0,offset=0;counter<G.vertices;counter++)
	{
		MST.links[offset].from = G.links[counter].from;
		MST.links[offset].to = G.links[counter].to;
		MST.links[offset].weight = G.links[counter].weight;
		parentOfFrom = find(G.links[offset].from);
		parentOfTo =  find(G.links[counter].to);
		if(parentOfFrom != parentOfTo)
		{	
			mstWeight += MST.links[offset].weight;
			offset++;
			MST.edges++;
			Union(parentOfFrom,parentOfTo);
		}
	}
	if(MST.edges = G.vertices-1)
		return true;
	else 
		return false;
}

int main()
{
	int counter;
	bool result;
	createGraph();
	for(counter=0;counter<G.edges;counter++)
	{
		cout<<"\n\tEdge From: "; cin>>G.links[counter].from;
		cout<<"\n\tEdge To: "; cin>>G.links[counter].to;
		cout<<"\n\tWeight: "; cin>>G.links[counter].weight;
	}
	result = kruskals();
	if(result == true)
	{
		cout<<"\n\tMST Created!\n\tFrom\tTo\tWeight";
		for(counter=0;counter<MST.edges;counter++)
		{
			cout<<"\n\t"<<MST.links[counter].from<<"\t"<<MST.links[counter].to<<"\t"<<MST.links[counter].weight;
		}
		cout<<"\n\tMST weight: "<<mstWeight<<endl;
	}
	else	
	{
		cout<<"\n\tMST cannot be created!\n";
	}
}