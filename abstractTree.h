#ifndef REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H
#define REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H


#include <iostream>
#include <functional>
#include "nod.h"


class abstractTree {


protected:
    static int nrInstante;
    int nrNoduri;
    enum findAuxNodeType {
        T, L, U
    };

    abstractTree();

    static void interval( std::ostream &output, nod *nodCurent, int lowerBound, int upperBound );

    static void afis( std::ostream &output, nod *nod );

    template < class nodType >
    static void rotateLeft( nodType *&root, nodType *nodCurent );

    template < class nodType >
    static void rotateRight( nodType *&root, nodType *nodCurent );

    template < class nodType >
    static nodType *findNodeByValue( nodType *root, int val, findAuxNodeType valNodAux, nodType *&nodAux );

    template < class nodType >
    void deletion( nodType *&root, nodType *&nodCurent, int &lastMove, nodType *&nodUltim, int nr );

public:

    abstractTree( const abstractTree &tree2 );

    virtual ~abstractTree() = 0;

    int getNrNoduri() const;

    static int getNrInstante();

    static int upperBound( nod *root, int nr );

    static int lowerBound( nod *root, int nr );

    static void printInterval( nod *root, std::ostream &output, int lowerBound, int upperBound );

    virtual void insert( int nr ) = 0;

    virtual void clear() = 0;

    virtual bool find( int nr ) = 0;

    virtual nod *getRoot() = 0;

    friend std::istream &operator>>( std::istream &input, abstractTree &tree );

    friend std::ostream &operator<<( std::ostream &output, abstractTree &tree );
};


template < class nodType >
void abstractTree::rotateLeft( nodType *&root, nodType *nodCurent ) {
    nodType *const nodTata = nodCurent->getTata();
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
void abstractTree::rotateRight( nodType *&root, nodType *nodCurent ) {
    nodType *const nodTata = nodCurent->getTata();
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


template < class nodType >
nodType *abstractTree::findNodeByValue( nodType *const root, int val, const abstractTree::findAuxNodeType valNodAux,
                                        nodType *&nodAux ) {
    nodType *nodCurent = root;
    ///valNodAux: T == tata, L == lowerBound, U == upperBound
    if ( valNodAux == T )
        nodAux = root;
    else
        nodAux = nullptr;
    while ( nodCurent != nullptr ) {
        if ( valNodAux == T && nodCurent->getVal() != val )
            nodAux = nodCurent;
        else if ( valNodAux == L && ( nodAux == nullptr || nodAux->getVal() < nodCurent->getVal() ) &&
                  nodCurent->getVal() <= val )
            nodAux = nodCurent;
        else if ( valNodAux == U && ( nodAux == nullptr || nodAux->getVal() > nodCurent->getVal() ) &&
                  nodCurent->getVal() >= val )
            nodAux = nodCurent;
        if ( nodCurent->getVal() == val )
            return nodCurent;
        else if ( val < nodCurent->getVal() )
            nodCurent = nodCurent->getFiu( 1 );
        else
            nodCurent = nodCurent->getFiu( 2 );
    }
    return nodCurent;
}


template < class nodType >
void abstractTree::deletion( nodType *&root, nodType *&nodCurent, int &lastMove, nodType *&nodUltim, int nr ) {
    ///metoda abstracta nu dezaloca memoria pt nodul sters, ci il intoarce prin parametrul nodCurent
    nodCurent = findNodeByValue( root, nr, T, nodUltim );
    lastMove = 1;
    if ( nodCurent != nullptr ) {
        nrNoduri--;
        if ( nodCurent->getFiu( 1 ) == nullptr && nodCurent->getFiu( 2 ) == nullptr ) {
            if ( nodCurent == root )
                root = nodUltim = nullptr;
            else {
                if ( nodUltim->getFiu( 1 ) == nodCurent ) {
                    nodUltim->setFiu( 1, nullptr );
                    lastMove = 1;
                }
                else {
                    nodUltim->setFiu( 2, nullptr );
                    lastMove = 2;
                }
            }
        }
        else if ( nodCurent->getFiu( 1 ) != nullptr && nodCurent->getFiu( 2 ) == nullptr ) {
            lastMove = 1;
            if ( nodCurent == root ) {
                root = nodCurent->getFiu( 1 );
                nodCurent->getFiu( 1 )->setTata( nullptr );
                nodUltim = nullptr;
            }
            else {
                nodCurent->getFiu( 1 )->setTata( nodUltim );
                if ( nodUltim->getFiu( 1 ) == nodCurent )
                    nodUltim->setFiu( 1, nodCurent->getFiu( 1 ) );
                else
                    nodUltim->setFiu( 2, nodCurent->getFiu( 1 ) );
            }
        }
        else if ( nodCurent->getFiu( 2 ) != nullptr && nodCurent->getFiu( 1 ) == nullptr ) {
            lastMove = 2;
            if ( nodCurent == root ) {
                root = nodCurent->getFiu( 2 );
                nodCurent->getFiu( 2 )->setTata( nullptr );
                nodUltim = nullptr;
            }
            else {
                nodCurent->getFiu( 2 )->setTata( nodUltim );
                if ( nodUltim->getFiu( 1 ) == nodCurent )
                    nodUltim->setFiu( 1, nodCurent->getFiu( 2 ) );
                else
                    nodUltim->setFiu( 2, nodCurent->getFiu( 2 ) );
            }
        }
        else {
            nodType *nodAux = nodCurent->getFiu( 2 );
            lastMove = 2;
            while ( nodAux->getFiu( 1 ) != nullptr ) {
                nodAux = nodAux->getFiu( 1 );
                lastMove = 1;
            }
            nodCurent->setVal( nodAux->getVal() );
            if ( nodAux->getFiu( 2 ) == nullptr ) {
                if ( nodAux->getTata()->getFiu( 1 ) == nodAux )
                    nodAux->getTata()->setFiu( 1, nullptr );
                else
                    nodAux->getTata()->setFiu( 2, nullptr );
            }
            else {
                if ( nodAux->getTata()->getFiu( 1 ) == nodAux ) {
                    nodAux->getTata()->setFiu( 1, nodAux->getFiu( 2 ) );
                    nodAux->getFiu( 2 )->setTata( nodAux->getTata() );
                }
                else {
                    nodAux->getTata()->setFiu( 2, nodAux->getFiu( 2 ) );
                    nodAux->getFiu( 2 )->setTata( nodAux->getTata() );
                }
            }
            nodCurent = nodAux;
        }
    }
}


#endif //REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H
