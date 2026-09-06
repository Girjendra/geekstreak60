/*
Given an array arr[] of integers, calculate the sum of bitwise AND for all pairs of elements such that the first index is less than the second index.
*/
#include<iostream>
#include <vector>
using namespace std;

// TC : O(n^2) SC: O(1)
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++)
                ans += arr[i] & arr[j];
        }
        
        return ans;
    }
};


// TC : O(n*32) SC: O(n*32)
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
        
        vector<vector<int>> m(n, vector<int>(32, 0));
        for(int i = 0; i < 32; i++) {
            for(int j = 0; j < n; j++) {
                if(arr[j] >> i & 1)
                    m[j][i] = 1;
            }
        } 
        
        
        long long ans = 0;
        for(int j = 0; j < 32; j++) {
            int cnt = 0;
            for(int i = 0; i < n; i++)
                cnt += m[i][j];

            ans += (1LL << j) * cnt * (cnt - 1) / 2;
        }
        
        return ans;
    }
};



// TC = O(n) SC = O(32) = O(1)
class Solution {
  public:
    long long pairAndSum(vector<int> &arr) {
        int n = arr.size();
    
        vector<int> m(32, 0);
        for(int i = 0; i < 32; i++)
            for(int j = 0; j < n; j++)
                if(arr[j] >> i & 1)
                    m[i]++;
        
        
        long long ans = 0;
        for(int j = 0; j < 32; j++)
            ans += (1LL << j) * m[j] * (m[j] - 1) / 2;
        
        return ans;
    }
};