/*The following method works but will cause stack overflow if z is large
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(z>x+y) return false;
        vector<bool> res(x+y+1, false);
        vector<bool> visited(x+y+1, false);
        if(x>y) swap(x, y);
        res[0] = true;
        helper(x, y, z, res, visited);
        return res[z];
    }
    
    void helper(int& x, int& y, int z, vector<bool>& res, vector<bool>& visited) {
        if(z==x||z==y) res[z] = true;
        if(visited[z]||res[z]) return;
        visited[z] = true;
        helper(x, y, abs(x-z), res, visited);
        helper(x, y, abs(y-z), res, visited);
        res[z] = res[abs(y-z)] || res[abs(x-z)];
        return;
    }
};
*/

//Use greatest common divisor (gcd)
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z==0 || (x + y >= z && z % gcd(x, y) == 0);
    }
    
    int gcd(int a, int b) {
        return b==0 ? a : gcd(b, a%b);
    }
};
