class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int index1 = m - 1, index2 = n - 1, endIndex = m + n - 1;
        
        while(index1 > -1 && index2 > -1) {
            
            if(nums1[index1] >= nums2[index2]) {
                
                nums1[endIndex] = nums1[index1];
                
                --index1;
            }
            else {
                nums1[endIndex] = nums2[index2];
                --index2;
            }
            --endIndex;
        }
        
        while(index1 > -1) {
            
            nums1[endIndex] = nums1[index1];
            --index1;
            --endIndex;
        }
        
        while(index2 > -1) {
            
            nums1[endIndex] = nums2[index2];
            --index2;
            --endIndex;
        }
    }
};