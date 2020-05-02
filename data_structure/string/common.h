#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <limits>
#include <stack>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};