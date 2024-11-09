// class Solution {
// public:
//     string intToRoman(int num) {
//         vector<int> base = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
//         vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
//         string res = "";
//         // using subtraction method
//         for(int i = 0; i < base.size(); i++){
//             while(num >= base[i]){
//                 res.append(roman[i]);
//                 num -= base[i];
//             }
//         }
//         return res;
//     }
// };

// using division method
class Solution {
public:
    string intToRoman(int num) {
        vector<int> base = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        // using subtraction method
        for(int i = 0; i < base.size(); i++){
            if(num >= base[i]){
                int recur = num / base[i];
                while(recur > 0){
                    res.append(roman[i]);
                    recur--;
                }

                num = num % base[i];
            }
        }
        return res;
    }
};