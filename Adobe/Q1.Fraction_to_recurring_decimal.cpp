class Solution {
public:
    //we can use map to find out the position of repeating remainder in fraction
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if(numerator==0)
        return "0";
        string ans;
        unordered_map<int64_t,int64_t>remainder_pos;//it will store the remainder position
        if(numerator<0^denominator<0)ans+="-";
        numerator=abs(numerator);
        denominator=abs(denominator);
        ans+=to_string(numerator/denominator);//floor value stored in string
        int64_t remainder=numerator%denominator;
        if(remainder==0)
        return ans;
        ans+='.';
        //while loop to check first repeation of reminder and store positon of
        //remainder to insert bracket when needed
        int64_t pos=ans.size();
        while(remainder&&remainder_pos.find(remainder)==remainder_pos.end())
        {
            remainder_pos[remainder]=pos++;
            ans+='0'+remainder*10/denominator;
            remainder=remainder*10%denominator;
        }
        if(remainder)//because of repeating character it came out of loop
        {
            ans+=')';
            ans.insert(ans.begin()+remainder_pos[remainder],'(');

        }
        return ans;
        



    }
};
