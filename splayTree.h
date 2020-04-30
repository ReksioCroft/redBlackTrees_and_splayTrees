#ifndef SPLAYTREES_SPLAYTREE_H
#define SPLAYTREES_SPLAYTREE_H


#include "abstractTree.h"


class splayTree : public abstractTree {

    void bstInsert( nod* nodNou );

    void splay( nod* nodCurent );

    nod* findNodeByValue( int val, nod*& nodTata, nod*& lowerBound, nod*& upperBound );

    void interval( std::ostream& output, nod* nodCurent, int lowerBound, int uperBound );

public:
    splayTree();

    ~splayTree();

    void insert( int nr );

    void deletion( int nr );

    bool find( int nr );

    int lowerBound( int nr );

    int upperBound( int nr );

    void printInterval( std::ostream& output, int lowerBound, int uperBound );

};


#endif //SPLAYTREES_SPLAYTREE_H
