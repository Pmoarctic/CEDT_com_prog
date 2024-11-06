#ifndef __STUDENT_H_
#define __STUDENT_H_

#include<queue>

template <typename KeyT,
          typename MappedT,
          typename CompareT >
CP::map_bst<KeyT,MappedT,CompareT> CP::map_bst<KeyT,MappedT,CompareT>::split(KeyT val) {
  //your code here
  CP::map_bst<KeyT,MappedT,CompareT> result;

  //search node
  std::queue<node*> q,q2;
  q.push(mRoot);
  node* cur;
  while(!q.empty())
  {
    cur = q.front();
    q.pop();

    
    while(cur && cur->data.first < val)
    {
      if (cur->right != NULL)
      {
        cur = cur->right;
      }
      else
      {
        break;
      }
    }

    
    if(cur!=NULL && cur->data.first >= val)result[cur->data.first] = cur->data.second;
    if(cur->right!=NULL)q2.push(cur->right);
    
    if(cur->left != NULL)
    {
      q.push(cur->left);
      cur->left->parent = cur->parent;
      cur->parent->right = cur->left;
    }
  }

  while(!q2.empty())
  {
    node* nw = q2.front();
    std::cout << nw->data.first << "\n";
    q2.pop();
    result[nw->data.first] = nw->data.second;
    if(nw->left!=NULL)q2.push(nw->left);
    if(nw->right!=NULL)q2.push(nw->right);
  }
  


  return result;
}

#endif
