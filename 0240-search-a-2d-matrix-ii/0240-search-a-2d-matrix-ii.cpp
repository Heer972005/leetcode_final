class Solution {
public:
    bool helper(vector<vector<int>>& matrix,
                int sr, int sc,
                int er, int ec,
                int target) {

        // Base Case
        if (sr > er || sc > ec)
            return false;

        // Find middle cell
        int midr = (sr + er) / 2;
        int midc = (sc + ec) / 2;

        int value = matrix[midr][midc];

        // Target found
        if (value == target)
            return true;

        // Middle value is smaller than target
        if (value < target) {

            return helper(matrix,
                          midr + 1, sc,
                          er, ec,
                          target)

                ||

                   helper(matrix,
                          sr, midc + 1,
                          midr, ec,
                          target);
        }

        // Middle value is greater than target
        return helper(matrix,
                      sr, sc,
                      er, midc - 1,
                      target)

            ||

               helper(matrix,
                      sr, midc,
                      midr - 1, ec,
                      target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty())
            return false;

        return helper(matrix,
                      0, 0,
                      matrix.size() - 1,
                      matrix[0].size() - 1,
                      target);
    }
};