#include <map>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> ret(2);
            
        for(int i = 0; i < nums.size(); ++i){
            m.insert(pair<int, int>(nums[i], i));
        }
        
        for(int i = 0; i < nums.size(); ++i){
            int b = target - nums[i];
            map<int, int>::iterator it = m.find(b);
            
            if(it != m.end() && it->second != i){
                ret[0] = i;
                ret[1] = it->second;
                break;
            }
            
            
        }
        
        return ret;
    }
};