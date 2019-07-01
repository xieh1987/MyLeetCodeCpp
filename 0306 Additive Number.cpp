//Use stol instead of stoi to avoid integer overflow
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if(len<3) return false;
        for(int i=1;i<len-1;++i) {
            string s1 = num.substr(0, i);
            if(s1[0]=='0'&&s1.size()>1) continue;
            long n1 = stol(s1);
            for(int j=i+1;j<len;++j) {
                string s2 = num.substr(i, j-i);
                if(s2[0]=='0'&&s2.size()>1) continue;
                long n2 = stol(s2);
                int pos = j;
                long sum = n1 + n2;
                string s = to_string(sum);
                while(pos+s.size()<=len) {
                    string s3 = num.substr(pos, s.size());
                    long n3 = stol(s3);
                    if(n3!=sum) break;
                    else {
                        pos += s.size();
                        if(pos==len) return true;
                        n1 = n2;
                        n2 = n3;
                        sum = n1 + n2;
                        s = to_string(sum);
                    }
                }
                n1 = stol(s1);
            }
        }
        return false;
    }
};

/*Follow up: use string addition to deal with large numbers
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int len = num.size();
        if(len<3) return false;
        for(int i=1;i<len-1;++i) {
            string s1 = num.substr(0, i);
            if(s1[0]=='0'&&s1.size()>1) continue;
            for(int j=i+1;j<len;++j) {
                string s2 = num.substr(i, j-i);
                if(s2[0]=='0'&&s2.size()>1) continue;
                int pos = j;
                string s = AddString(s1, s2);
                while(pos+s.size()<=len) {
                    string s3 = num.substr(pos, s.size());
                    if(s3!=s) break;
                    else {
                        pos += s.size();
                        if(pos==len) return true;
                        s1 = s2;
                        s2 = s;
                        s = AddString(s1, s2);
                    }
                }
                s1 = num.substr(0, i);
            }
        }
        return false;
    }
    
    string AddString(string& num1, string& num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        if(len1==0) return num2;
        if(len2==0) return num1;
        
        int i = len1-1, j = len2-1, carry = 0;
        string res;
        while(i>=0||j>=0){
            if(i>=0) carry += num1[i--] - '0';
            if(j>=0) carry += num2[j--] - '0';
            res = to_string(carry % 10) + res;;
            carry /= 10;
        }
        if(carry) res = "1" + res;
        return res;
    }
};
*/
