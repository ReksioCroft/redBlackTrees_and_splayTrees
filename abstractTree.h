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


    template < class nodType >
    nodType* findNodeByValue( nodType*& root, int val, nodType*& nodTata, nodType*& lowerBound, nodType*& upperBound ) {
        nodType* nodCurent = nodTata = root;
        lowerBound = upperBound = nullptr;
        while ( nodCurent != nullptr ) {
            if ( nodCurent->getVal() != val )
                nodTata = nodCurent;
            if ( ( lowerBound == nullptr || lowerBound->getVal() < nodCurent->getVal() ) && nodCurent->getVal() <= val )
                lowerBound = nodCurent;
            if ( ( upperBound == nullptr || upperBound->getVal() > nodCurent->getVal() ) && nodCurent->getVal() >= val )
                upperBound = nodCurent;
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
    void interval( std::ostream& output, nodType* nodCurent, int lowerBound, int upperBound ) {
        if ( nodCurent->getFiu( 1 ) != nullptr && nodCurent->getVal() >= lowerBound )
            interval( output, nodCurent->getFiu( 1 ), lowerBound, upperBound );
        if ( nodCurent->getVal() >= lowerBound && nodCurent->getVal() <= upperBound )
            output << nodCurent->getVal() << " ";
        if ( nodCurent->getFiu( 2 ) != nullptr && nodCurent->getVal() <= upperBound )
            interval( output, nodCurent->getFiu( 2 ), lowerBound, upperBound );
    }


public:
    abstractTree();

    virtual ~abstractTree() = 0;

    virtual void insert( int nr ) = 0;


    template <class nodType>
    void deletion( nodType*& root, nodType*& nodCurent, nodType*& nodUltim, int nr ) {
        ///metoda abstracta nu dezaloca memoria pt nodul sters, ci il intoarce prin parametrul nodCurent
        nodType* lowerBound;
        nodType* upperBound;
        nodCurent = findNodeByValue( root, nr, nodUltim, lowerBound, upperBound );

        if ( nodCurent != nullptr ) {
            nrNoduri--;
            if ( nodCurent->getFiu( 1 ) == nullptr && nodCurent->getFiu( 2 ) == nullptr ) {
                if ( nodCurent == root )
                    root = nodUltim = nullptr;
                else {
                    if ( nodUltim->getFiu( 1 ) == nodCurent )
                        nodUltim->setFiu( 1, nullptr );
                    else
                        nodUltim->setFiu( 2, nullptr );
                }
            }
            else if ( nodCurent->getFiu( 1 ) != nullptr && nodCurent->getFiu( 2 ) == nullptr ) {
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
                nodType* nodAux = nodCurent->getFiu( 2 );
                while ( nodAux->getFiu( 1 ) != nullptr )
                    nodAux = nodAux->getFiu( 1 );
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

    virtual bool find( int nr ) = 0;


    template < class nodType >
    int upperBound( nodType* root, int nr ) {
        nodType* nodCurent;
        nodType* nodUltim;
        nodType* lowerBound;
        nodType* upperBound;
        nodCurent = findNodeByValue( root, nr, nodUltim, lowerBound, upperBound );
        return upperBound->getVal();
    }


    template < class nodType >
    void printInterval( nodType* root, std::ostream& output, int lowerBound, int upperBound ) {
        interval( output, root, lowerBound, upperBound );
        output << '\n';
    }


    template < class nodType >
    int lowerBound( nodType* root, int nr ) {
        nodType* nodCurent;
        nodType* nodUltim;
        nodType* lowerBound;
        nodType* upperBound;
        nodCurent = findNodeByValue( root, nr, nodUltim, lowerBound, upperBound );
        return lowerBound->getVal();
    }


    int getNrNoduri();
};


#endif //REDBLACKTREES_SPLAYTREES_ABSTRACTTREE_H
