vector<int> rightSideView(TreeNode* root) {
        vector<int>view;
        if(root == NULL)
        {
            return view;
        }
        view.push_back(root->val);
        queue<TreeNode*>pq;
        vector<int>lr;
        pq.push(root);
        pq.push(NULL);
        while(!pq.empty())
        {
            TreeNode *top = pq.front();
            pq.pop();
            if(top != NULL)
            {
                if(top->left)
                {
                    pq.push(top->left);
                    lr.push_back(top->left->val);
                }
                if(top->right)
                {
                    pq.push(top->right);
                    lr.push_back(top->right->val);
                }
            }
            else
            {
                if(lr.size())
                {
                    view.push_back(lr[lr.size() - 1]);
                }
                lr.clear();
                pq.push(NULL);
                if(pq.front() == NULL)
                {
                    break;
                }
                continue;
            }
        }
        return view;
    }