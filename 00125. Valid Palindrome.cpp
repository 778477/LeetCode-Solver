
//	Accepted	60 ms	cpp
class Solution {
public:
    bool isPalindrome(string s) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        string after;
        bool flag = false;
        after.clear();
        int len = s.length();
        for(int i=0;i<len;i++)
            if(s[i]>='0'&&s[i]<='9') after+=s[i];
            else if(s[i]>='a'&&s[i]<='z') after+=s[i];
            else if(s[i]>='A'&&s[i]<='Z') after+=(s[i]-'A'+'a');
            else if(s[i]!=' ') flag = true;
        if(!after.size() && !flag) return true;
        len = after.length();
        int p = 0,q = len-1;
        while(p <= q)
        {
            if(after[p] == after[q]) p++,q--;
            else return false;
        }
        return true;
    }
};
