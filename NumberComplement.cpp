class Solution {
public:
    int findComplement(int num)
    {
        int res = 0;
        int i = 0;
        while(num)
        {
            if(num%2==0)
                res = res | 1<<i;
            i++;
            num /= 2;
        }
        return res;
    }
};