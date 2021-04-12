#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#define V 4
int minkey(int key[],bool mst[]);
void print(int parent[],int g[V][V]);
void prims(int g[V][V])
{
	int key[V], parent[V],i,count,u,v;
	bool mst[V];
	for(i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mst[i]=false;
	}
	key[0]=0;
	parent[0]=-1;
	for(count=0;count<V-1;count++)
	{
		u=minkey(key,mst);
		mst[u]=true;
		for(v=0;v<V;v++)
		{
			if(g[u][v] && mst[v]==false && g[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=g[u][v];
			}
		}
	}
	print(parent,g);
}

int minkey(int key[], bool mst[])
{
		int i,min=INT_MAX,min_index;
		for(i=0;i<V;i++)
		{
			if(mst[i]==false && key[i]<min)
			{
				min=key[i];
				min_index=i;
			}
	    }
	    return min_index;
}

void print(int parent[],int g[V][V])
{
	int i;
	printf("\n Edge\tWeight\n");
	for(i=1;i<V;i++)
	{
		printf("%d-%d\t%d\n",parent[i],i,g[i][parent[i]]);
	}
}

int main()
{
	int g[V][V]={ {0,7,0,10},
				  {7,0,8,0},
				  {0,8,0,9},
				  {10,0,9,0}};
	prims(g);
	return 0;
}
				  


