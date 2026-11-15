class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sz = digits.size() - 1;
        int carry = 1; 
        
        while (sz >= 0) {
            int sum = digits[sz] + carry;
            digits[sz] = sum % 10;
            carry = sum / 10;
            
            if (carry == 0) {
                return digits;
            }
            
            sz--;
        }

        if (carry > 0) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};