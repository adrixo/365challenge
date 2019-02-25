#include <stdlib.h>
#include <stdio.h>

/* This function is implemented relying on internet examples, 
 * you have another one with different data types
 * at https://github.com/adrixo/Estructuras-Datos
 */


#define MAX 1024
#define INF 1000000000

int n, i, k, min, dist[MAX][MAX]; 

struct node {
	int last;
	int length;
	bool flag;
} node[MAX];

void initialize();
void extract_min();
void dijkstra(int s, int t, int path[]);

int main(){
	int initial_node, final_node, arist;

    //********

	//Initialize
	for (int i=0; i<n; i++)
	    for( int j=0; j<n; j++)
	        dist[i][j]=0;

    //********

	dijkstra(final_node, initial_node, arist)
	return 0;
}

void initialize(){
	for (p = &node[0]; p < &node[n]; p++) {
		p->last = -1;
		p->length = INF;
		p->flag = false;
	}
}

void extract_min(){
	k = 0; 
	min = INF;

	for (i = 0; i < n; i++)
		if (node[i].flag == false && node[i].length < min) {
			min = node[i].length;
			k = i;
		}
}

void dijkstra(int s, int t, int path[]) { 
	initialize();
	node[t].length = 0; node[t].flag = true;
	k = t;
	do{ /* there's a better path? */	
		
		for (int i = 0; i <n; i++)
			if (dist[k][i] != 0 && node[i].flag == false)
				if (node[k].length + dist[k][i] < node[i].length) {
					node[i].last = k;
					node[i].length = node[k].length + dist[k][i];
				}

		extract_min();
		node[k].flag = true;
	} while (k != s);

	i = 0; k = s;
	printf("The path is: ");
	do {
		prinf("%d", k);
		path[i] = k; 
		k = node[k].last; 
		i++;
	} while (k >= 0);

	printf("Dijsktra best path: %d", min);
}
