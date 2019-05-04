class Solution {
public:
    string solveEquation(string equation) {
        int coeff = 0, C = 0;
        string temp = "";
        char op = '?';
        for(char c : equation){
            if(c=='x'){
                if(op=='?') ++coeff;
                else if((op=='+')){
                    if(temp!="")
                        coeff += stoi(temp);
                    else ++coeff;
                }
                else if ((op ='-')){
                    if(temp!="") 
                        coeff -= stoi(temp);
                    else --coeff;
                }
                temp = "";
            }
            else if(c>='0'&&c<='9'){
                temp += c;
                if(op=='?') op = '+';
            }
            else{
                if(temp!=""){
                    if(op=='+') C += stoi(temp);
                    if(op=='-') C -= stoi(temp);
                }
                temp = "";
                if(c=='+') op = '+';
                else if(c=='-') op = '-';
                else{
                    C = -C;
                    coeff = -coeff;
                    op = '?';
                }
            }
        }
        if(temp!=""){
            if(op=='+') C += stoi(temp);
            if(op=='-') C -= stoi(temp);
        } 
        if(coeff) return "x=" + to_string(-C/coeff);
        else if(C) return "No solution";
        else return "Infinite solutions";
    }
};
