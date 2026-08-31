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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i = 0;
        vector<int> pts;
        int prev = head->val;
        while(head && head->next)
        {
            if(prev > head->val && head->val < head->next->val)
            {
                pts.push_back(i);
            }
            else if(prev < head->val && head->val > head->next->val)
            {
                pts.push_back(i);
            }
            i++;
            prev = head->val;
            head = head->next;
        }
        if(pts.size() < 2)
            return {-1, -1};
        int mini = INT_MAX;
        for(int i = 1; i < pts.size();i++)
        {
            mini = min(mini, abs(pts[i] - pts[i-1]));
        }
        return {mini, pts[pts.size() - 1] - pts[0]};
    }
};