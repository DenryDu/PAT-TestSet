#include <bits/stdc++.h>
using namespace std;
#define InfSet 0x3f 
#define Inf 0x3f3f3f3f   
int weight[501];
int graph[501][501];
int InOrOut[501];//0 is in, 1 represents has been picked out
int dist[501];//store the distance info (distance from src to i(dist[i])
int numRescue[501];//to calculate the num of rescue team can gather around i(numRescue[i])
int numPath[501];//to transmit the num of path to dst

int main() {
	//input from screen
    int n, m, src, dst;
    cin >> n >> m >> src >> dst;
    
    //assign the weight
    for(int i = 0; i < n; i++)
        cin >> weight[i];
  
    //init the graph
    memset(graph,InfSet,sizeof(graph));
    
    //assign the graph
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        //connection in both direction
        graph[b][a] = c;
        graph[a][b] = c;
    }
    
    //init Distance
    memset(dist, InfSet, sizeof(dist));

	//init info about src
    dist[src] = 0;
    numPath[src] = 1;
    numRescue[src] = weight[src];
 
    for(int i = 0; i < n; i++) {
        int picked = -1, mindis = Inf;
        
        //to find the min distance among all the node that left(InOrOut[j]=0)
        for(int j = 0; j < n; j++) {
            if(InOrOut[j] == 0 && dist[j] < mindis) {
                mindis = dist[j];
                picked = j;
            }
        }
        if(picked == -1)
            break;
        InOrOut[picked] = 1;
        for(int j = 0; j < n; j++) {
            //check and update
            //check connection
            if(InOrOut[j] == 0 && graph[picked][j] != Inf) {
                //check whether it needs to be updated
                if(dist[j] > dist[picked] + graph[picked][j]) {
                    //update
                    dist[j] = dist[picked] + graph[picked][j];
                    //add the weight ahead of it in such a line
                    numRescue[j] = numRescue[picked] + weight[j];
                    //transmit the num of path
                    numPath[j] = numPath[picked];
                } else if(dist[j] == dist[picked] + graph[picked][j]) {
                	//not update
                	//but need to add the num of path
                    numPath[j] = numPath[picked] + numPath[j];
                    //maintain the max weight can be gathered
                    if(numRescue[j] < numRescue[picked] + weight[j])
                        numRescue[j] = numRescue[picked] + weight[j];
                }
            }
        }
    }
 
    cout << numPath[dst] << " " << numRescue[dst];
    return 0;
}

