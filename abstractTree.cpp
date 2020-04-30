#include "abstractTree.h"


abstractTree::abstractTree() {
    root = nullptr;
}


abstractTree::~abstractTree() {
    root = nullptr;
}


void abstractTree::rotateRight( nod* nodCurent ) {
    nod* nodTata = nodCurent->getTata();
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


void abstractTree::rotateLeft( nod* nodCurent ) {
    nod* nodTata = nodCurent->getTata();
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
