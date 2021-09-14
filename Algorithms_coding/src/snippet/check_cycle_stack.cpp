//#include <vector>
//#include <stack>

// # of nodes
#define N 10000

struct Edge
{
	int from;
	int to;
};


// # of incoming edges
int inCnt[N+1];
bool visit[N+1];
vector<int> adj[N+1];



bool check_cycle()
{
	int cur;

	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == false && inCnt[i] == 0)
		{
			stack<int> my_stack;
			my_stack.push(i);

			while(!my_stack.empty())
			{
				cur = my_stack.top();
				my_stack.pop();
				visit[cur] = true;

				for (int nxt : adj[cur])
				{
					inCnt[nxt]--;
					if (inCnt[nxt] == 0)
					{
						my_stack.push(nxt);
					}
				}
			}
		}
	}


	// if all nodes are visited, then no cycle
	int check_visit = 0;

	for (int i = 1; i <= N; i++)
		if (visit[i]) check_visit++;
		else return true;
	
	if (check_visit == N) return false;
	else return true;

}

