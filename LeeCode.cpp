消除有序数组的重复
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2)
            return nums.size();
        vector<int>::iterator it = unique(nums.begin(), nums.end());
        return (it - nums.begin());
    }
};
旋转数组
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
        std::reverse(nums.begin(), nums.end() - k % nums.size());
        std::reverse(nums.end() - k % nums.size(), nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};
合并有序链表
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
 ListNode *preHead = new ListNode(-1);
        ListNode *node = preHead;
        while(l1 && l2)
        {
            if(l1->val <= l2->val)
            {
                node->next = l1;
                l1 = l1->next;
            }
            else
            {
                node->next = l2;
                l2 = l2->next;
            }
            node = node->next;
        }
        node->next = l1 == nullptr ? l2 : l1;
        return preHead->next;
    }

};
合并有序数组
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n < 1)
            return;

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0)
        {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        if(j >= 0)
            std::copy(nums2.begin(), nums2.begin() + j + 1, nums1.begin());
    }

};
两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
移动0
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       if(nums.size() > 1)
        {
            for(int i = 0, j= 0; i < nums.size(); i++)
            {
                if(nums[i] != 0)
                    swap(nums[i], nums[j++]);                             
            }
        }
    }

};
加一
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            digits[i]++;
            if(digits[i] != 10)
                return digits;
            else
                digits[i] = 0;                                          
        }
        if(digits[0] == 0)
        {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;

    }
};
设计双端循环队列
class MyCircularDeque {
    int size;
    vector<int> values;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        size = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(values.size() == size)
            return false;
        values.insert(values.begin(), value);
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(values.size() == size)
            return false;
        values.push_back(value);
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(values.size() > 0)
        {
            values.erase(values.begin());
            return true;
        }
        return false;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(values.size() > 0)
        {
            values.pop_back();
            return true;
        }
        return false;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(values.size() > 0)
            return values.front();
        return -1;
    }
        /** Get the last item from the deque. */
    int getRear() {
        if(values.size() > 0)
            return values.back();
        return -1;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return values.empty();
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return values.size() == size;
    }

};
接雨水
class Solution {
public:
    int trap(vector<int>& height) {
              if(height.size() < 3)
            return 0;
        int res = 0, left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        while(left < right)
        {
            if(height[left] < height[right])
            {
                height[left] >= leftMax ? leftMax = height[left] : res += leftMax - height[left];
                left++;
            }
            else
            {
                height[right] >= rightMax ? rightMax = height[right] : res += rightMax - height[right];
                right--;
            }
        }
        return res;
        
    }
};
