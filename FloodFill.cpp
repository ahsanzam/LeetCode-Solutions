// https://leetcode.com/problems/flood-fill/
// Jan 21, 2019

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(sr > image.size()) return image;
        if(sc > image[sr].size()) return image;
        if(image[sr][sc] == newColor) return image;
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        if(sr-1 > -1 && image[sr-1][sc] == oldColor) //flood fill up
            floodFill(image, sr-1, sc, newColor);
        if(sc-1 > -1 && image[sr][sc-1] == oldColor) //flood fill left
            floodFill(image, sr, sc-1, newColor);
        if(sc+1 < image[sr].size() && image[sr][sc+1] == oldColor) //flood fill right
            floodFill(image, sr, sc+1, newColor);
        if(sr+1 < image.size() && image[sr+1][sc] == oldColor) //flood fill down
            floodFill(image, sr+1, sc, newColor);
        return image;
    }
};