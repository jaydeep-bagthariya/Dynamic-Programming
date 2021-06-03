//Minimum number of deletions and insertions to transform one string into another

// Given two strings ‘str1’ and ‘str2’ of size m and n respectively. The task is to remove/delete and 
// insert the minimum number of characters from/in str1 to transform it into str2. It could be possible 
// that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

// Example 1: 

// Input : 
// str1 = "heap", str2 = "pea" 
// Output : 
// Minimum Deletion = 2 and
// Minimum Insertion = 1
// Explanation:
// p and h deleted from heap
// Then, p is inserted at the beginning
// One thing to note, though p was required yet
// it was removed/deleted first from its position and
// then it is inserted to some other position.
// Thus, p contributes one to the deletion_count
// and one to the insertion_count.

#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int n, int m)
{
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0) dp[i][j] = 0;
            else if(s1[i-1]==s2[j-1]) 
                dp[i][j] = 1+dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    return dp[n][m];
}
int main()
{
    string s1 = "heap";
    string s2 = "pea";
    int n = s1.length();
    int m = s2.length();
    // tabulation method;
    int ans = lcs(s1,s2,n,m);
    cout << "Minimum number of insertion is : " << (m-ans) <<endl;
    cout << "Minimum number of deletion is : " << (n-ans);
    return 0;
}