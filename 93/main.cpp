#include <iostream>
#include <string>
#include <climits>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>

using namespace std;
struct Node {
    int start, val, end;
};

int largestRectangleArea(vector<int> &heights) {
    stack<Node> stack_Node;
    int ret = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (stack_Node.empty()) {
            stack_Node.push({0, heights[i]});
        } else {
            Node *top = &stack_Node.top();
            if ((*top).val <= heights[i]) {
                stack_Node.push({i, heights[i]});
            } else {
                int start = 0;
                while (!stack_Node.empty() && (*top).val > heights[i]) {
                    int end = i;
                    (*top).end = end;
                    start = ((*top).start);
                    stack_Node.pop();
                    ret = max(ret, (*top).val * ((*top).end - (*top).start));
                    if (!stack_Node.empty()) {
                        top = &stack_Node.top();
                        (*top).end = end;
                    }
                }
                stack_Node.push({start, heights[i]});
            }
        }
    }
    Node *top = &stack_Node.top();
    int end = heights.size();
    while (!stack_Node.empty()) {
        ret = max(ret, (*top).val * (end - (*top).start));
        stack_Node.pop();
        top = &stack_Node.top();
    }
    return ret;
}

int main() {
    vector<int> heights = {4,2,0,3,2,5};
    largestRectangleArea(heights);
    return 0;

}