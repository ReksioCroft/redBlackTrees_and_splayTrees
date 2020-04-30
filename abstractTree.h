#ifndef REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H
#define REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H


#include "nod.h"
#include <iostream>


class abstractTree {
protected:
    nod* root;

    void rotateLeft( nod* nodCurent );

    void rotateRight( nod* nodCurent );

public:
    virtual void insert( int nr ) = 0;

    virtual void deletion( int nr ) = 0;

    virtual ~abstractTree() = 0;

    abstractTree();

    virtual bool find( int nr ) = 0;

    virtual int lowerBound( int nr ) = 0;

    virtual int upperBound( int nr ) = 0;

    virtual void printInterval( std::ostream& output, int lowerBound, int uperBound ) = 0;
};


#endif //REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H
