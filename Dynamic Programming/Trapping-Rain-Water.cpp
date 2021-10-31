int trap(vector<int>& arr) {
        int n = arr.size();
        int maxl[n];
        maxl[0] = arr[0];
        int ml = arr[0];
        
        for(int i = 1; i<n; i++){
            if(arr[i]>ml){
                maxl[i] = arr[i];
                ml = arr[i];
            }
            else{
                maxl[i] = ml;
            }
        }
        
        
        int maxr[n];
        maxr[n-1] = arr[n-1];
        int mr = maxr[n-1];
        
        for(int i = n-2; i>=0; i--){
            if(arr[i]> mr){
                maxr[i] = arr[i];
                mr = arr[i];
            }
            else{
                maxr[i] = mr;
            }
        }
        int  sm = 0;
        for(int j = 0; j<n; j++){
            int var = min(maxr[j],maxl[j])-arr[j];
            sm+=var;
        }
        
        return sm;
    }
