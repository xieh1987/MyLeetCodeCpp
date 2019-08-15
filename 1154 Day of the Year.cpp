class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        vector<int> dayofmonth = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int res = dayofmonth[month-1] + day;
        return isLeapYear(year)&&month>2 ? res + 1 : res;
    }
    
    bool isLeapYear(int year) {
        return (year%400==0) || (year%100 && year%4==0);
    }
};
