class Solution {
public:
    int reverse_pair_counter(vector<int> &arr1,vector<int> &arr2,int n1,int n2){
        int j=0,ans=0;
        for(int i=0;i<n1;i++){
            while(j<n2 && (long long)arr1[i]>(long long)2*arr2[j]) j++;
            ans+=j;
        }
        return ans;
    }
    void merge(vector<int> &nums,int lo,int mid,int hi,int &count){
        vector<int> arr1,arr2;
        for(int i=lo;i<=mid;i++){
            arr1.push_back(nums[i]);
        }
        for(int i=mid+1;i<=hi;i++){
            arr2.push_back(nums[i]);
        }

        int n1=arr1.size(); int n2=arr2.size();
        int i=0,j=0,k=lo;

        count+=reverse_pair_counter(arr1,arr2,n1,n2);

        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]) nums[k++]=arr1[i++];
            else nums[k++]=arr2[j++];
        }

        while(i<n1) nums[k++]=arr1[i++];
        while(j<n2) nums[k++]=arr2[j++];
    }
    void mergesort(vector<int> &nums ,int lo ,int hi,int &count){
        if(lo>=hi) return;

        int mid=lo+(hi-lo)/2;

        mergesort(nums,lo,mid,count);
        mergesort(nums,mid+1,hi,count);

        merge(nums,lo,mid,hi,count);
    }
    
    int reversePairs(vector<int>& nums) {
        int count=0;
        mergesort(nums,0,nums.size()-1,count);

        return count;
    }
};