class Solution {
public:
    int countCheck(vector<vector<int>> matrix , int mid) {
        int n = matrix.size();
        int row = n-1 , col = 0 , count = 0;
        while(row >= 0 && col < n) {
            if(matrix[row][col] <= mid) {
                count += (row + 1);
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //brute approch---->
        // priority_queue<int> pq;
        // int n = matrix.size() , m = matrix[0].size();

        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         pq.push(matrix[i][j]);
        //         if(pq.size() > k) {
        //             pq.pop();
        //         }
        //     }
        // }
        // return pq.top();

        // With the help of Binary Serarch

        // int n = matrix.size();

        // int st = matrix[0][0] , end = matrix[n-1][n-1];

        // while(st <= end) {
        //     int mid = st + (end - st) /2;
        //     int count = countCheck(matrix,mid);
        //     if(count < k) {
        //         st = mid + 1;
        //     } else {
        //         end = mid - 1;
        //     }
        // }
        // return st;

        // using Heap whit sorted Property

        vector<pair<int, pair<int, int>>> v;

        for(int i=0; i<matrix.size(); i++)
        v.push_back(make_pair(matrix[i][0], make_pair(i, 0)));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int,int>>>> p(v.begin(), v.end());

        pair<int, pair<int, int>> element;
        while(k--) {
            element = p.top();
            p.pop();
            int i = element.second.first;
            int j = element.second.second;

            if(j+1 < matrix.size())
            p.push(make_pair(matrix[i][j+1], make_pair(i, j+1)));
        }

        return element.first;
    }
};