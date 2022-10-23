#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include "menu.h"
#define MAX 1000
using namespace std;

class Graph
{
	private:
		int v, e;
		int A[MAX][MAX];
		vector <int> adj[MAX]; // luu dinh ke
		vector <pair <int, int> > edge; // luu danh sach canh
		int deg[MAX];
	public:
		Graph(int, int);
		void setDinh(int v);
		int getDinh();
		void docMaTranKe(FILE *fin);
		void docDsCanh(FILE *fin);
		void docDsKe(FILE *fin);
		void inMaTranKe(FILE *fout);
		void inDsCanh(FILE *fout);
		void inDsKe(FILE *fout);
		void tinhBacCuaDinh();
		void inBacCuaDinh(FILE *fout);
		
};

//============================================
Graph:: Graph(int v, int e)
{
	this->v=v;
	this->e=e;
}

void Graph::setDinh(int v)
{
	this->v=v;
}

int Graph::getDinh()
{
	return v;
}
void Graph::docMaTranKe(FILE *fin)
{
	for(int i=0; i<v; i++)
    {	
    	for(int j=0; j<v; j++)	
    	{	
    		fscanf(fin,"%d",&this->A[i][j]);
			printf("%d", A[i][j] );
        }    
    }	
}


void Graph::docDsKe(FILE *fin)
{
	char buf[MAX];
	int c, i=-1;
	while(fgets(buf, MAX, fin)!=NULL)
	{
		i++;
		for(int j=0; j<sizeof(buf); j++)
		{
			int c = buf[j]-'0';
			if(c>0)
			{
				adj[i].push_back(c);
			}		
		}
	}
}


void Graph::docDsCanh(FILE *fin)
{
	int sta, end;
    while(!feof(fin))
    {	
    		fscanf(fin,"%d %d", &sta, &end);
    		edge.push_back({sta, end});
    }
}

void Graph::inMaTranKe(FILE *fout)
{
	fprintf(fout,"%s \n", "Ma tran ke");
	for(int i=0; i<v; i++)
    {	
    	for(int j=0; j<v; j++)	
    	{	
    		fprintf(fout, "%d ", A[i][j]);
        } 
		fprintf(fout, "%s", "\n");  
    }
}

void Graph:: inDsCanh(FILE *fout)
{
	fprintf(fout, "%s", "Danh sach canh");
	for (auto it: edge)
	{
		fprintf(fout, "%d %d", it.first, it.second);
		//cout << it.first << " " << it.second << endl;
	}
} 

void Graph:: inDsKe(FILE *fout)
{
	fprintf(fout, "%s", "Danh sach ke");
	for (int i=0; i<v; i++)
	{
		fprintf(fout, "%d :", i+1);
		for(int it: adj[i])
		{
			fprintf(fout, "%d ", it);
		}

	}
	
}

void Graph:: tinhBacCuaDinh()
{
	for(int i=0; i<v; i++)
    {	
    	int sum=0;
    	for(int j=0; j<v; j++)	
    	{	
    		sum+=A[i][j];
        }  
		deg[i]=sum;  
	}
}

void Graph:: inBacCuaDinh(FILE *fout)
{
	for(int i=0; i<v; i++)
	{
		fprintf(fout, "%d : %d \n", i+1, deg[i]);
	}
}


