class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        vp = nums1 + nums2
        vp.sort()
        
        if len(vp) % 2 == 1:
          return vp[len(vp) // 2] * 1.0
        else:
          return (vp[len(vp) // 2 - 1] + vp[(len(vp) // 2)]) * 0.5
