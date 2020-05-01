#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H


#include "abstractTree.h"
#include "redBlackNode.h"


class redBlackTree : public abstractTree {
    redBlackNode* root;
    void redBlackFix(redBlackNode* nodCurent);
public:
    redBlackTree();

    ~redBlackTree();

    void insert( int nr );

    void deletion( int nr );

    bool find( int nr );

    int lowerBound( int nr );

    int upperBound( int nr );

    void printInterval( std::ostream& output, int lowerBound, int uperBound );
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
