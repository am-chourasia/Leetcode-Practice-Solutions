class Solution {
    int N;
    int M;
    const vector<vector<int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    bool isValid(int i, int j){
        if(i < 0 or i >= N)
            return false;
        if(j < 0 or j >= M)
            return false;
        return true;
    }
    
    void floodFill(int i, int j, int newColor, vector<vector<int>>& image){
        int oldColor = image[i][j];
        image[i][j] = newColor;
        for(const auto& dir : direction){
            int newI = i + dir[0];
            int newJ = j + dir[1];
            if(isValid(newI, newJ) and image[newI][newJ] == oldColor)
                floodFill(newI, newJ, newColor, image);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        N = image.size();
        M = image[0].size();
        if(newColor != image[sr][sc])
            floodFill(sr, sc, newColor, image);
        return image;
    }
};