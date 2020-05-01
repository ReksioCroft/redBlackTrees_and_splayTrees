#ifndef REDBLACKTREES_SPLAYTREES_SPLAYTREE_H
#define REDBLACKTREES_SPLAYTREES_SPLAYTREE_H


#include "abstractTree.h"
#include "nod.h"


class splayTree : public abstractTree {
    nod* root;

    void splayInsert( nod* nodNou );

    void splay( nod* nodCurent );


public:
    splayTree();

    ~splayTree();

    void insert( int nr );

    void deletion( int nr );

    bool find( int nr );

    nod* getRoot();
};


#endif //REDBLACKTREES_SPLAYTREES_SPLAYTREE_H
