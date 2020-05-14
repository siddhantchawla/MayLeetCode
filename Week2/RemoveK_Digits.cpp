class Solution {
public:
    string removeKdigits(string num, int k)
    {
        if(num.size() == k)
            return "0";

        stack<char> s;

        s.push(num[0]);

        for(int i = 1;i<num.size();i++)
        {
            if(s.top() > num[i])
            {
                while(!s.empty() && s.top() > num[i] && k > 0)
                {
                    s.pop();
                    k--;
                }
            }
            s.push(num[i]);
        }

        while(k--)
        {
            s.pop();
        }

        stack<char> t;
        while(!s.empty())
        {
            t.push(s.top());
            s.pop();
        }

        while(t.top() == '0' && t.size() != 1)
            t.pop();

        num = "";
        while(!t.empty())
        {
            num = num + t.top() ;
            t.pop();
        }
        return num;
    }
};