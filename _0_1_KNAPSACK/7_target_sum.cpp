//   ****** 494. Target Sum ******

// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000


//when you will see this problem carefully this problem is nothing but
//this is previous problem COUNT NUMBER OF SUBSET WITH GIVEN DIFFERENCE 


#include<bits/stdc++.h>
using namespace std;

//in this problem we have to take care of 0's with few changes
//explanation 
// Cnt is for '0's in the array. If we have n number of zeroes then 
// we need to multiply out result of count of subsets with a sum to 2^n.  
// And we need to not consider this while calculating in bottom-up manner, 
// hence the case " if(nums[i-1]==0) { dp[i][j] = dp[i-1][j] } ".
// For example: If we have 2(cnt=2) zeroes in the example array for which 
// we calculate count of subset with a sum then there are 4(2^cnt) ways 
// that is either selecting first zero, second selecting second 0 present in array, 
// third not selecting both, fourth selecting both.
class Solution {
public:
    // void helper(vector<int>& nums, int target, int realTarget, int n,int& count)
    // {
    //     if(target==realTarget && n==0) count++;
    //     if(n==0) return;        
    //     helper(nums,target-nums[n-1],realTarget,n-1,count);
    //     helper(nums,target+nums[n-1],realTarget,n-1,count);
    // }
    int Count(vector<int>& nums,int target, int n, int realTarget)
    {
        int dp[n+1][realTarget+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<realTarget+1;j++)
            {
                if(j==0) dp[i][j] = 1;
                else if(i==0 && j!=0) dp[i][j] = 0;
                else if(nums[i-1]==0)
                    dp[i][j] = dp[i-1][j];
                else if(nums[i-1]<=j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][realTarget];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0,cnt = 0;
        for(int i : nums){
            sum += i;
            if(i==0) cnt++;
        }
        if(target>sum) return 0;
        if((target + sum) % 2 != 0 ) return 0;
        int realTarget = (sum-target)/2;
        int ans = Count(nums,target,n,realTarget);
        return pow(2,cnt)*ans;
    }
};