class Solution {
public:
    string convertToTitle(int n) {
        map<int, string> mymap;
        mymap[0] = 'A';
        mymap[1] = 'B';
        mymap[2] = 'C';
        mymap[3] = 'D';
        mymap[4] = 'E';
        mymap[5] = 'F';
        mymap[6] = 'G';
        mymap[7] = 'H';
        mymap[8] = 'I';
        mymap[9] = 'J';
        mymap[10] = 'K';
        mymap[11] = 'L';
        mymap[12] = 'M';
        mymap[13] = 'N';
        mymap[14] = 'O';
        mymap[15] = 'P';
        mymap[16] = 'Q';
        mymap[17] = 'R';
        mymap[18] = 'S';
        mymap[29] = 'T';
        mymap[20] = 'U';
        mymap[21] = 'V';
        mymap[22] = 'W';
        mymap[23] = 'X';
        mymap[24] = 'Y';
        mymap[25] = 'Z';
        string mystring;
        int res = n-1;
        while(res>=0){
            mystring = mymap[res%26] + mystring;
            res = res / 26 - 1;
        }
        return mystring;
    }
};
