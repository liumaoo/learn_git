1.有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() == 0 && t.size() == 0) return true;
        if (s.size() != t.size()) return false;

        map<char, int> sDict, tDict;
        for (int i=0; i<s.size(); i++) {
            sDict[s[i]]++;
        }

        for (int i=0; i<t.size(); i++) {
            tDict[t[i]]++;
        }

        if (sDict.size() != tDict.size()) return false;
        for (int i=0; i<sDict.size(); i++) {
            if (sDict[i] != tDict[i]) return false;
        }
        return true;
    }
};
2.两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;
        vector<int> b(2,-1);
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0)
            {
                b[0]=a[target-nums[i]];
                b[1]=i;
                break;
            }
            a[nums[i]]=i;
        }
        return b;
    }
};

3.N叉树前序遍历
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> ve;
        if (!root) return ve;
       
       stack<Node*> st;
       st.push(root);
       while(!st.empty()) {
           Node *node = st.top();
           st.pop();

            if (node) {
                ve.emplace_back(node->val);
            }else {
                continue;
            }

            if (!node->children.empty()) {
                int size = node->children.size();
                for (int i=size-1; i>=0; i--) { 
                    Node *n = node->children[i];
                    if (n) st.push(n);
                }
            }
       }
        return ve;
    }
};
4.字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs) {
            string key = str;
            sort(key.begin(), key.end());
            mp[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

5.二叉树的中序遍历
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root)
        {
            stack<TreeNode *> st;
            st.push(root);
            while(!st.empty())
            {
                TreeNode *node = st.top();
                st.pop();
                if(node)
                {
                    if(node->right)
                        st.push(node->right);
                    st.push(node);
                    st.push(nullptr);
                    if(node->left)
                        st.push(node->left);
                }
                else
                {
                    res.push_back(st.top()->val);
                    st.pop();
                }
            }
        }
        return res;
    }
};
6.二叉树的前序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root)
        {
            stack<TreeNode *> st;
            st.push(root);
            while(!st.empty())
            {
                TreeNode *node = st.top();
                st.pop();
                if(node)
                {
                    res.push_back(node->val);
                    if(node->right)
                        st.push(node->right);
                    if(node->left)
                        st.push(node->left);
                }
            }
        }
        return res;
    }
};
7.N叉树层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        vector<vector<int>> result;
        deque<Node*> worker;
        worker.push_back(root);
        while (worker.size()) {
            vector<int> sub;
            int loops = worker.size();
            while (loops--) {
                root = worker.front(), worker.pop_front();
                for (auto &i : root->children)
                    worker.push_back(i);
                sub.push_back(root->val);
            }
            result.push_back(sub);
        }
        return result;
    }
};
8.丑数
class Solution {
public:
    int nthUglyNumber(int n) {
        int a = 0, b = 0, c = 0;
        int dp[n];
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            int n2 = dp[a] * 2, n3 = dp[b] * 3, n5 = dp[c] * 5;
            dp[i] = min(min(n2, n3), n5);
            if(dp[i] == n2) a++;
            if(dp[i] == n3) b++;
            if(dp[i] == n5) c++;
        }
        return dp[n - 1];
    }
};