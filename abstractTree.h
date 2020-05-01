#ifndef REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H
#define REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H


#include <iostream>


class abstractTree {


protected:
    int nrNoduri;


    template < class nodType >
    void rotateLeft( nodType*& root, nodType* nodCurent ) {
        nodType* nodTata = nodCurent->getTata();
        if ( nodCurent->getTata() == root ) {
            nodCurent->setTata( nullptr );
            root = nodCurent;
        }
        else {
            if ( nodTata->getTata()->getFiu( 1 ) == nodTata )
                nodTata->getTata()->setFiu( 1, nodCurent );
            else
                nodTata->getTata()->setFiu( 2, nodCurent );
            nodCurent->setTata( nodTata->getTata() );
        }

        if ( nodCurent->getFiu( 1 ) != nullptr )
            nodCurent->getFiu( 1 )->setTata( nodTata );
        nodTata->setFiu( 2, nodCurent->getFiu( 1 ) );
        nodTata->setTata( nodCurent );
        nodCurent->setFiu( 1, nodTata );
    }


    template < class nodType >
    void rotateRight( nodType*& root, nodType* nodCurent ) {
        nodType* nodTata = nodCurent->getTata();
        if ( nodCurent->getTata() == root ) {
            nodCurent->setTata( nullptr );
            root = nodCurent;
        }
        else {
            if ( nodTata->getTata()->getFiu( 1 ) == nodTata )
                nodTata->getTata()->setFiu( 1, nodCurent );
            else
                nodTata->getTata()->setFiu( 2, nodCurent );
            nodCurent->setTata( nodTata->getTata() );
        }

        if ( nodCurent->getFiu( 2 ) != nullptr )
            nodCurent->getFiu( 2 )->setTata( nodTata );
        nodTata->setFiu( 1, nodCurent->getFiu( 2 ) );
        nodTata->setTata( nodCurent );
        nodCurent->setFiu( 2, nodTata );
    }


public:
    abstractTree();

    virtual ~abstractTree() = 0;

    virtual void insert( int nr ) = 0;

    virtual void deletion( int nr ) = 0;

    virtual bool find( int nr ) = 0;

    virtual int lowerBound( int nr ) = 0;

    virtual int upperBound( int nr ) = 0;

    virtual void printInterval( std::ostream& output, int lowerBound, int uperBound ) = 0;

    int getNrNoduri();
};


#endif //REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H
