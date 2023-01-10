// You are playing the Bulls and Cows game with your friend.

// You write down a secret number and ask your friend to guess what the number is. When your friend makes a guess, you provide a hint with the following info:

// The number of "bulls", which are digits in the guess that are in the correct position.
// The number of "cows", which are digits in the guess that are in your secret number but are located in the wrong position. Specifically, the non-bull digits in the guess that could be rearranged such that they become bulls.
// Given the secret number secret and your friend's guess guess, return the hint for your friend's guess.

// The hint should be formatted as "xAyB", where x is the number of bulls and y is the number of cows. Note that both secret and guess may contain duplicate digits.

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull=0;
        int cow=0;
        vector<int>arr(10,0);
        int n=secret.length();
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
            bull++;
            int m=secret[i]-'0';
            arr[m]++;
        }
        for(int i=0;i<n;i++)
        {
            int m=guess[i]-'0';
            if(arr[m]>0)
            arr[m]--;
        }
        int sum=0;
        for(int i=0;i<10;i++)
        sum+=arr[i];//it will contain how many digits are different
        cow=n-sum-bull;//bull cannot be cow as they are in correct place
        string ans=to_string(bull)+"A"+to_string(cow)+"B";
        return ans;
    }
};
