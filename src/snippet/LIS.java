import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class LIS
{
	static int N;
	public static int[] lis;


	public static void main(String[] args) throws Exception
	{
		//System.setIn(new FileInputStream("sample_input.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		int tc = Integer.parseInt(br.readLine());

		for (int t = 1; t <= tc; t++)
		{
			N = Integer.parseInt(br.readLine());
		
			// 전처리
			int[] input = new int[N];
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++)
			{
				input[i] = Integer.parseInt(st.nextToken());
			}

			lis = new int[N];

			long answer = 0;

			bw.write("#" + t + " " + answer + "\n");
			bw.flush();
		}
	}

	private static int lis(int[] arr)
	{
		lis[0] = arr[0];
		int idx = 0;

		for (int i = 1; i < N; i++)
		{
			if (lis[idx] < arr[i])
			{
				idx++;
				lis[idx] = arr[i];
			}
			else
			{
				int tmp = Arrays.binarySearch(lis, 0, idx, arr[i]);
				if (tmp < 0)
					tmp = (tmp * -1) - 1;
				lis[tmp] = arr[i];

			}
		}

		return idx+1;
	}

}
