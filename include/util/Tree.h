#pragma once

#include <map>
#include <memory>

template<typename T>
class Tree
{
public:
    struct TreeNode
    {
        T data;
        const TreeNode* parent;
        std::map<T, std::unique_ptr<TreeNode>> children; // will auto-delete when parent node is removed 

        inline TreeNode(const T& data, const TreeNode* parent = nullptr) : data(data), parent(parent) {}
        inline bool operator==(const TreeNode& other) const
        {
            return data == other.data;
        }
        inline bool operator<(const TreeNode& other) const
        {
            return data < other.data;
        }

        bool EditChild(const T& new_data);
    };

protected:
    TreeNode* root;

public:
    Tree();

    virtual void AddNode(const T& data, TreeNode* parent);
    void AddNode(const T& data);

    virtual bool RemoveNode(const T& data, TreeNode* parent);
    bool RemoveNode(const T& data);
};

#include "util/Tree.tpp"