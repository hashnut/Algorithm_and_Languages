#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int r_dir[4] = {-1, 1, 0, 0};
int c_dir[4] = {0, 0, -1, 1};

int light(vector<vector<int>> &nodes, vector<vector<vector <int>>> &maps, int o_r, int o_c, int o_d, int rows, int cols)
{
    int r = o_r, c = o_c, d = o_d;
    int nth = 1;
    
    while (true)
    {
        if (maps[r][c][d] == 1)
            break;
        
        maps[r][c][d] = nth;
        
        // out of range case handling
        if (d == 0 && r == 0)
            r = rows-1;
        else if (d == 1 && r == rows-1)
            r = 0;
        else if (d == 2 && c == 0)
            c = cols-1;
        else if (d == 3 && c == cols-1)
            c = 0;
        else
        {
            r += r_dir[d]; 
            c += c_dir[d];
        }
        
        // direction update
        // straight -> do nothing
        if (d == 0)
        {
            if (nodes[r][c] == 1) d = 2;
            else if (nodes[r][c] == 2) d = 3;
        }
        else if (d == 1)
        {
            if (nodes[r][c] == 1) d = 3;
            else if (nodes[r][c] == 2) d = 2;
        }
        else if (d == 2)
        {
            if (nodes[r][c] == 1) d = 1;
            else if (nodes[r][c] == 2) d = 0;
        }
        else if (d == 3)
        {
            if (nodes[r][c] == 1) d = 0;
            else if (nodes[r][c] == 2) d = 1;
        }
        
        nth++;
    }    

    return nth-1;

}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    int rows = grid.size();
    int cols = grid[0].length();
    
    vector<vector<int>> nodes(rows, vector<int>(cols, 0));
    vector<vector<vector <int>>> maps(rows, vector<vector<int>>(cols, vector<int>(4, 0)));
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == 'S')
                nodes[i][j] = 0;
            else if (grid[i][j] == 'L')
                nodes[i][j] = 1;
            else nodes[i][j] = 2;
        }
        
    }
    
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                if (maps[i][j][d] != 0)
                    continue;
                
                answer.push_back(light(nodes, maps, i, j, d, rows, cols));
            }
            
        }
        
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
