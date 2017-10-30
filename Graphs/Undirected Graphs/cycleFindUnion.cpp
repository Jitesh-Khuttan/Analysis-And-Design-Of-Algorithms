#include<bits/stdc++.h>
using namespace std;

typedef struct
{
	int from,to;
}Edge;

typedef struct 
{
	int edges,vertices;
	Edge *links;
}Graph;

Graph G;
int *parent;

void createGraph()
{
	cout<<"Enter the number of vertices: ";
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

bool detectCycle()
{
	int counter,parentOfFrom,parentOfTo;
	for(counter=0;counter<G.vertices;counter++)
	{
		parent[counter] = -1;
	}
	for(counter=0;counter<G.vertices;counter++)
	{
		parentOfFrom = find(G.links[counter].from);
		parentOfTo =  find(G.links[counter].to);
		if(parentOfFrom == parentOfTo)
			return true;
		Union(parentOfFrom,parentOfTo);
	}
	return false;
}

int main()
{
	int counter;
	bool cycle;
	createGraph();
	for(counter=0;counter<G.edges;counter++)
	{
		cout<<"Edge From: "; cin>>G.links[counter].from;
		cout<<"Edge To: "; cin>>G.links[counter].to;
	}
	cycle = detectCycle();
	if(cycle == true)	cout<<"\n\tCycle Detected!";
	else	cout<<"\n\tCycle Not Found";
}