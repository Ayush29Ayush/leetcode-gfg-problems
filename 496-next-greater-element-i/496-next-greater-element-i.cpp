// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans(nums1.size());
        
//         for(int i = 0; i < nums1.size(); i++){
//             for(int j = 0; j < nums2.size(); j++){
//                 if(nums1[i]==nums2[j])
//                     {
//                         for(int k = j; k<nums2.size(); k++)
//                         {
//                             if(nums2[k] > nums2[j])
//                             {
//                                 ans.push_back(nums2[k]);
//                                 break;
//                             }
//                         }
//                         ans.push_back(-1);
//                         break;
//                     }
//                 }
//             }
//         return ans;
//     }
// };
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    int m= -1;
                    for(int k=j; k<nums2.size(); k++){
                        if(nums2[k]>nums2[j]){
                            m=nums2[k];
                            break;
                        }  
                    }
                    ans.push_back(m);
                }
            }
        }
        return ans;
    }
};