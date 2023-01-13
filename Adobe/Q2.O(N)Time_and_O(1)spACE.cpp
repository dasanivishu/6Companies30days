class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int low=INT_MAX;
        int mid=INT_MAX;
        //we just have to assign each time i to low and mid respectively
        //and if next number is greater than low and mid then return true
        for(auto i:nums)
        {
            if(i<=low)
            low=i;
            else if(i<=mid)//i>low
            mid=i;
            else 
            return true;
            
            
        }
        return false;
    }
};