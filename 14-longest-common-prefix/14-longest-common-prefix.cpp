class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // 가장 길이가 작은 문자열 찾기
        string lower_str;
        int length = 200;
        string result;
        short check[200] = {0,};
        
        for(string s : strs){
            if(s.size() < length){
                length = s.size();
                lower_str = s;
            }
        }
        
        if(lower_str.size() == 0){return "";}
        
        for(int i = 0; i < lower_str.size(); ++i){
            string prefix = lower_str.substr(0,i+1);
            for(string s : strs){
                
                if(prefix == s.substr(0,i+1)){
                    ++check[i];
                    cout << "prefix : " << prefix << ", s.substr(0,i+1): " << s.substr(0,i+1) << endl;
                }
            }
        }
        int prefix_len = 0;
        for(int i = 0; i < lower_str.size(); ++i){
            
            if(check[i] == strs.size()){
                ++prefix_len;
            }
            cout << check[i];
        }
        cout << endl;
        
        return lower_str.substr(0,prefix_len);
    }
};