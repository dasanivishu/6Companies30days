// Question:Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] represents an axis-aligned rectangle.
//   The bottom-left point of the rectangle is (xi, yi) and the top-right point of it is (ai, bi).

// Return true if all the rectangles together form an exact cover of a rectangular region.
//  Link-> https://leetcode.com/problems/course-schedule/description/




class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>m;
        //In this problem we will count the number of edges after joining all
        //rectangles if atlast no of edges==4 then perfect rectangle
        //as when we will draw rectangle we can see that bottom left and top left
        //will concide so they can cancel extra inner points
        //similarly top right and bottom right 
        //so we will add count of one and subtract count of another in each case 
        for(auto P:rectangles)
        {
            m[{P[0],P[1]}]++;//bottom left
            m[{P[2],P[3]}]++;//top right
            m[{P[0],P[3]}]--;//top left
            m[{P[2],P[1]}]--;//bottom right

        }
        int sum=0;
        for(auto it:m)
        {
            sum+=abs(it.second);//abs is used as edges which will not come inner will not cancel each other 
            //but can come in negative due to -- in two case will also count as edge

        }
        if(sum==4)
        return true;
        return false;
    }
};
