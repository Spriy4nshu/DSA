class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int num = 0;
        int sign = 1;
        bool flag = false;

        while(i < n){
            if(s[i] == ' '){
                if(flag) break;  // if we've seen a number/sign, break
                else{
                    i++;
                    continue;
                };
            }
            else if(s[i] == '-'){
                if(flag) break;  // if we've seen a number/sign, break
                else{
                    sign = -1;
                    flag = true;
                }
            }
            else if(s[i] == '+'){
                if(flag) break;  // if we've seen a number/sign, break
                else{
                    sign = 1;
                    flag = true;
                }
            }
            else if(isdigit(s[i])){
                flag = true;
                // Check overflow before multiplication
                if (sign == 1) {
                    if (num > INT_MAX/10 || (num == INT_MAX/10 && (s[i]-'0') >= INT_MAX%10)) {
                        return INT_MAX;
                    }
                } else {
                    if (num > INT_MAX/10 || (num == INT_MAX/10 && (s[i]-'0' >= -(INT_MIN%10)))) {
                        return INT_MIN;
                    }
                }
                num = num * 10 + (s[i] - '0');
            }
            else break;  // any other character, break
            i++;
        }
        
        return num * sign;
    }
};