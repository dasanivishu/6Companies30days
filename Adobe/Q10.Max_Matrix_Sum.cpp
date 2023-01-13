class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int minimum_element=INT_MAX;
        int count_negative=0;
        for(auto it:matrix)
        {
            for(auto element:it)
            {
                if(element<0)
                count_negative++;
                sum+=abs(element);//absolute value sum
                minimum_element=min(minimum_element,abs(element));
            }
            
        }
        if(count_negative%2==0)//then negative will cancel
        return sum;
        else//min_element will be left as negative
        return sum-2*minimum_element;

    }
};
//Intitution-
// if count of negative numbers is even then we can cancel each other and abs sum of matrix will be ans 
// if count of negative numbers is odd then our aim is to make min element negative 
// which is left out after cancelling others ,so ans =absolute value sum-2*minimum_element
