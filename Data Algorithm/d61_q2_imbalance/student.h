// Your code here

size_t recur(node* cur, size_t &res, node* &res_node)
{
    if(cur == NULL)return 0;

    size_t ls = 1 + recur(cur->left,res,res_node);
    size_t rs = 1 + recur(cur->right,res,res_node);

    if(abs(ls-rs)>res)
    {
        res = abs(ls-rs);
        res_node = cur;
    }
    else if(abs(ls-rs)==res)
    {
        if(cur->data.first < res_node->data.first)
        {
            res_node = cur;
        }
    }
    
    return (ls<rs)?rs:ls;
}

KeyT getValueOfMostImbalanceNode() {

    node* res_node = mRoot;
    size_t res=0;
    recur(mRoot,res,res_node);

    return res_node->data.first;
}
