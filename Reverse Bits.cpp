class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        queue<int> digits;
        for(int i=0;i<32;++i) {
            digits.push(n%2);
            n /= 2;
        }
        uint32_t res = 0;
        while (!digits.empty()) {
            res = res * 2 + digits.front();
            digits.pop();
        }
        return res;
    }
};
