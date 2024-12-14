#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];
typedef int ShortPathTable[MAXVEX];
void ShortestPath_Dijskstra(MGraph G, int v0, Patharc *P, ShortPathTable *D){
	int v,w,k,min;
	int final[MAXVEX];
	for(v=0;v<G.numVertexes;v++){
		final[v]=0;
		(*D)[v]=G.arc[v0][v];
		(*P)[v]=0;
	}
	(*D)[v0]=0;
	final[v0]=1;
	for(v=1;v<G.numVertexes;v++){
		min=INFINITY;
		for(w=0;w<G.numVertexes;w++){
			if(!final[w]&&(*D)[w]<min){
				k=w;
				min=(*D)[w];
			}
		}
		final[k]=1;
		for(w=0;w<G.numVertexes;w++){
			if(!final[w]&&(min+G.arc[k][w]<(*D)[w])){
				(*D)[w]=min+G.arc[k][w];
				(*P)[w]=k;
			}
		}
	}
} 
