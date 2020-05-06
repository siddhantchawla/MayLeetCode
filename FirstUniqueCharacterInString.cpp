class Solution {
public:
    int firstUniqChar(string s)
    {
        string a = s;
        sort(a.begin(),a.end());
        map<char,int> mp;

        for(int i=0;i<a.length();i++)
        {
            mp[a[i]-'a']++;
        }

        for(int i=0; i<s.length();i++)
        {
            if(mp[s[i]-'a']==1)
                return i;
        }
        return -1;
    }
};