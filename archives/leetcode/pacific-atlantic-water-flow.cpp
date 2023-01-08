class Solution {
public:
    void markIt(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean, int lastHeight) {
        if(r < 0 || r >= heights.size() || c < 0 || c >= heights[r].size()) return;

        int currHeight = heights[r][c];

        if(ocean[r][c] == true || currHeight < lastHeight) return;

        ocean[r][c] = true;
        markIt(r - 1, c, heights, ocean, currHeight);
        markIt(r, c - 1, heights, ocean, currHeight);
        markIt(r + 1, c, heights, ocean, currHeight);
        markIt(r, c + 1, heights, ocean, currHeight);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> pacific(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic(r, vector<bool>(c, false));

        for(int i=0; i<c; i++) {
            markIt(0, i, heights, pacific, 0);
            markIt(r - 1, i, heights, atlantic, 0);
        }

        for(int i=0; i<r; i++) {
            markIt(i, 0, heights, pacific, 0);
            markIt(i, c - 1, heights, atlantic, 0);
        }

        vector<vector<int>> result;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }
        return result;
    }
};