class Solution {
public:
    bool check(int num)
    {
        int s = 2;
        int e = num/2;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(mid == num/mid && num%mid == 0)
                return true;
            else if(mid > num/mid)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return false;
    }

    bool isPerfectSquare(int num)
    {
        if(num == 1)
            return true;

        return check(num);
    }
};