#pragma once

#include "Tree.h"

struct FilesystemNodeData
{

    char name[256];
    bool is_directory;

    bool operator==(const FilesystemNodeData& other) const;
    bool operator<(const FilesystemNodeData& other) const;
};

class FilesystemTree : public Tree<FilesystemNodeData>
{
public:
    FilesystemTree();

    virtual bool RemoveNode(const FilesystemNodeData& data, TreeNode* parent) override;
    using Tree::RemoveNode;
};