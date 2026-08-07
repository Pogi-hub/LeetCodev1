class Solution {
public:
    int reverse_pair_counter(vector<int> &nums,int lo,int mid,int hi){
        int j=mid+1,ans=0;
        for(int i=lo;i<=mid;i++){
            while(j<=hi && (long long)nums[i]>(long long)2*nums[j]) j++;
            ans+=(j-(mid+1));
        }
        return ans;
    }
    void merge(vector<int> &nums,int lo,int mid,int hi){
        vector<int> arr1,arr2;
        for(int i=lo;i<=mid;i++){
            arr1.push_back(nums[i]);
        }
        for(int i=mid+1;i<=hi;i++){
            arr2.push_back(nums[i]);
        }

        int n1=arr1.size(); int n2=arr2.size();
        int i=0,j=0,k=lo;

        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]) nums[k++]=arr1[i++];
            else nums[k++]=arr2[j++];
        }

        while(i<n1) nums[k++]=arr1[i++];
        while(j<n2) nums[k++]=arr2[j++];
    }
    int mergesort(vector<int> &nums ,int lo ,int hi){
        int cnt=0;
        if(lo>=hi) return cnt;
        int mid=lo+(hi-lo)/2;

        cnt+=mergesort(nums,lo,mid);
        cnt+=mergesort(nums,mid+1,hi);
        cnt+=reverse_pair_counter(nums,lo,mid,hi);

        merge(nums,lo,mid,hi);

        return cnt;
    }
    
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};