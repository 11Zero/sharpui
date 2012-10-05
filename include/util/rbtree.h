
#ifndef _RB_TREE_H_
#define _RB_TREE_H_

template<class KEY,class VAL, class BASE>
class _rbtree : public BASE
{
public:

    _rbtree(const _rbtree& input)
    {
        if (this != &input)
        {
            CopyFrom(input);
        }
    }

    const _rbtree& operator=(const _rbtree& input)
    {
        if (this != &input)
        {
            CopyFrom(input);
        }

        return *this;
    }

protected:

    enum COLOR{RED, BLACK};

    class RBNode
    {
    public:

        RBNode()
        {
            right = NULL;
            left = NULL;
            parent = NULL;
        }

        COLOR RB_COLOR;
        RBNode* right;
        RBNode* left;
        RBNode* parent;

        KEY first;
        VAL second;
    };

public:

    _rbtree() : _iSize(0)
    {
        this->_nullNode = new RBNode();
        this->_root = _nullNode;
        this->_nullNode->right = this->_root;
        this->_nullNode->left = this->_root;
        this->_nullNode->parent = this->_root;
        this->_nullNode->RB_COLOR = BLACK;
    }

    bool Empty()
    {
        if (this->_root == this->_nullNode)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

protected:

    // ����first
    RBNode* Find(KEY first)
    {
        RBNode* index = _root;

        while (index != _nullNode)
        {
            if (first < index->first)   
            {
                index  = index->left;  // �ȵ�ǰ��С������
            }
            else if(first > index->first)
            {
                index = index->right;  // �ȵ�ǰ�Ĵ�����
            }
            else
            {
                break;
            }
        }

        return index;
    }

    bool Insert(KEY first,VAL second)
    {
        RBNode* newnode = Insert(first);
        
        if (!IsNullNode(newnode))
        {
            newnode->second = second;

            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsNullNode(RBNode* pNode)
    {
        return pNode == _nullNode;
    }

    RBNode* Insert(KEY first)
    {
        RBNode* insert_point = _nullNode;
        RBNode* index = _root;

        while (index != _nullNode)
        {
            insert_point = index;

            if (first < index->first)
            {
                index = index->left;
            }
            else if (first > index->first)
            {
                index = index->right;
            }
            else
            {
                return index;
            }
        }

        RBNode* insert_node = new RBNode();
        ++_iSize;

        insert_node->first = first;
        insert_node->second = VAL();
        insert_node->RB_COLOR = RED;
        insert_node->right = _nullNode;
        insert_node->left = _nullNode;

        // ����������һ�ſ���
        if (insert_point == _nullNode)
        {
            _root = insert_node;
            _root->parent = _nullNode;
            _nullNode->left = _root;
            _nullNode->right = _root;
            _nullNode->parent = _root;
        }
        else
        {
            if (first < insert_point->first)
            {
                insert_point->left = insert_node;
            }
            else
            {
                insert_point->right = insert_node;
            }
            insert_node->parent = insert_point;
        }

        //
        // ����InsertFixUp�޸����������
        //
        InsertFixUp(insert_node);

        return insert_node;
    }

    //---------------------�����������޸�--------------------------------
    //3�ֲ�����������������α������(δ�漰������ȫ���Ĳ������)��
    /*
    RB-INSERT-FIXUP(T, z)
    1 while color[p[z]] = RED
    2     do if p[z] = left[p[p[z]]]
    3           then y �� right[p[p[z]]]
    4                if color[y] = RED
    5                   then color[p[z]] �� BLACK                    ? Case 1
    6                        color[y] �� BLACK                       ? Case 1
    7                        color[p[p[z]]] �� RED                   ? Case 1
    8                        z �� p[p[z]]                            ? Case 1
    9                   else if z = right[p[z]]
    10                           then z �� p[z]                       ? Case 2
    11                                LEFT-ROTATE(T, z)              ? Case 2
    12                           color[p[z]] �� BLACK                 ? Case 3
    13                           color[p[p[z]]] �� RED                ? Case 3
    14                           RIGHT-ROTATE(T, p[p[z]])            ? Case 3
    15           else (same as then clause with "right" and "left" exchanged)
    16 color[root[T]] �� BLACK
    */
    //Ȼ��Ĺ������ͷǳ����ˣ���������α�����дΪ������c++���룺
    void InsertFixUp(RBNode* node)
    {
        while (node->parent->RB_COLOR == RED)
        {
            if (node->parent==node->parent->parent->left)   //
            {
                RBNode* uncle = node->parent->parent->right;

                if (uncle->RB_COLOR == RED)   //�������1��z������y�Ǻ�ɫ�ġ�
                {
                    node->parent->RB_COLOR = BLACK;
                    uncle->RB_COLOR = BLACK;
                    node->parent->parent->RB_COLOR = RED;
                    node = node->parent->parent;
                }
                else if (uncle->RB_COLOR == BLACK )  // �������2��z������y�Ǻ�ɫ�ģ���
                {
                    if (node == node->parent->right) // ��z���Һ���
                    {
                        node = node->parent;
                        RotateLeft(node);
                    }
                    else // �������3��z������y�Ǻ�ɫ�ģ���z�����ӡ�
                    {
                        node->parent->RB_COLOR = BLACK;
                        node->parent->parent->RB_COLOR = RED;
                        RotateRight(node->parent->parent);
                    }
                }
            }
            else // �ⲿ�������Ϊ�������1�У�z�ĸ���������Ϊ�游���Һ����˵��������д�ġ�
                // 15 else (same as then clause with "right" and "left" exchanged)
            {
                RBNode* uncle = node->parent->parent->left;

                if (uncle->RB_COLOR == RED)
                {
                    node->parent->RB_COLOR = BLACK;
                    uncle->RB_COLOR = BLACK;
                    uncle->parent->RB_COLOR = RED;
                    node = node->parent->parent;
                }
                else if (uncle->RB_COLOR == BLACK)
                {
                    if (node == node->parent->left)
                    {
                        node = node->parent;
                        RotateRight(node);     // ������������ȣ�������Ϊ����
                    }
                    else
                    {
                        node->parent->RB_COLOR = BLACK;
                        node->parent->parent->RB_COLOR = RED;
                        RotateLeft(node->parent->parent);   // ������Ϊ���������ɡ�
                    }
                }
            }
        }
        _root->RB_COLOR = BLACK;
    }

    //��������ʵ��
    bool RotateLeft(RBNode* node)
    {
        if (node == _nullNode || node->right == _nullNode)
        {
            return false;//can't rotate
        }

        RBNode* lower_right = node->right;
        lower_right->parent =  node->parent;
        node->right=lower_right->left;

        if (lower_right->left != _nullNode)
        {
            lower_right->left->parent = node;
        }

        if (node->parent == _nullNode) // rotate node is root
        {
            _root = lower_right;
            _nullNode->left = _root;
            _nullNode->right= _root;
            //_nullNode->parent = _root;
        }
        else
        {
            if (node == node->parent->left)
            {
                node->parent->left = lower_right;
            }
            else
            {
                node->parent->right = lower_right;
            }
        }

        node->parent = lower_right;
        lower_right->left = node;

        return true;
    }

    //��������ʵ��
    bool RotateRight(RBNode* node)
    {
        if (node == _nullNode || node->left == _nullNode)
        {
            return false;//can't rotate
        }

        RBNode* lower_left = node->left;
        node->left = lower_left->right;
        lower_left->parent = node->parent;

        if (lower_left->right != _nullNode)
        {
            lower_left->right->parent = node;
        }

        if (node->parent == _nullNode)
        {
            _root = lower_left;
            _nullNode->left = _root;
            _nullNode->right = _root;
        }
        else
        {
            if (node == node->parent->right)
            {
                node->parent->right = lower_left;
            }
            else
            {
                node->parent->left = lower_left;
            }
        }
        node->parent = lower_left;
        lower_left->right = node;

        return true;
    }

    //--------------------------ɾ������ܲ���----------------------------------
    //α���룬�������������飬��ο��˺����ϵ�еڶ�ƪ���£�
    //�����㷨�о�ϵ�У��塢������㷨��ʵ����������
    //http://blog.csdn.net/v_JULY_v/archive/2010/12/31/6109153.aspx��
    bool Delete(KEY first)
    {
        RBNode* delete_point = Find(first);

        if (delete_point == _nullNode)
        {
            return false;
        }

        if (delete_point->left != _nullNode && delete_point->right != _nullNode)
        {
            RBNode* successor = __InOrderSuccessor(delete_point);
            delete_point->second = successor->second;
            delete_point->first = successor->first;
            delete_point = successor;
        }

        RBNode* delete_point_child;

        if (delete_point->right != _nullNode)
        {
            delete_point_child = delete_point->right;
        }
        else if (delete_point->left != _nullNode)
        {
            delete_point_child = delete_point->left;
        }
        else
        {
            delete_point_child = _nullNode;
        }

        delete_point_child->parent = delete_point->parent;

        if (delete_point->parent == _nullNode) // delete root node
        {
            _root = delete_point_child;
            _nullNode->parent = _root;
            _nullNode->left = _root;
            _nullNode->right = _root;
        }
        else if (delete_point == delete_point->parent->right)
        {
            delete_point->parent->right = delete_point_child;
        }
        else
        {
            delete_point->parent->left = delete_point_child;
        }

        if (delete_point->RB_COLOR == BLACK 
            && !(delete_point_child == _nullNode 
            && delete_point_child->parent == _nullNode))
        {
            DeleteFixUp(delete_point_child);
        }

        --_iSize;
        delete delete_point;

        return true;
    }

    //---------------------ɾ����������޸�-----------------------------------
    //���еĹ�������������23��α�����У�
    /*
    RB-DELETE-FIXUP(T, x)
    1 while x �� root[T] and color[x] = BLACK
    2     do if x = left[p[x]]
    3           then w �� right[p[x]]
    4                if color[w] = RED
    5                   then color[w] �� BLACK                        ?  Case 1
    6                        color[p[x]] �� RED                       ?  Case 1
    7                        LEFT-ROTATE(T, p[x])                    ?  Case 1
    8                        w �� right[p[x]]                         ?  Case 1
    9                if color[left[w]] = BLACK and color[right[w]] = BLACK
    10                   then color[w] �� RED                          ?  Case 2
    11                        x p[x]                                  ?  Case 2
    12                   else if color[right[w]] = BLACK
    13                           then color[left[w]] �� BLACK          ?  Case 3
    14                                color[w] �� RED                  ?  Case 3
    15                                RIGHT-ROTATE(T, w)              ?  Case 3
    16                                w �� right[p[x]]                 ?  Case 3
    17                         color[w] �� color[p[x]]                 ?  Case 4
    18                         color[p[x]] �� BLACK                    ?  Case 4
    19                         color[right[w]] �� BLACK                ?  Case 4
    20                         LEFT-ROTATE(T, p[x])                   ?  Case 4
    21                         x �� root[T]                            ?  Case 4
    22        else (same as then clause with "right" and "left" exchanged)
    23 color[x] �� BLACK 
    */
    //�������Ĺ������ܼ򵥣���������α�����д��c++���뼴�ɡ�
    void DeleteFixUp(RBNode* node)
    {
        while (node != _root && node->RB_COLOR == BLACK)
        {
            if (node == node->parent->left)
            {
                RBNode* brother = node->parent->right;

                if (brother->RB_COLOR == RED)   //���1��x���ֵ�w�Ǻ�ɫ�ġ�
                {
                    brother->RB_COLOR = BLACK;
                    node->parent->RB_COLOR = RED;
                    RotateLeft(node->parent);
                }
                else     //���2��x���ֵ�w�Ǻ�ɫ�ģ�
                {
                    if (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK)
                        //��w���������Ӷ��Ǻ�ɫ�ġ�
                    {
                        brother->RB_COLOR = RED;
                        node = node->parent;
                    }
                    else if (brother->right->RB_COLOR == BLACK)
                        //���3��x���ֵ�w�Ǻ�ɫ�ģ�w���Һ����Ǻ�ɫ��w�������Ǻ�ɫ����
                    {
                        brother->RB_COLOR = RED;
                        brother->left->RB_COLOR = BLACK;
                        RotateRight(brother);
                    }
                    else if (brother->right->RB_COLOR == RED)
                        //���4��x���ֵ�w�Ǻ�ɫ�ģ���w���Һ���ʱ��ɫ�ġ�
                    {
                        brother->RB_COLOR = node->parent->RB_COLOR;
                        node->parent->RB_COLOR = BLACK;
                        brother->right->RB_COLOR = BLACK;
                        RotateLeft(node->parent);
                        node = _root;
                    }
                }
            }
            else  //������������������1�У�node��Ϊ�Һ��Ӷ������ġ�
                  //22        else (same as then clause with "right" and "left" exchanged)
                  //ͬ����ԭ��һ�£�ֻ������������Ϊ����������������Ϊ���������ɡ��������벻�䡣
            {
                RBNode* brother = node->parent->left;

                if (brother->RB_COLOR == RED)
                {
                    brother->RB_COLOR = BLACK;
                    node->parent->RB_COLOR = RED;
                    RotateRight(node->parent);
                }
                else
                {
                    if (brother->left->RB_COLOR == BLACK && brother->right->RB_COLOR == BLACK)
                    {
                        brother->RB_COLOR = RED;
                        node = node->parent;
                    }
                    else if (brother->left->RB_COLOR == BLACK)
                    {
                        brother->RB_COLOR = RED;
                        brother->right->RB_COLOR = BLACK;
                        RotateLeft(brother);
                    }
                    else if (brother->left->RB_COLOR == RED)
                    {
                        brother->RB_COLOR = node->parent->RB_COLOR;
                        node->parent->RB_COLOR = BLACK;
                        brother->left->RB_COLOR = BLACK;
                        RotateRight(node->parent);
                        node = _root;
                    }
                }
            }
        }

        _nullNode->parent = _root;   //���node��Ϊ����㣬
        node->RB_COLOR = BLACK;    //����Ϊ��ɫ��
    }

    inline RBNode* __InOrderPredecessor(RBNode* node)
    {
        if (node == _nullNode)       //null node has no predecessor
        {
            return _nullNode;
        }

        RBNode* result = node->left;     //get node's left child

        while (result != _nullNode)         //try to find node's left subtree's right most node
        {
            if(result->right!=_nullNode)     
            {
                result = result->right;
            }
            else
            {
                break;
            }
        } // after while loop result==null or result's right child is null

        if (result == _nullNode)
        {
            RBNode* index = node->parent;
            result = node;

            while (index != _nullNode && result == index->left)
            {
                result = index;
                index = index->parent;
            }
            result = index;         // first right parent or null
        }
        return result;
    }

    inline RBNode* __InOrderSuccessor(RBNode* node)
    {
        if (node == _nullNode)       //null node has no successor
        {
            return _nullNode;
        }

        RBNode* result = node->right;   //get node's right node

        while (result != _nullNode)        //try to find node's right subtree's left most node
        {
            if (result->left != _nullNode)     
            {
                result = result->left;
            }
            else
            {
                break;
            }
        } //after while loop result==null or result's left child is null

        if (result == _nullNode)
        {
            RBNode* index = node->parent;
            result = node;

            while (index != _nullNode && result == index->right)
            {
                result = index;
                index = index->parent;
            }
            result = index;         //first parent's left or null
        }
        return result;
    }

    void __copy_from(const _rbtree& _Other, RBNode* node)
    {
        if (node == _Other._nullNode)
        {
            return;
        }
        else
        {
            // ��������
            Insert(node->first, node->second);

            __copy_from(_Other, node->left);
            __copy_from(_Other, node->right);
        }
    }

    void CopyFrom(const _rbtree& _Other)
    {
        Clear();

        __copy_from(_Other, _Other._root);
    }

    void Clear()
    {
        clear(_root);

        _root = _nullNode;

        _iSize = 0;
    }

    virtual ~_rbtree()
    {
        Clear();

        if (NULL != _root)
        {
            delete _nullNode;
        }
    }

protected:

    RBNode* GetRootNode()
    {
        return _root;
    }

    RBNode* GetNullNode()
    {
        return _nullNode;
    }

private:

    // utility function for destructor to destruct object;
    void clear(RBNode* node)
    {
        if(node == _nullNode)
        {
            return ;
        }
        else
        {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

protected:

    RBNode* _nullNode;
    RBNode* _root;

    int _iSize;
};

#endif
