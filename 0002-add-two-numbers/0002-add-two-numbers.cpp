/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return nullptr;
        vector<int> res;
        while (l1) {
            res.push_back(l1->val);
            l1 = l1->next;
        }
        if (!l2)
            return nullptr;
        vector<int> res2;
        while (l2) {
            res2.push_back(l2->val);
            l2 = l2->next;
        }
        if (res.empty())
            return nullptr;
        reverse(res.begin(), res.end());
        reverse(res2.begin(), res2.end());
        vector<int> doubled;
        int carry = 0;
        int rem;
        for (int i = res.size() - 1, j = res2.size() - 1; i >= 0 || j >= 0;) {
            if (i < 0) {
                rem = (res2[j] + carry) % 10;
                carry = (res2[j] + carry) / 10;
                j--;
            } else if (j < 0) {
                rem = (res[i] + carry) % 10;
                carry = (res[i] + carry) / 10;
                i--;
            } else {
                rem = (res[i] + res2[j] + carry) % 10;
                carry = (res[i] + res2[j] + carry) / 10;
                j--;
                i--;
            }
            doubled.push_back(rem);
        }
        while (carry) {
            int rem = carry % 10;
            carry /= 10;
            doubled.push_back(rem);
        }
        res = doubled;
        ListNode* ans = nullptr;
        ListNode* temp = nullptr;
        for (int i = 0; i < res.size(); i++) {
            if (!ans) {
                temp = new ListNode(res[i]);
                ans = temp;
            } else {
                temp->next = new ListNode(res[i]);
                temp = temp->next;
            }
        }
        return ans;
    }
};