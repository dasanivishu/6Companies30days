class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        //just using sorting propery
        //as we go from right to left at ith pos element is minimum
        //we go from left to right at ith pos element is maximum
        int n=arr.size();
        int right_pos=0;
        int max_x=arr[0];
        for(int i=1;i<n;i++)
        {
            if(arr[i]<max_x)
            right_pos=i;
            max_x=max(max_x,arr[i]);
        }
        int min_x=arr[n-1];
        int left_pos=0;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>min_x)
            left_pos=i;
            min_x=min(min_x,arr[i]);
        }
        if(left_pos==0&&right_pos==0)return 0;
        return right_pos-left_pos+1;
    }
};
