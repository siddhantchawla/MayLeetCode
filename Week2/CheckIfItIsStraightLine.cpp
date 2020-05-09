class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        if(coordinates.size() == 2)
            return true;

        int x1_2 = abs(coordinates[0][0] - coordinates[1][0]);
        int y1_2 = abs(coordinates[0][1] - coordinates[1][1]);

        for(int i = 2;i<coordinates.size();i++)
        {
            int x2_3 = abs(coordinates[1][0] - coordinates[i][0]);
            int y2_3 = abs(coordinates[1][1] - coordinates[i][1]);

            if(x1_2 == 0)
            {
                if(x2_3 != 0)
                    return false;
            }
            else if(y1_2 == 0)
            {
                if(y2_3 != 0)
                    return false;
            }
            else
            {
                if(x1_2 * y2_3 != x2_3 * y1_2)
                    return false;
            }
        }
        return true;
    }
};