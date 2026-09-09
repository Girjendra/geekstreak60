/*
Given a number n, find a number in the range from 1 to n such that its digit sum is maximum. If there are multiple such numbers, return the largest of them.
*/
#include<iostream>
#include <cmath>
using namespace std;


// TC : O((log n)^2)  SC: O(1)
class Solution {
  public:
    int digitSum(int x) {
        int sum = 0;
    
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
    
        return sum;
    }
    
    int findMax(int n) {
        int ans = n;
        int maxSum = digitSum(n);
    
        int x = n;
        int b = 1;
    
        while (x > 0) {
            int cur = (x - 1) * b + (b - 1);
            int sum = digitSum(cur);
    
            if (sum > maxSum || (sum == maxSum && cur > ans)) {
                maxSum = sum;
                ans = cur;
            }
            
            x /= 10;
            b *= 10;
        }
    
        return ans;
    }
};
