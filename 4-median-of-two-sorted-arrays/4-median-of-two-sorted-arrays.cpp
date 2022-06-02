class Solution {
public:
    // void mergedSort(vector<int> &v, )
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 머지
        double ret = 0.0f;
        vector<int> m(nums1.size() + nums2.size());
        int n = m.size();
        
        // merge sort
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), m.begin());
        
        // 중간값 계산
        int mid = n/2;
        if(n%2 == 0){
            ret = ((double)(m[mid - 1] + m[mid])) / 2;
        }else{
            ret = m[mid];
        }
        
        return ret;
    }
};