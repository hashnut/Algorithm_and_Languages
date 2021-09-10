import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class LCA
{
	static int N;
	static int Q;
	static int LGN;
	static int ROOT = 1;
	static int parent[][];
	static int depth[];
	static ArrayLIst<Interger> adjList[];

	public static void main(String[] args) throws Exception
	{		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String Tokenizer st;

		int tc = Integer.parseInt(br.readLine());

		for (int t = 1; t <= tc; t++)
		{
			// 전처리
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			Q = INteger.parseInt(st.nextToken());

			LGN = (int) (Math.ceil(Math.log(N) / Math.log(2)));

			depth = new int[N+1];
			adjList = new ArrayList[N+1];
			
			for (int i = 1; i <= N; i++)
			{
				depth[i] = -1;
				adjList[i] = new ArrayList<>();
			}

			parent = new int[LGN+1][N+1];
			for (int i = 0; i <= LGN; i++)
			{
				Arrays.fill(parent[i], 0);
			}

			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= N; i++)
			{
				int p = Integer.parseInt(st.nextToken());
				if (p == 0) continue;
				adjList[p].add(i);
			}

			bfs(ROOT);
			make_parnet();

			// 문제풀이
			long answer = 0;

			int a, b;
			int lca;
			for (int i =1; i <= Q; i++)
			{
				st = new StringTokenizer(br.readLine());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());

				lca = lca(a, b);
			}
			
			bw.write("#" + t + " " + answer + "\n");
			bw.flush();
		}


	}

	private static int lca(int a, int b)
	{
		if (depth[a] > depth[b])
		{
			int tmp = a;
			a = b;
			b = tmp;
		}

		for (int i = LGN; i >= 0; i--)
		{
			if (depth[b] - depth[a] >= 1 << i)
			{
				b = parent[i][b];
			}
		}
		
		if (a == b) return a;

		for (int i = LGN; i >= 0; i--)
		{
			if (parent[i][a] != parent[i][b])
			{
				a = parent[i][a];
				b = parent[i][b];
			}
		}

		return parent[0][a];

	}

	static void make_parent()
	{
		for (int i = 1; i <= LGN; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				parent[i][j] = parent[i-1][parent[i-1][j]];
			}

		}
	}

	public static int distance(int a, int b)
	{
		int lca = lca(a, b);
		return depth[a] + depth[b] - (depth[lca] * 2);
	}

	private static void bfs(int start)
	{
		Queue<Integer> queue = new ArrayDeque<>();
		queue.add(start);
		depth[start] = 0;

		while(!queue.isEmpty())
		{
			int curr = queue.poll();
			for (Integer next : adjList[curr])
			{
				if (depth[next] > -1)
				{
					continue;
				}

				depth[next] = depth[curr] + 1;
				parent[0][next] = curr;
				queue.add(next);
			}		

		}

	}

}

