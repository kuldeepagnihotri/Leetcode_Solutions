class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto row : grid){
            for(auto num : row){
               arr.push_back(num);// convert a 2d array to 1d array
                }
        }
        int rem = arr[0] % x;// remainder of every element should be equal
        for(auto num: arr){
            if(num %x != rem) return -1;// if not equal return -1
        }
       // sort the array so that operations can be done smoothly
        sort(arr.begin(),arr.end());
        //find median
        int median = arr[arr.size()/2];
        // count operations so that will be returned
        int operations =0;

           for(auto num : arr){
            operations += abs(num - median) / x;
        }
        return operations;
    }
};