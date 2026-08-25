class Solution {
public:
    int strStr(string haystack, string needle) {

        for (int i = 0; i + needle.length() <= haystack.length(); i++) {

            if (haystack.substr(i, needle.length()) == needle) {
                return i;
            }
        }
        return -1;
    }
};