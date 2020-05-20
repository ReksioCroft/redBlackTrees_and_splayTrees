#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H


#include "abstractTree.h"
#include "redBlackNode.h"


class redBlackTree : public abstractTree {
    static int nrInstanteCurente;
    redBlackNode *root;

    void deepcopy( redBlackNode *nodNou, redBlackNode *nodCopiat );

    void redBlackInsertionFix( redBlackNode *nodCurent );

    void redBlackDeletionFix( redBlackNode *nodCurent );

    redBlackTree();

public:
    redBlackTree( const redBlackTree &tree2 );

    static redBlackTree *getInstance();

    ~redBlackTree() override;

    void insert( int nr ) override;

    void deletion( int nr );

    void clear() override;

    bool find( int nr ) override;

    redBlackNode *getRoot() override;

    int blackHigh() const;

    redBlackTree &operator=( redBlackTree tree2 );
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKTREE_H
