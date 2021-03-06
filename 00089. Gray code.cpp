
/*
[Gray Code](https://leetcode.com/problems/gray-code/)



这里是[Gray code](https://en.wikipedia.org/wiki/Gray_code)维基百科的定义

https://upload.wikimedia.org/wikipedia/commons/thumb/c/c1/Binary-reflected_Gray_code_construction.svg/250px-Binary-reflected_Gray_code_construction.svg.png

其实解题思路，看上面那张图就够了。模拟实现就ok了。
 
 我是用string来模拟，主要是方便插入前面的0和1.最后再 处理一下 `Binary String to Integer`
 
 
 > http://stackoverflow.com/questions/23596988/binary-string-to-integer-with-atoi
*/


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        
        if(n >= 1){
            vector<string> tmp;
            string str("0");
            string str1("1");
            tmp.push_back(str);
            tmp.push_back(str1);
            
            for(int i=1;i<n;i++){
                vector<string> res = tmp;
                reverse(res.begin(), res.end());
                
                int m = (int)tmp.size();
                for(int i=0;i<m;i++){
                    tmp[i].insert(0, "0");
                }
                
                for(int i=0;i<m;i++){
                    res[i].insert(0, "1");
                    tmp.push_back(res[i]);
                }
            }
            
            ans.clear();
            for_each(tmp.begin(), tmp.end(), [&](const string str){
                ans.push_back(stoi(str.c_str(),nullptr,2));
            });
        }
        
        return ans;
    }
};
