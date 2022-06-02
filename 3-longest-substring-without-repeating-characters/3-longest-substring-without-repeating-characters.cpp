#include <vector>
class Solution {
public:
//     int lengthOfLongestSubstring(string s) {
//         int ret = 0;
//         int n = s.length();
        
//         for(int i = 0; i < n; ++i){
//             for(int j = i; j < n; ++j){
                
                
//                 if(checkRepetition(s, i, j)){
//                     ret = max(ret, j - i + 1);
//                 }
//             }
//         }
            
//         return ret;
//     }
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int n = s.length();
        int right = 0;
        int left = 0;
        vector<int> chars(128);
        
        while(right < n){
            char r = s[right];
            chars[r]++;
            
            while(chars[r] > 1){
                char l = s[left];
                chars[l]--;
                left++;
            }
            
            ret = max(ret, right - left + 1);
            // cout << left << ", " << right << " ," << ret << endl;
            right++;
            
        }
        
      
        
        return ret;
    }
     bool isRepetition(string &t, int s, int e){
        vector<int> chars(128);
        
        for(int i = s; i <= e; ++i){
            char c = t[i];

            chars[c]++;
            if(chars[c] > 1){
                return true;
            }
        }
        
        return false;
    }
//     int lengthOfLongestSubstring(string s) {
//         int ret = 0;
//         int n = s.length();
//         int right = 0;
//         int left = 0;
//         vector<int> chars(128);
        
//         while(right < n){
            
//             while(isRepetition(s, left, right)){
//                 left++;
//             }
            
//             ret = max(ret, right - left + 1);
//             // cout << left << ", " << right << " ," << ret << endl;
//             right++;
            
//         }
        
      
        
//         return ret;
//     }

};