/*
Given a 2D grid mat[][] of size n × m consisting of characters and a string word, find all starting positions where the word occurs in the grid.

The word can be formed from any cell by moving in any of the 8 directions (2 horizontal, 2 vertical, and 4 diagonal) in a straight line without changing direction.
Each cell can be used at most once per occurrence.
Return all unique starting coordinates in lexicographically smallest order.
*/
#include<iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


// TC : O(n * m * l)  SC : O(n * m)
class Solution {
  public:
    bool isword(int i, int j, vector<vector<char>>& ma, string& word) {
        int n = ma.size();
        int m = ma[0].size();
        int ws = word.size();
        
        // up
        int ind = 0;
        int r = i, c = j;
        while(r >= 0 && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            r--;
            ind++;
        }
        if(ind == ws)
            return true;
        
        // first diagonal   
        ind = 0;
        r = i, c = j;
        while(r >= 0 && c < m && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            r--;
            c++;
            ind++;
        }
        if(ind == ws)
            return true;
    
        // right
        ind = 0;
        r = i, c = j;
        while(c < m && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            c++;
            ind++;
        }
        if(ind == ws)
            return true;
        
        // second diagonal
        ind = 0;
        r = i, c = j;
        while(r < n && c < m && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            r++;
            c++;
            ind++;
        }
        if(ind == ws)
            return true;    
        
        // down
        ind = 0;
        r = i, c = j;
        while(r < n && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            r++;
            ind++;
        }
        if(ind == ws)
            return true;
            
        // third diagonal 
        ind = 0;
        r = i, c = j;
        while(r < n && c >= 0 && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            r++;
            c--;
            ind++;
        }
        if(ind == ws)
            return true;    
            
        // left
        ind = 0;
        r = i, c = j;
        while(c >= 0 && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            c--;
            ind++;
        }
        if(ind == ws)
            return true;    
            
        // fourth diagonal
        ind = 0;
        r = i, c = j;
        while(r >= 0&& c >= 0 && ind < ws) {
            if(ma[r][c] != word[ind])
                break;
                
            r--;
            c--;
            ind++;
        }
        
        if(ind == ws)
            return true;
        else
            return false;
    }
    
    vector<vector<int>> searchWord(vector<vector<char>> &mat,
                        string &word) {
        int n = mat.size();
        int m = mat[0].size();
        
        set<pair<int, int>> s;
        for(int i = 0; i< n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == word[0] && isword(i, j, mat, word))
                    s.insert({i, j});
            }
        }
        
        vector<vector<int>> ans;
        for(auto it : s) {
            ans.push_back({it.first, it.second});
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};