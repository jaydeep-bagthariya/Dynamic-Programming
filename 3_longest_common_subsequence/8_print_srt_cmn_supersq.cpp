//Printing Shortest Common Supersequence

// Given two strings X and Y, print the shortest string that has both X and Y as subsequences. 
// If multiple shortest supersequence exists, print any one of them.

// Examples:

// Input: X = "AGGTAB",  Y = "GXTXAYB"
// Output: "AGXGTXAYB" OR "AGGXTXAYB" 
// OR Any string that represents shortest
// supersequence of X and Y

// Input: X = "HELLO",  Y = "GEEK"
// Output: "GEHEKLLO" OR "GHEEKLLO"
// OR Any string that represents shortest 
// supersequence of X and Y

#include<bits/stdc++.h>
using namespace std;

string printScs(string s1, string s2, int n , int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    string ans = "";
    int i=n, j=m;
    while(i>0 && j>0)
    {
        if(s1[i-1] == s2[j-1]){
            ans.push_back(s1[i-1]);
            i--,j--;
        }
        else {
            if(dp[i-1][j]>dp[i][j-1]) {
                ans.push_back(s1[i-1]);
                i--;
            }
            else {
                ans.push_back(s2[j-1]);
                j--;
            }
        }
    }
    while(i>0){
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}


int main()
{
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int n = s1.length();
    int m = s2.length();
    // tabulation method;
    string scs = printScs(s1,s2,n,m);
    cout << scs;
    return 0;
}