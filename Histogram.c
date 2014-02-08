//  Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
//  find the area of largest rectangle in the histogram.
int largestRectangleArea(vector<int> &height) {
    height.push_back(0);
    stack<int> stackIndex;
    stackIndex.push(-1);
    int result = 0;
    for(int i = 0; i < height.size(); i++){
        while(stackIndex.size() > 1 && height[stackIndex.top()] >= height[i]){
            int area = height[stackIndex.top()];
            stackIndex.pop();
            area *= (i - stackIndex.top() - 1);
            if(area > result) result = area;
        }
        stackIndex.push(i);
    }
    height.pop_back();
    return result;
}