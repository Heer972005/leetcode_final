class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return reverse(n, 0, 31);
    }

    uint32_t reverse(uint32_t n, int start, int end) {

        // Base case
        if (start == end) {
            return (n >> (31 - start)) & 1;
        }

        int mid = start + (end - start) / 2;

        uint32_t left = reverse(n, start, mid);
        uint32_t right = reverse(n, mid + 1, end);

        return (right << (end - mid)) | left;
    }
};