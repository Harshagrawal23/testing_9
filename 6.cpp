#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);


/*
 * Complete the 'largestSubgrid' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY grid
 *  2. INTEGER maxSum
 */

int dp[1551][1551];

int calculate(vector<vector<int>> grid, int maxsum)
{
    int n=grid.size();
    int sum=0, i1, j1, len1=1, len2=n, len, mid;

    bool flag=false;
    while(len1<=len2)
    {
        len=(len1+len2)/2 + (len1+len2)%2;
        cout<<len<<endl;
 
        flag=true;
        for(int i=0;i<=n-len;i++)
        {
            for(int j=0;j<=n-len;j++)
            {
                i1=i+len-1, j1=j+len-1;
                sum=dp[i1][j1];

                if(i>0)
                {
                    sum-=dp[i-1][j1];
                }
                if(j>0)
                {
                    sum-=dp[i1][j-1];
                }

                if(i>0 && j>0)
                sum-=grid[i][j];

                if(sum> maxsum)
                {
                    flag=false;
                    break;
                }

            }
            if(flag==false)
            break;
        }

        if(len1==len2)
        {
            if(flag)
            return len1;
        }

        if(flag==true)
        len1=len;
        else {
            len2=len-1;
        }
    }

    return 0;
    
}

int largestSubgrid(vector<vector<int>> grid, int maxSum) {
    memset(dp, 0, sizeof(dp));
    int n=grid.size();

    dp[0][0]=grid[0][0];

    for(int i=1;i<n;i++)
    {
        dp[0][i]=grid[0][i]+dp[0][i-1];
        dp[i][0]=grid[i][0] + dp[i-1][0];
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1]-dp[i-1][j-1]+grid[i][j];
        }
    }

    return calculate(grid, maxSum);

}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string grid_rows_temp;
    getline(cin, grid_rows_temp);

    int grid_rows = stoi(ltrim(rtrim(grid_rows_temp)));

    string grid_columns_temp;
    getline(cin, grid_columns_temp);

    int grid_columns = stoi(ltrim(rtrim(grid_columns_temp)));

    vector<vector<int>> grid(grid_rows);

    for (int i = 0; i < grid_rows; i++) {
        grid[i].resize(grid_columns);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < grid_columns; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    string maxSum_temp;
    getline(cin, maxSum_temp);

    int maxSum = stoi(ltrim(rtrim(maxSum_temp)));

    int result = largestSubgrid(grid, maxSum);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
