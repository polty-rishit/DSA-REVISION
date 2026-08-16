from typing import List
def trappingRainWater(nums:List[int])->int:
    n=len(nums)
    pre=[0]*n
    pre[0]=nums[0]
    suf=[0]*n
    suf[n-1]=nums[n-1]
    for i in range(1,n):pre[i]=max(pre[i-1],nums[i])
    for i in range(n-2,-1,-1):suf[i]=max(suf[i+1],nums[i])
    t=0
    for i in range(0,n):
        maxi=min(pre[i],suf[i])
        if maxi>nums[i]:t+=maxi-nums[i]
    return t

nums=[3, 0, 1, 0, 4, 0, 2]
ans=trappingRainWater(nums)
print(ans,end=" ")
