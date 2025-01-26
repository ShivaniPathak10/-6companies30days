vector<int> ans(2); // To store the repeated and missing numbers
        int n = arr.size();
        int i = 0;
    
        while (i < n) {
            if (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            } else {
                i++;
            }
        }
    
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                ans[0] = arr[i];    
                ans[1] = i + 1;    
            }
        }
    
        return ans;