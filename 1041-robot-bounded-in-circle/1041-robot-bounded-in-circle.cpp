class Solution {
public:
    bool isRobotBounded(string s) {
       vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}}; //make sure to maintian this order  NORTH WEST SOUTH EAST 
        int x=0, y=0, itr=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'L')
            {
                itr = (itr+1)%4;
            }
            else if(s[i] == 'R')
            {
                itr = (itr+3)%4;
            }
            else
            {
                x += dir[itr][0];
                y += dir[itr][1];
            }
        }
        //// If the robot perform 1 rotation, it means  "i != 0" then it will gauranteed perform a circle & after certain rotation it will come back to the origin.
        // But if "i is  0" , it mean's robot is moving straight, hence there is no cycle. It will never come back to origin. 
       
            return (x==0 and y==0) || itr!=0;
        }
};
        
        
        
        
        
        