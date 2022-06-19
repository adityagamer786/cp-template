int cycle_count(vector<int> &q, int n){
    // assumes 1 based indexing edge indexing
    for(int i = 0; i < n; i++){
        q[i]--; // remove for 0 based edge indexing
    }
    vector<int> used(n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(used[i] == 1) continue;
        int j = i;
        while(used[j] == 0){
            used[j] = 1;
            j = q[j];
        }
        ans++;
    }
    return ans;
    // number of swaps = n-ans
}