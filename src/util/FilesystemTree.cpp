#include <util/FilesystemTree.h>

#include <string.h>

bool FilesystemNodeData::operator==(const FilesystemNodeData& other) const
{
    return (strncmp(name, other.name, 256) == 0) && (is_directory == other.is_directory);
}

bool FilesystemNodeData::operator<(const FilesystemNodeData& other) const
{
    int compared = strncmp(name, other.name, 256);
    if (compared != 0)
        return compared < 0;
    return is_directory < other.is_directory;
}

FilesystemTree::FilesystemTree()
    : Tree()
{
}

bool FilesystemTree::RemoveNode(const FilesystemNodeData& data, TreeNode* parent)
{
    auto& collec = parent->children;
    for (auto it = collec.begin(); it != collec.end(); ++it)
    {
        if (it->first == data)
        {
            collec.erase(it);
            return true;
        }
    }

    return false;
}