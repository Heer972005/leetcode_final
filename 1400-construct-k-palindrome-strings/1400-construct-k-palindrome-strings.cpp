// class Solution {
// public:
//     bool canConstruct(string s, int k) {
//         int n=s.length();
//         if(n<k)
//             return false;
//         //int freq=0;
//         unsigned freq=0;
//         //left shift
//         //The shift ensures that every letter has its own dedicated slot (bit) inside the integer.
//         //Let's assume freq starts at 0 (0000).First character 'a':Mask for 'a' is 1 << 0 \(\rightarrow \) 0001freq ^= 0001 \(\rightarrow \) freq becomes 0001 (Bit 0 is ON because 'a' appeared 1 time)Second character 'b':Mask for 'b' is 1 << 1 \(\rightarrow \) 0010freq ^= 0010 \(\rightarrow \) freq becomes 0011 (Bits for both 'a' and 'b' are ON)Third character 'a':Mask for 'a' is 1 << 0 \(\rightarrow \) 0001freq ^= 0001 \(\rightarrow \) 0011 ^ 0001 = 0010Result: Bit 0 (for 'a') toggled back to 0 because 'a' now has an even count (2). Bit 1 (for 'b') stays 1 because 'b' has an odd count (1).
//         for(char c:s){
//             freq=feq^(1<<(c-'a'));
//         }
//         int odd_count = 0;
//         while (freq > 0) {
//             freq &= (freq - 1); // Clears the lowest set bit
//             odd_count++;
//         }

//         return odd_count <= k;
//     }
// };

class Solution {
public:
    bool canConstruct(std::string& s, int k) {
        // Base case: If string length is less than k, we can't make k non-empty strings
        if (s.size() < k) return false;

        // Traditional frequency array to store counts for 'a' through 'z'
        vector<int> counts(26, 0);
        for (char c : s) {
            counts[c - 'a']++;
        }

        // Count how many characters appear an odd number of times
        int odd_count = 0;
        for (int count : counts) {
            if (count % 2 != 0) {
                odd_count++;
            }
        }

        // Total odd characters cannot exceed the number of available palindrome slots
        return odd_count <= k;
    }
};