class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != nullptr) {
                ans.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        sort(ans.begin(), ans.end());

        ListNode* root = nullptr;
        ListNode* tail = nullptr;

        for (int i = 0; i < ans.size(); i++) {
            ListNode* newNode = new ListNode(ans[i]);
            if (root == nullptr) {
                root = newNode;
                tail = root;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        return root;
    }
};
