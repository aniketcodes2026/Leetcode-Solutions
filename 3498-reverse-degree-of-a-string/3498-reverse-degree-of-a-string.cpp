class Solution {
public:
    int reverseDegree(string s) {
        int totalReverseDegree = 0;
        
        for (int i = 0; i < s.length(); ++i) {
            // 'a' becomes 26, 'b' becomes 25, ..., 'z' becomes 1
            int reverseAlphabetPos = 'z' - s[i] + 1;
            int stringPos = i + 1; // 1-indexed position
            
            totalReverseDegree += reverseAlphabetPos * stringPos;
        }
        
        return totalReverseDegree;
    }
};