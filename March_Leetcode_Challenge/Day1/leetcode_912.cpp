class Solution {
public:

    void merge(vector<int>&nums, int l , int mid, int r)
    {   int ln = mid-l+1;
        int rn = r-mid;
        vector<int>left(ln);
        vector<int>right(rn);
        int s = 0;
        for(int i = l;i<=mid;i++)
        {
            left[s++] = nums[i];
        }
        s = 0;
        for(int i = mid+1; i<=r; i++)
        {
            right[s++] = nums[i];
        }
        int ls = 0 , rs = 0, ms = l;
        while(ls<ln && rs<rn)
        {
            if(left[ls]<right[rs])
            {
                nums[ms++] = left[ls++];
            }
            else
            {
              nums[ms++] = right[rs++];  
            }
        }
        while(ls<ln)
        {
          nums[ms++] = left[ls++];  
        }
        while(rs<rn)
        {
           nums[ms++] = right[rs++];   
        }
    }

    void mergeSort(vector<int>&nums, int l, int r)
    {
      if(l<r)
      {
          int mid = (l+r)/2;
          mergeSort(nums,l,mid);
          mergeSort(nums,mid+1,r);
          merge(nums,l,mid,r);
      }
    }
    vector<int> sortArray(vector<int>& nums) {
      int n = nums.size()-1;
      mergeSort(nums,0,n);
      return nums;  
    }
};
