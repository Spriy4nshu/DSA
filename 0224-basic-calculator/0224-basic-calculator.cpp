class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int num = 0;
        int res = 0;
        int sign = 1;
        stack<pair<int, int>> st;

        for(char c: s){
            if(c == ' ') continue;
            else if(isdigit(c)){
                num = 10 * num + (c - '0');
            }
            else if(c == '+'){
                res += sign * num;
                num = 0;
                sign = 1;
            }
            else if(c == '-'){
                res += sign * num;
                num = 0;
                sign = -1;
            }
            else if(c == '('){
                st.push({res, sign});
                res = 0;
                sign = 1;
            }
            else if(c == ')'){
                res += num * sign;
                res *= st.top().second;
                res += st.top().first;
                st.pop();
                num = 0;
                sign = 1;
            }
        }
        res += num * sign;
        return res;
    }
};