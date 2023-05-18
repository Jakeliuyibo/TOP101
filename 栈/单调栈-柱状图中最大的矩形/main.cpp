class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int res = 0;
        stack<int> st;

        /* 为了保证堆栈清空，末尾添加辅助数 */
        heights.insert(heights.begin(), 0);
        heights.push_back(0);

        int n = heights.size();
        for(int idx=0; idx<n; idx++)
        {
            while(!st.empty() && heights[idx] < heights[st.top()])
            {
                int cur         = st.top();
                st.pop();
                int curHeight   = heights[cur];

                int left  = st.empty() ? 0 : st.top();
                int right = idx;
                int curWeight   = right - left - 1;

                res = max(res, curWeight*curHeight);
            }
            st.push(idx);
        }

        /* 还原数组     */
        heights.erase(heights.begin(), heights.begin()+1);
        heights.pop_back();

        return res;
    }
};
