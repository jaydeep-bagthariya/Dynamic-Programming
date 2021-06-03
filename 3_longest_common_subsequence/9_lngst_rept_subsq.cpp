//Longest Repeated Subsequence

// Given a string, print the longest repeating subsequence such that the two subsequence don’t have same 
// string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the 
// same index in the original string.

// Examples: 

// Input: str = "aabb"
// Output: "ab"  

// Input: str = "aab"
// Output: "a"
// The two subsequence are 'a'(first) and 'a' 
// (second). Note that 'b' cannot be considered 
// as part of subsequence as it would be at same
// index in both.

//in this program we print only size of the subsequence;
//to print this watch in gfg;
#include<bits/stdc++.h>
using namespace std;

int longestRepatingSub(string s1, int n)
{
    int dp[n+1][n+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(s1[i-1] == s1[j-1] && i!=j)
                dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    return dp[n][n];

}

int main()
{
    string s1 = "AABEBCDD";
    int n = s1.length();
    // tabulation method;
    cout <<longestRepatingSub(s1,n);
    return 0;
}