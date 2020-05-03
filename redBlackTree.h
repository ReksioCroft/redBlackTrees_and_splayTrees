#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H


#include "abstractTree.h"
#include "redBlackNode.h"


class redBlackTree : public abstractTree {
    redBlackNode* root;

    void deepcopy( redBlackNode* nodNou, redBlackNode* nodCopiat );

    void redBlackInsertionFix( redBlackNode* nodCurent );

    void redBlackDeletionFix( redBlackNode* nodCurent );

public:
    redBlackTree();

    redBlackTree( redBlackTree& tree2 );

    ~redBlackTree();

    void insert( int nr );

    void deletion( int nr );

    void empty();

    bool find( int nr );

    redBlackNode* getRoot();

    int blackHigh();

    redBlackTree& operator=( redBlackTree& tree2 );
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
