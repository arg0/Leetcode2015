

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int> > &matrix) {
    vector<int> result;
    if(matrix.empty() || matrix[0].empty()) return result;
    int m = matrix.size(); int n = matrix[0].size();
    int top = 0; int right = n-1; int bottom = m-1; int left = 0;
    int r = 0; int c = 0;
    while(1) {
      int size = result.size();
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r][c++]);
      }
      top++;c--;r++;
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r++][c]);
      }
      right--;r--;c--;
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r][c--]);
      }
      bottom--;c++;r--;
      while(c <= right && c >= left && r <= bottom && r >= top) {
        result.push_back(matrix[r--][c]);
      }
      left++;r++;c++;
      if(size == result.size())break;
    }
    return result;
  }
};
