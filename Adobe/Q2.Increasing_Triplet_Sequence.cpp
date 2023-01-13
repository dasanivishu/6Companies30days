class Solution {
public:
    bool increasingTriplet(vector<int>& arr) {
        int n=arr.size();
       
        vector<int>min_from_front(n),max_from_back(n);
        //we will find min from front and max from back
        //then we will tranverse the array where element will be 
        //not equal to min from front[i] and ,max from back[i]
        //will be mid element of needed subsequence
         min_from_front[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            min_from_front[i]=min(min_from_front[i-1],arr[i]);
        }
        max_from_back[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        max_from_back[i]=max(max_from_back[i+1],arr[i]);
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=min_from_front[i]&&arr[i]!=max_from_back[i])
            return true;
        }
        return false;


    }
};
// time -O(N)
// Space -O(N)