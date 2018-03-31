#include "graph.h"

Graph :: Graph() {}

void Graph :: createGraph(int vertices)
{
	this->vertices = vertices;
	totalIncludedVertices = 0;
	totalEdges = 0;
	adjlist = (LinkedList*)calloc(vertices,sizeof(LinkedList));
	visited = (bool*)calloc(vertices,sizeof(bool));
	finished = (bool*)calloc(vertices,sizeof(bool));
	included = (bool*)calloc(vertices,sizeof(bool));
	child = (int*)calloc(vertices,sizeof(int));
	minWeight = (int*)calloc(vertices,sizeof(int));
	inqueuestate = (bool*)calloc(vertices,sizeof(bool));
	Q = vertices; //Setting The Length Of The Queue
}

void Graph :: insertEgde(int u,int v,int weight) //Ordered Pair (u,v)
{
	if(u > vertices-1 && v > vertices-1 )
	{
		cout<<"\n\t"<<u<<" and "<<v<<" Vertices Not Available";
		return;
	}

	else if(u > vertices-1 )
	{
		cout<<"\n\t"<<u<<" Vertice Not Available";
		return;
	}

	else if(v > vertices-1)
	{
		cout<<"\n\t"<<v<<" Vertice Not Available";
		return;
	}

	adjlist[u].insertNode(v,weight);
	totalEdges++;
//	adjlist[v].insertNode(u,weight);	
//	totalEdges++;
}


void Graph :: deleteEdge(int u,int v)
{

	Node* temp;
	if(u > vertices-1 && v > vertices-1 )
	{
		cout<<"\n\t"<<u<<" and "<<v<<" Vertices Not Available";
		return;
	}

	else if(u > vertices-1 )
	{
		cout<<"\n\t"<<u<<" Vertice Not Available";
		return;
	}

	else if(v > vertices-1)
	{
		cout<<"\n\t"<<v<<" Vertice Not Available";
		return;
	}

	temp = adjlist[u].getHead();

	if(temp == NULL)
	{
		cout<<"\n\tThere Is No Outgoing Edge From "<<u;
		return;
	}

	while(temp->getData() != v)
	{
		temp = temp->getNextNodeAddress();
		if(temp == NULL) break;
	}

	if(temp == NULL)
	{
		cout<<"\n\tNo Egde From "<<u<<" to "<<v<<".";
		return;
	}

	adjlist[u].deleteNode(v);	
	totalEdges--;
}

void Graph :: traverseGraph()
{
	Node* temp;
	int check=0;
	for(int counter=0;counter<vertices;counter++)
	{
		temp = adjlist[counter].getHead();
		if(temp==NULL)
		{
			check++;
		}
	}
	if(check == vertices)
	{
		cout<<"\n\tGraph Is Empty";
		return; 
	}
	cout<<"\n\tThere are Directed Edges from:";
	for(int counter=0;counter<vertices;counter++)
	{
		temp = adjlist[counter].getHead();
		if(temp!= NULL)
		{
			cout<<"\n\t"<<counter<<" to ";
			adjlist[counter].traverseList();
		}	
	}
}

void Graph :: DFS(int v)
{
	int counter;
	for(counter=0;counter<vertices;counter++)
	{
		visited[counter] = false;
	}
	cout<<"\n\tDepth First Traversal: ";
	DFStraversal(v);
}

void Graph :: DFStraversal(int v)
{
	visited[v] = true;
	cout<<v<<" ";
	Node* temp = adjlist[v].getHead();
	while(temp!=NULL)
	{
		if(visited[temp->getData()] == false)
		{
			DFStraversal(temp->getData());
		}
		temp = temp->getNextNodeAddress();
	}
} 


void Graph :: DFID(int v,int depth)
{
	int counter;
	for(counter=0;counter<vertices;counter++)
	{
		visited[counter] = false;
	}
	cout<<"\n\tDFID Traversal: ";
	for(counter=0;counter<=depth;counter++)
	{
//		cout<<"Inside Loop";
		DFIDtraversal(v,counter);
		cout<<"\n\t";
	}
}

void Graph :: DFIDtraversal(int v,int currentDepth)
{
	if(visited[v] == false)
		cout<<v<<" ";
	if(currentDepth <= 0 )
		return;
	visited[v] = true;
	Node* temp = adjlist[v].getHead();
	while(temp!=NULL)
	{
		if(visited[temp->getData()] == false)
		{
			DFIDtraversal(temp->getData(),currentDepth-1);
		}
		temp = temp->getNextNodeAddress();
	}
}


void Graph :: BFS(int v)
{
	int counter;
	for(counter=0;counter<vertices;counter++)
	{
		visited[counter] = false;
		inqueuestate[counter]=false;
	}
	cout<<"\n\tBreadth First Traversal: ";
	BFStraversal(v);
}

void Graph :: BFStraversal(int v)
{
	cout<<v<<" ";
	visited[v] = true;
	Node* temp = adjlist[v].getHead();
	while(temp!=NULL)
	{
		if(inqueuestate[temp->getData()] == false && visited[temp->getData()] == false)
		{
			Q.enqueue(temp);
			inqueuestate[temp->getData()] = true;
		}
		temp = temp->getNextNodeAddress();
	}
	// cout<<"\n\tQueue Elements: ";
	// for(int counter=Q.getfront();counter<=Q.getrear();counter++)
	// {
	// 	cout<<Q.print(counter)<<" ";
	// }
	if(!Q.isEmpty())
	{
		temp = Q.dequeue();
		BFStraversal(temp->getData());
	}
}

	/* ******** Detection Of Cycle In A Graph Using Depth First Search ****** */

bool Graph :: detectCycle(int v)
{
	int counter;
	for(counter=0;counter<vertices;counter++)
	{
		visited[counter] = false;
		finished[counter] = false;
	}
	backedge = false;
	Cycle(v);
	return backedge;
}

void Graph :: Cycle(int v)
{
	visited[v] = true;
	//cout<<"\n\tTotal Calls: "<<totalTraversals;
	Node* temp = adjlist[v].getHead();
	while(temp!=NULL)
	{
		if(visited[temp->getData()] == true && finished[temp->getData()] == false)
		{
			backedge = true;
			return;
		}
		if(visited[temp->getData()] == false)
			Cycle(temp->getData());
		if(backedge == true)
			return;
		temp = temp->getNextNodeAddress();
	}
	finished[v] = true;
}

void Graph :: MSTprim(int v)
{
	int counter;
	for(counter=0;counter<vertices;counter++)
	{
		included[counter] = false;
	}
	for(counter=0;counter<vertices;counter++)
	{
		minWeight[counter] = 9999;
	}
	included[v] = true;
	totalIncludedVertices += 1;
	// cout<<"\n\tTotal Included Vertices: "<<totalIncludedVertices;
	prims();
}

void Graph :: prims()
{
	Node* temp;
	int counter,minindex,minWeightInList=9999,minNumberInList=9999,minimum=9999,mstWeight=0;
	Graph MST;
	MST.createGraph(vertices);
	while(totalIncludedVertices != vertices)
	{
		for(counter=0;counter<vertices;counter++)
		{
			if(included[counter] == true)
			{
				temp = adjlist[counter].getHead();
				while(temp!=NULL)
				{
					if(temp->getWeight() < minWeightInList && included[temp->getData()] == false)
					{
						minWeightInList = temp->getWeight(); //Gives Least Weight Value
						minNumberInList = temp->getData(); //Gives Node Number
					}
					temp = temp->getNextNodeAddress();
				}
				child[counter] = minNumberInList;
				minWeight[counter] = minWeightInList;
			}	
		}

		for(counter=0;counter<vertices;counter++)
		{
			if(minWeight[counter] < minimum)
			{
				minimum = minWeight[counter];
				minindex = counter;
			}
		}
		MST.insertEgde(minindex,child[minindex],minWeight[minindex]);
		included[child[minindex]] = true;
		totalIncludedVertices += 1;
		mstWeight += minWeight[minindex];
		minWeightInList=99999;minNumberInList=99999;minimum=99999;
	}
	MST.traverseGraph();
	cout<<"\n\tMinimum Weight of MST: "<<mstWeight;
}

int Graph :: compare(KruskalWeights object1,KruskalWeights object2)
{
	return(object1.weight < object2.weight);
}

void Graph :: MSTkruskal()
{
	// int counter;
	// for(counter=0;counter<vertices;counter++)
	// 	included[counter] = false;
	kruskal();
}

void Graph :: kruskal()
{
	KruskalWeights sortedWeights[totalEdges];
	Node* temp;
	Graph MST;
	int minWeight=0;
	bool cycle;
	MST.createGraph(vertices);
	int counter,offset=0;
	for(counter=0;counter<vertices;counter++)
	{	
		temp = adjlist[counter].getHead();
		while(temp!=NULL)
		{
			sortedWeights[offset].from = counter;
			sortedWeights[offset].to = temp->getData();
			sortedWeights[offset].weight = temp->getWeight();
			offset++;
			temp = temp->getNextNodeAddress();
		}	
	}
	//Sorting the edges in the non-decreasing order.
	sort(sortedWeights,sortedWeights+totalEdges,compare);
	// for(counter=0;counter<totalEdges;counter++)
	// {
	// 	cout<<"\n\tFrom: "<<sortedWeights[counter].from<<" To: "<<sortedWeights[counter].to;
	// }
	counter=0;
	while(counter<totalEdges && MST.totalEdges != vertices-1)
	{
		//if(included[sortedWeights[counter].from] == false && included[sortedWeights[counter].to] == false)
		{
			MST.insertEgde(sortedWeights[counter].from,sortedWeights[counter].to,sortedWeights[counter].weight);
			cycle = MST.detectCycle(sortedWeights[0].to);
			if(cycle == true)
				MST.deleteEdge(sortedWeights[counter].from,sortedWeights[counter].to);
			else
			{
				minWeight += sortedWeights[counter].weight;
				included[sortedWeights[counter].from] = true;
				included[sortedWeights[counter].to] = true;
			}
		}
		counter++;
	}
	if(MST.totalEdges == this->vertices-1)
	{
		cout<<"\n\tMST Created!";
		MST.traverseGraph();
		cout<<"\n\tMinimum Weight Of The MST is: "<<minWeight<<endl;
	}
	else
	{
		cout<<"\n\tMST Cannot be created!";
	}
}

void Graph :: dijkstras(int source)
{
	int counter,recentlyIncluded,totalIncluded=0,miniWeightVertex,miniWeight;
	int minimumWeight[vertices];
	Node* temp;
	for(counter=0;counter<vertices;counter++)
	{
		included[counter] = false;
		minimumWeight[counter] = 99999;
	}
	minimumWeight[source] = 0;
	included[source] = true;
	recentlyIncluded = source;
	while(totalIncluded != vertices)
	{
		temp = adjlist[recentlyIncluded].getHead();
		while(temp!=NULL)
		{
			if(minimumWeight[temp->getData()] > minimumWeight[recentlyIncluded] + temp->getWeight())
			{
				minimumWeight[temp->getData()] = minimumWeight[recentlyIncluded] + temp->getWeight();
			}
			temp = temp->getNextNodeAddress();
		}
		miniWeight = 100000;
		for(counter=0;counter<vertices;counter++)
		{
			if(miniWeight > minimumWeight[counter] && included[counter] == false)
			{
				miniWeight = minimumWeight[counter];
				miniWeightVertex = counter;
			}
		}
		recentlyIncluded = miniWeightVertex;
		included[recentlyIncluded] = true;
		totalIncluded++;
	}
	cout<<"\n\tThe Shortest Distance of Vertices From "<<source<<" are ";
	cout<<"\n\n\tSource\tDestination\tDistance";
	for(counter=0;counter<vertices;counter++)
	{
		cout<<"\n\t"<<source<<"\t"<<counter<<"\t\t"<<minimumWeight[counter];
	}
}
