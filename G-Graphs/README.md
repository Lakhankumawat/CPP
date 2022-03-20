# Bipartite Graph

A graph Can be said bipartite when  the graph can be **coloured using 2 colours only such a way that no 2 adjacent vertex will be of same colour**.

---
![Bipartite Graph](https://i0.wp.com/algorithms.tutorialhorizon.com/files/2019/09/Even-and-odd-cycles-Bipartite-Graph-1.png?resize=563%2C264)
---

##   **APPROACH::** <br>
It is possible to test whether a graph is bipartite or not using a BFS Algorithm
There are 2 ways to check for a bipartite graph:
*  A graph is a bipartite graph if and only if it is colorable by 2 colors only.
While doing BFS traversal m the given Graph, each node in the BFS tree is given its parent’s opposite color. If there exists an edge connecting the current vertex to a previously colored vertex with the same color, then we can say that the graph is not bipartite.

* A graph is a bipartite graph if and only if it contains an odd cycle(Cycle contains Odd number of vertices)
If a graph contains an odd, we cannot divide the graph such that every adjacent vertex has a different color. If in the BFS, we find an edge, if both of its endpoints are at the same level, then the graph is not Bipartite and an odd-cycle is found.

*Here in the explanation, we use the 1st approach of the BFS algorithm to check whether a given graph I bipartite or not.*

---
## Algorithm to check Biparite or not:
   >  *We will be Doing it by BFS tarversal
        main moto is to check if all nodes are coloured with opposite colours using only 2 colours*
    <br>
    1. Take a **Queue** data structure ans push the source node, take array **color[node]={-1}** we have to color using 1 and 0.
    <br>
    2. colour queue\<top> with  0 pop from queue and push it's adjacent nodes into 
    queue and color with oppsoite colour if not coloured before<br>
    3. If coloured before with same colour then break , its not bipartite.
    <br>
    4.pop the top and push top's adjacent and colour with opposite colour
    5. pop and repeat previous steps until queue is empty

---
***P.S.:***  If the Graph is not have odd length cycle it's Biparite for sure.

---
## Complexity Analysis:
 >***Time Comlexity :*** O(N+E)
 <br>//N=number of nodes and E=no. of edges.
>***Space Complexity:*** O(N+E)+O(N)+O(N)
<br>//O(N+E) for adjacency List , O(N) for color array, O(N) for queue.
---

## Code Analysis

```cpp
//Main function used to check bipartite graph
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); //initialise colour array with -1
    for(int i = 0;i<n;i++) {// for loop for multiple component graph
        if(color[i] == -1) {//if any node is not coloured call bipartiteBfs
            if(!bipartiteBfs(i, adj, color)) {
                return false;
            }
        }
    }
    return true; 
}
```
---
```cpp
//bipartiteBfs() which is used to do BFS on all over the nodes
bool bipartiteBfs(int src, vector<int> adj[], int color[]) {
    //src=Source Node
    queue<int>q;
    q.push(src); 
    color[src] = 1; //1st node coloured with 1
    while(!q.empty()) {// code will run untill queue is empty
        int node = q.front(); 
        q.pop();
        
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node]; //if not coloured , colour with opposite colour
                q.push(it); 
            } else if(color[it] == color[node]) {
                return false; // if previously coloured with same colour return false;
            }
        }
    }
    return true; 
}
```
---

## Input & Output:

***1.***

![bipartite1](https://user-images.githubusercontent.com/77873383/157034893-7bff7c34-665e-4600-a10c-b50fa355931c.jpg)

***2.***

![bipartite2](https://user-images.githubusercontent.com/77873383/157035024-9cd7dcdb-6ff4-405b-b75d-aa90f1b40b7c.jpg)