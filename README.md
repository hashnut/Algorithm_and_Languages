# Coding_Algorithm
 Algorithms for Coding test and more (including src codes for various problems)

<br><br/>

# Online solving website
- [LeetCode](https://leetcode.com/)
- [BAEKJOON](https://www.acmicpc.net/)
- [Samsung SW Expert Academy](https://swexpertacademy.com/main/main.do)

<br><br/>

## BFS

Breadth-First-Search

**Used for vertices closer to the given source & unweighted graph**

Time complexity : 
 1. O(V+E) : When adjacency list is used
 2. O(V^2) : When adjacency matrix is used


<br><br/>


## DFS

**Used for vertices far from the given source & disjoint set**

Time complexity : 
 1. O(V+E) : When adjacency list is used
 2. O(V^2) : When adjacency matrix is used



<br><br/>


## Union-Find

<br><br/>


# Graph

Graph algorithms, including `shortest distance` and `MST`

<br><br/>

## Dijkstra 

**[Find shortest distance from the starting point](https://yabmoons.tistory.com/364)**
> Doesn't work when there is negative-weighted edge

Time complexiey : 
 1. O(V^2) : Naive visit (traverse all nodes and edges)
 2. O(ElogV) : Using priority queue

<br><br/>

## Bellman-Ford 

**[Find shortest distance from the starting point](https://ratsgo.github.io/data%20structure&algorithm/2017/11/27/bellmanford/)**
> Doesn't work when there is negative cycle
> Also used to check if there is negative cycle
> Dynamic Programming : `dist[n] = min(distance[n], distance[m] + E(m, n))`

Time complexity : O(VE)

[Bellman-Ford and Negative cycle](https://ssungkang.tistory.com/m/entry/Algorithm-%EB%B2%A8%EB%A7%8C%ED%8F%AC%EB%93%9CBellman-Ford-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)

<br></br>


## Floyd-Warshall

**[Find shortest distance for all pairs](https://ansohxxn.github.io/algorithm/floyd/)**
> Dynamic programming : `dist[i,j] = min(dist[i,k] + dist[k,j], dist[i,j])`


Time complexity : O(V^3)

<br><br/>


## Prim

**[Find minimum spanning tree](https://kbw1101.tistory.com/m/52)**
> Greedy, add edges to the heap as you traverse through vertices

Time complexity :
 1. O(ElogV) : Using binary Heap
 2. O(E + VlogV) : Using fibonacci Heap

<br><br/>


## Kruskal

**[Find minimum spanning tree](https://ansohxxn.github.io/algorithm/mst/)**
> Sort edges, and select min edges with disjoint set
> Suitable when there is few edges in the graph

Time complexity : O(ElogE or ElogV)

<br><br/>



## Topological Sort

**[]()**

Time complexity :
 1.

<br><br/>


## LCA (Lowest-Common-Ancestor)

**[]()**

Time complexity :
 1.

<br><br/>


## Articulation Point(Bridge)

**[]()**

Time complexity :
 1.

<br><br/>


## HLD (Heavy-Light Decomposition)

**[]()**

Time complexity :
 1.

<br><br/>


# Dyanamic Programming

****

<br><br/>


## Knapsack, LCS, Stick

**[]()**

Time complexity :
 1.

<br><br/>


## LIS

**[]()**

Time complexity :
 1.

<br><br/>
<br><br/>

## Euclidean Algorithm

**[]()**

Time complexity :
 1.

<br><br/>


## Sieve of Eratosthenes

**[]()**

Time complexity :
 1.

<br><br/>


## Parametric search

**[]()**

Time complexity :
 1.

<br><br/>



