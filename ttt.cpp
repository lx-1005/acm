#include <iostream>
using namespace std;

// 定义一个结构体表示内存块
struct MemoryBlock {
    bool isFree;  // 标识该块是否为空闲
    int size;     // 块的大小
    // 其他块相关的属性
};

// 定义一个二叉树节点表示内存块
struct MemoryNode {
    MemoryBlock* block;        // 内存块指针
    MemoryNode* leftChild;     // 左子节点指针
    MemoryNode* rightChild;    // 右子节点指针
    MemoryNode* parent;        // 父节点指针
    bool isFree;               // 标识该节点所代表的内存块是否为空闲
};

// 全局变量，表示伙伴系统的内存树根节点
MemoryNode* root;

// 初始化伙伴系统
void initialize(int size) {
    // 创建一个初始的内存块，并将其作为根节点
    root = new MemoryNode;
    root->block = new MemoryBlock;
    root->block->size = size;
    root->isFree = true;
    root->leftChild = nullptr;
    root->rightChild = nullptr;
    root->parent = nullptr;
}

// 在内存树中查找适合大小的空闲块
MemoryNode* findFreeBlock(MemoryNode* node, int size) {
    // 如果节点为空或节点不是空闲块
    if (node == nullptr || !node->isFree) {
        return nullptr;
    }
    
    // 如果节点所代表的块大小正好合适
    if (node->block->size == size) {
        return node;
    }
    
    // 尝试在左子树中查找
    MemoryNode* left = findFreeBlock(node->leftChild, size);
    if (left != nullptr) {
        return left;
    }
    
    // 尝试在右子树中查找
    MemoryNode* right = findFreeBlock(node->rightChild, size);
    if (right != nullptr) {
        return right;
    }
    
    return nullptr;
}

// 分配内存
MemoryBlock* allocate(int size) {
    // 在内存树中查找适合大小的空闲块
    MemoryNode* node = findFreeBlock(root, size);
    
    // 如果找到了合适的空闲块
    if (node != nullptr) {
        // 标记该块为已分配
        node->isFree = false;
        // 返回内存块的起始地址
        return node->block;
    }
    
    // 如果没有找到适合的空闲块，返回nullptr或错误码
    return nullptr;
}

// 获取节点的伙伴节点
MemoryNode* getBuddy(MemoryNode* node) {
    if (node->parent->leftChild == node) {
        return node->parent->rightChild;
    } else {
        return node->parent->leftChild;
    }
}

// 创建一个内存节点
MemoryNode* createMemoryNode(int size) {
    MemoryNode* node = new MemoryNode;
    node->block = new MemoryBlock;
    node->block->size = size;
    node->isFree = false;
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    node->parent = nullptr;
    return node;
}

// 合并两个节点
void mergeNodes(MemoryNode* node1, MemoryNode* node2) {
    // 创建一个新的节点，代表合并后的块
    MemoryNode* mergedNode = createMemoryNode(node1->block->size * 2);
    
    // 将新节点作为父节点的子节点
    if (node1->parent->leftChild == node1) {
        node1->parent->leftChild = mergedNode;
    } else {
        node1->parent->rightChild = mergedNode;
    }
    
    // 更新新节点的父节点
    mergedNode->parent = node1->parent;
    
    // 释放旧的节点
    delete node1;
    delete node2;
}

// 尝试合并伙伴块
void tryMergeBuddies(MemoryNode* node) {
    // 如果节点是根节点或者父节点为空，则无法合并
    if (node == root || node->parent == nullptr) {
        return;
    }
    
    // 获取节点的伙伴节点
    MemoryNode* buddy = getBuddy(node);
    
    // 如果伙伴节点是空闲的且与当前节点大小相等
    if (buddy->isFree && buddy->block->size == node->block->size) {
        // 合并两个节点
        mergeNodes(node, buddy);
        // 尝试继续合并
        tryMergeBuddies(node->parent);
    }
}



// 在内存树中查找与给定块相对应的节点
MemoryNode* findNodeByBlock(MemoryNode* node, MemoryBlock* block) {
    // 如果节点为空，则返回nullptr
    if (node == nullptr) {
        return nullptr;
    }
    
    // 如果节点所代表的块与给定块相同，返回该节点
    if (node->block == block) {
        return node;
    }
    
    // 尝试在左子树中查找
    MemoryNode* left = findNodeByBlock(node->leftChild, block);
    if (left != nullptr) {
        return left;
    }
    
    // 尝试在右子树中查找
    MemoryNode* right = findNodeByBlock(node->rightChild, block);
    if (right != nullptr) {
        return right;
    }
    
    return nullptr;
}

// 释放内存
void deallocate(MemoryBlock* block) {
    // 在内存树中查找与给定块相对应的节点
    MemoryNode* node = findNodeByBlock(root, block);
    
    // 如果找到了对应的节点
    if (node != nullptr) {
        // 标记该块为空闲
        node->isFree = true;
        // 尝试合并伙伴块
        tryMergeBuddies(node);
    }
}

















int main() {
    initialize(1024);              // 初始化伙伴系统，分配1024字节的内存
    MemoryBlock* block = allocate(256);   // 分配一个大小为256字节的内存块
    if (block != nullptr) {
        cout << "Memory block allocated successfully!" << endl;
        deallocate(block);             // 释放内存块
        cout << "Memory block deallocated successfully!" << endl;
    } else {
        cout << "Failed to allocate memory block!" << endl;
    }
    
    return 0;
}
