#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H


#include "abstractTree.h"
#include "redBlackNode.h"


class redBlackTree : public abstractTree {
    redBlackNode* root;

    void redBlackInsertionFix( redBlackNode* nodCurent );

    void redBlackDeletionFix( redBlackNode* nodCurent );

public:
    redBlackTree();

    ~redBlackTree();

    void insert( int nr );

    void deletion( int nr );

    bool find( int nr );

};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
