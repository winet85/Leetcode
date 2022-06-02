#include <map>

map<const char, int> change = {
    {'I', 1}
    ,{'V', 5}
    ,{'X', 10}
    ,{'L', 50}
    ,{'C', 100}
    ,{'D', 500}
    ,{'M', 1000}
};
class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        string tmp(s);
        tmp.append("*");
        // cout << s.size() << ", " << tmp.size() << endl;
        int k = 0;
        for(int i = 0; i < tmp.size()-1; ){
            int value = 0;
            char cur = tmp.at(i);
            char next = tmp.at(i+1);
            map<const char, int>::iterator it_cur = change.find(cur);
            if((cur == 'I' && (next == 'V' || next == 'X'))
                ||(cur == 'X' && (next == 'L' || next == 'C'))
                ||(cur == 'C' && (next == 'D' || next == 'M')))
            {
                
                map<const char, int>::iterator it_next = change.find(next);
                // cout << it_cur->second << ", " << it_next->second << endl;
                value = it_next->second - it_cur->second;
                i = i + 2;
            }else if(cur == '*'){
                break;
            }else{
                value = it_cur->second;
                ++i;
            }
            
            cout << value << endl;
            ret += value;
        }
        
        // for(const char c : s){
        //     map<const char, int>::iterator it = change.find(c);
        //     if(it != change.end()){
        //         ret += it->second;
        //     }
        // }
        
        return ret;
    }
};