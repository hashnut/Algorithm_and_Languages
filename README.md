# Coding_Algorithm
 Algorithms for Coding test and more (including src codes for various problems)

<br><br/>

# Online solving website
- [LeetCode](https://leetcode.com/)
- [BAEKJOON](https://www.acmicpc.net/)
- [Samsung SW Expert Academy](https://swexpertacademy.com/main/main.do)

<br><br/>

## BFS

**Used for vertices closer to the given source & unweighted graph**
> Use queue

Time complexity : 
 1. O(V+E) : When adjacency list is used
 2. O(V^2) : When adjacency matrix is used


<br><br/>


## DFS

**Used for vertices far from the given source & disjoint set**
> Use recursion or stack 

Time complexity : 
 1. O(V+E) : When adjacency list is used
 2. O(V^2) : When adjacency matrix is used



<br><br/>


## Union-Find

**[Used for tree-style disjoint set](https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html)**
> Path compression `find(int a)` : `parent[a] = find(parent[a])`
> Weighted union-find using rank : `if (rank[a] == rank[b]) {rank[a]++}`


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

**[Sort nodes in DAG](https://zoomkoding.github.io/algorithm/2019/07/02/Topological-Sort-1.html)**
> Sort nodes using incoming edge
> Used when nodes have precedence/order
> Add node with zero incoming edges and update them during sorting


<br><br/>


## LCA (Lowest-Common-Ancestor)

**[Find lowest node that has both v and w as descendants, wheere we define each node to be a descendant of itself](https://kibbomi.tistory.com/m/201)**
> Step 1 (Depths) : DFS or BFS to update depths and `parent[0][a]`(2^0 the parent of `a`)
> Step 2 (Connect) : Update parent information
> Step 3 (LCA) : Synchronize difference of depth and jump from 2^k to 2^0 (k = CEIL.log2(N))

Time complexity :
 1. O(N) : Naive, you shouldn't do that
 2. O(logN) : Jump up to 2^k (not considering preprocessing)

<br><br/>


## Articulation Point(Bridge)

**[Find if the node could divide graph into disjoint set](https://www.crocus.co.kr/1164)**
> Use DFS to check values of "order of visit"
> If it is impossible to get to nodes having smaller "order of visit", then it is articulation point

Time complexity : O(V+E)

<br><br/>


## HLD (Heavy-Light Decomposition)

**[Divide tree with chain so that you can use them as 1D array](https://www.secmem.org/blog/2019/12/12/HLD/)**


<br><br/>


# Dyanamic Programming

**Optimal substructure & overlapping subproblems**

<br><br/>


## Cutting rod, Knapsack, LCS

**[Basics : Cutting rod, Knapsack, LCS](https://www.zerocho.com/category/Algorithm/post/584b979a580277001862f182)**
> Cutting Rod : `R[n] = max(P[i] + R[n-i])`, where i is from 1 to n
> 0/1 Knapsack : `M[i][C] = max(M[i-1][C], M[i-1][C-w[i-1]] + v[i-1])`, when `C >w[i-1]`, where `C` is available weight, `i` stands for the number of item in the knapsack, `w[]` is weight array for items and `v[]` is value array for items
> Fractional Knapsack : (Greedy) Sort items in descending order according to values and fill the bag
> LCS (Value) : If `left[i] == right[j]` than `res[i][j] = res[i-1][j-1] + 1`, if not same, `res[i][j] = max(res[i-1][j], res[i][j-1]`
> LCS (String) : Using `res[]` in the above, start from `res[n][m]` to `res[0][0]`, add character when `left[i] == right[j]`


<br><br/>

## Matrix Chain Multiplication

**[O(N^3) Matrix Chain Multiplication](https://www.zerocho.com/category/Algorithm/post/584b979a580277001862f182)**
> 3 for loop : length -> start idx -> end idx (for loop ... k -> st to end)
> `M[i, j] = min(M[i, k] + M[k+1, j] + p[i-1]*p[k]*p[j])`, where `k` is from `i` to `j-1`
> If you use Strassen's algorithm, O(N^2.7)


<br><br/>

## LIS

**[Find longest increasing sequence, using DP and binary search](https://shoark7.github.io/programming/algorithm/3-LIS-algorithms#5)**
> Next element : n, current length : count, `C[count] = last`
> If last < n, `C[count+1] = n`, else `C[i] = n`, where `C[i-1] < n <= C[i]`

Simple code :
```
for (int i = 0; i < sizeof(arr)/sizeof(*arr); i++)
{
 if (C[count] < arr[i]) 
  { C[++count] = arr[i]; continue;}
 else 
  {int idx = lower_bound(C, C+count, arr[i]) - C; C[idx] = arr[i]}
}
```

Time complexity : O(NlogN)

<br><br/>

## Extended Euclidean Algorithm

**[How to solve for "ax +by = d" when "GCD(a, b) = d"](https://baeharam.github.io/posts/algorithm/extended-euclidean/)**
> GCD : `int gcd(int a, int b){ if (!b) return a; else return gcd(b, a%b);}`
> Bezout's Identity : when `gcd(a,b) = d`, there exists `x`, `y` which satisfies `ax + by = d` and `d` is the smallest possible integer
> Solve out for recurrence relation : 
![image](https://user-images.githubusercontent.com/26838115/131449080-99c217ef-c35d-407e-a664-1280d5dd6318.png)
![image](https://user-images.githubusercontent.com/26838115/131449096-15f3c7fe-4841-4000-aed1-749217a783ca.png)
![image](https://user-images.githubusercontent.com/26838115/131449106-535fdc88-83d3-43ea-8bd0-7c934fabcfd7.png)
![image](https://user-images.githubusercontent.com/26838115/131449117-243bbed1-54b1-4819-b49c-575905558429.png)


<br><br/>


## Sieve of Eratosthenes

**[When you have to get list of prime numbers...](https://velog.io/@max9106/Algorithm-%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98-%EC%B2%B4)**
> Initialize array to its own value
> Starting from `i = 2`, set `arr[idx]=0` when `idx % i == 0` (But not itself)
> Print all remaining numbers where `arr[idx] != 0`

<br><br/>




