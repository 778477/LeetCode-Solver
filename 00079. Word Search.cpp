
//Accepted	96 ms	cpp
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        n = board.size();
        m = board[0].size();
        if(n*m < word.length()) return false;
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    vis[i][j] = true;
                    if(word.length() == 1 || dfs(board,word,i,j,1)) return true;
                    vis[i][j] = false;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char> > &board, string word,int x,int y,int step)
    {
        if(step == word.length()) return true;
        int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<4;i++)
        {
            int xx = x+dir[i][0];
            int yy = y+dir[i][1];
            if(xx>-1&&xx<n&&yy>-1&&yy<m&&!vis[xx][yy]&&board[xx][yy]==word[step])
            {
                vis[xx][yy] = true;
                if(dfs(board,word,xx,yy,step+1)) return true;
                vis[xx][yy] = false;
            }
        }
        return false;
    }
private:
    bool vis[100][100];
    int n,m;
};
