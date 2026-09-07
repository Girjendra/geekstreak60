/*
Given an array arr[] of size n, partition its elements into a strictly increasing subsequence and a strictly decreasing subsequence.

Each element can belong to at most one of these subsequences, and some elements may remain unused.

Determine the minimum number of elements that cannot be included in either subsequence.
*/
#include<iostream>
#include <vector>
#include <climits>
using namespace std;


// TC : O(3^n) SC : O(n)
class Solution {
  public:
    int solve(int i, vector<int>& arr, int previ, int prevd) {
        if(i == arr.size())
            return 0;
            
        int takei = 0;
        if(previ < arr[i])
            takei = 1 + solve(i+1, arr, arr[i], prevd);
        
        int taked = 0;
        if(prevd > arr[i])
            taked = 1 + solve(i+1, arr, previ, arr[i]);
            
        int skip = solve(i+1, arr, previ, prevd);
            
        return max(max(takei, taked), skip);
    }
    
    int minCount(vector<int>& arr) {
        int n = arr.size();
        int used = solve(0, arr, INT_MIN, INT_MAX);
        
        return n - used;
    }
};



// TC : O(n^3) SC : O(n^3)
class Solution {
  public:
    int solve(int i, vector<int>& arr, int previi, int prevdi,
                vector<vector<vector<int>>>& dp) {
        if(i == arr.size())
            return 0;
            
        if(dp[i][previi+1][prevdi+1] != -1)
            return dp[i][previi+1][prevdi+1];
            
        int takei = 0;
        if(previi == -1 || arr[previi] < arr[i])
            takei = 1 + solve(i+1, arr, i, prevdi, dp);
        
        int taked = 0;
        if(prevdi == -1 || arr[prevdi] > arr[i])
            taked = 1 + solve(i+1, arr, previi, i, dp);
            
        int skip = solve(i+1, arr, previi, prevdi, dp);
            
        return dp[i][previi+1][prevdi+1] = max(max(takei, taked), skip);
    }
    
    int minCount(vector<int>& arr) {
        int n = arr.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>
                                        (n+1, vector<int>(n+1, -1)));
        int used = solve(0, arr, -1, -1, dp);
        
        return n - used;
    }
};