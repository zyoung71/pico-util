#include <util/Tree.h>

#include <algorithm>

template<typename T>
bool Tree<T>::TreeNode::EditChild(const T& new_data)
{
    auto node = children.extract(data);
    if (!node)
        return false;

    node.key() = new_data;
    children.insert(std::move(node));
    return true;
}

template<typename T>
Tree<T>::Tree()
    : root(nullptr)
{
}

template<typename T>
void Tree<T>::AddNode(const T& data, TreeNode* parent)
{
    parent->children.emplace(data, std::make_unique<TreeNode>(data, parent));
}

template<typename T>
void Tree<T>::AddNode(const T& data)
{
    return AddNode(data, root);
}

template<typename T>
bool Tree<T>::RemoveNode(const T& data, TreeNode* parent)
{
    auto& collec = parent->children;

    for (auto it = collec.begin(); it != collec.end(); ++it)
    {
        if (it->first == data)
        {
            for (auto& child : it->second->children)
            {
                child.second->parent = parent;
                collec.emplace(child.first, std::move(child.second));
            }

            collec.erase(it);

            return true;
        }
    }

    return false;
}

template<typename T>
bool Tree<T>::RemoveNode(const T& data)
{
    return RemoveNode(data, root);
}