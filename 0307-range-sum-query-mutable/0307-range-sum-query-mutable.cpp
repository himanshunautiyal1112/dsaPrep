class NumArray {
public:
    vector<int>tree;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(4*n);
        buildTree(0, 0, n-1, nums);
    }

    void buildTree(int node, int start, int end, vector<int> &nums) {
        if(start == end) {
            tree[node] = nums[start];
            return;
        }

        int mid = start + (end - start)/2;
        buildTree(2*node+1, start, mid, nums);
        buildTree(2*node+2, mid+1, end, nums);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    void updateTree(int node, int start, int end, int index, int val) {
        if(start == end){
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) /2;

        if(index <= mid) {
            updateTree(2*node+1, start, mid, index, val);
        } else {
            updateTree(2*node+2, mid+1, end, index, val);
        }

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }
    
    void update(int index, int val) {
        updateTree(0, 0, n-1, index, val);
    }

    int rangeQuery(int node, int start, int end, int left, int right) {
        if(end < left || right < start) {
            return 0;
        }
        if(left <= start && end <= right) {
            return tree[node];
        }
        int mid = start + (end-start)/2;
        int leftSum = rangeQuery(2*node+1, start, mid, left, right);
        int rightSum = rangeQuery(2*node+2, mid+1, end, left, right);

        return leftSum + rightSum;
    }
    
    int sumRange(int left, int right) {
        return rangeQuery(0, 0, n-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */