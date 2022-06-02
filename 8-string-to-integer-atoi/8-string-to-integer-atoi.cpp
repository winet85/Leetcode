using namespace std;
class Solution {
public:
    bool isDisit(char c){
        if(c >= '0' && c <= '9') return true;
        return false;
    }
    bool isWhiteSpace(char c){
        if(c == ' ') return true;
        return false;
    }
    bool isPositive(char c){
        if(c == '-') return false;
        return true;
    }
    int myAtoi(string s) {
        
        int ret = 0;
        int state = 1;
        string tmp;
        
        // 공백 제거
        s.erase(0, s.find_first_not_of(' '));
        cout << s << endl;
        
        string::iterator it = s.begin();
        
        
        if(*it == '-'){
            state = -1;
            ++it;
        }else if(*it == '+'){
            state = 1;
            ++it;
        }
        

        while(it < s.end() && isDisit(*it)){
            int digit = int(*it - '0');

            if((ret > INT_MAX/10) || (ret == INT_MAX/10 && digit > INT_MAX %10)){
              return state == -1 ? INT_MIN : INT_MAX;  
            } 
            ret = ret*10 + digit;
            
            
            ++it;
        }
        
        cout << ret * state<< ", " <<state << endl;
        return ret * state;
    }
};