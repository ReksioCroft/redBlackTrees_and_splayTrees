#ifndef REDBLACKTREES_SPLAYTREES_SPLAYTREE_H
#define REDBLACKTREES_SPLAYTREES_SPLAYTREE_H


#include "abstractTree.h"
#include "nod.h"


class splayTree : public abstractTree {
    static int nrInstanteCurente;
    nod* root;

    void splayInsert( nod* nodNou ) const;

    void splay( nod* nodCurent );

    void deepcopy( nod* nodNou, nod* nodCopiat );

    splayTree();

public:
    splayTree( const splayTree& tree2 );

    ~splayTree() override;

    void insert( int nr ) override;

    void deletion( int nr );

    bool find( int nr ) override;

    void clear() override;

    nod* getRoot() override;

    splayTree& operator=( splayTree tree2 );

    static splayTree* getInstance();
};


#endif //REDBLACKTREES_SPLAYTREES_SPLAYTREE_H
