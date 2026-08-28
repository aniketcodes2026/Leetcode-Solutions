class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carry = 0;
        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            // Add digit from a
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }

            // Add digit from b
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // Current binary digit
            ans += char((sum % 2) + '0');

            // Carry for next position
            carry = sum / 2;
        }

        // We calculated from right to left,
        // so reverse the answer.
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
