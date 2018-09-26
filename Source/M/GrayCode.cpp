#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int max(int x, int y){
        return y > x ? y : x;
    }
    int min(int x, int y){
        return x < y ? x : y;
    }
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int *rowMax = new int[row];
        int *colMax = new int[col];
        memset(rowMax, 0, sizeof(int)*row);
        memset(colMax, 0, sizeof(int)*col);

        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                if (grid[i][j] > rowMax[i]){
                    rowMax[i] = grid[i][j];
                }
                if (grid[i][j] > colMax[j]){
                    colMax[j] = grid[i][j];
                }
            }
        }

        int needAdd = 0;
        for (int i = 0; i < grid.size(); ++i){
            for (int j = 0; j < grid[0].size(); ++j){
                needAdd += max(0, min(rowMax[i], colMax[j]) - grid[i][j]);
            }
        }

        return needAdd;
    }
};

int main(){
    Solution s = Solution();

    int x[4][4] = { { 3, 0, 8, 4 },
              { 2, 4, 5, 7 },
              { 9, 2, 6, 3 },
              { 0, 3, 1, 0 } };

    vector<int> v[4];
    for(int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            v[i].push_back(x[i][j]);
        }
    }
    vector<vector<int>> input;
    for (int i = 0; i < 4; ++i){
        input.push_back(v[i]);
    }

    cout << s.maxIncreaseKeepingSkyline(input);
    return 0;
} 