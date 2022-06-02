using namespace std;

class Solution {
public:
    int reverse(int x) {
        // pop digit
        int tmp = x;
        int ret = 0;
        
        while(tmp != 0){
        
            int pop = tmp % 10;
            tmp = tmp / 10;
            if(ret > INT_MAX /10 ) return 0;
            if(ret < INT_MIN / 10) return 0;
            ret = ret * 10 + pop;
        }
        
        return ret;
    }
};