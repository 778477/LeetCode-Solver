
//Accepted	36 ms	cpp

class Solution {
private:
    vector<int> _Qcol;
    int _ans;
    int _n;
public:
    int totalNQueens(int n) {
        _n = n;
        _ans = 0;
        _Qcol = vector<int>(n,0);
        dfs(0);
        return _ans;
    }
    void dfs(int step)
    {
        if(step == _n)
        {
            _ans++;
            return ;
        }
        for(int i=0;i<_n;i++)
        {
            if(judge(step,i))
            {
                _Qcol[step] = i;
                dfs(step+1);
                _Qcol[step] = 0;
                
            }
        }
    }
    
    bool judge(const int x,const int y)
    {
        for(int i=0;i<x;i++)
        {
            if(_Qcol[i] == y) return false;
            if(_Qcol[i] - y == i - x) return false;
            if(y - _Qcol[i] == i - x) return false;
        }
        return true;
    }
};

