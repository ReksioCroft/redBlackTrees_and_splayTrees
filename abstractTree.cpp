#include "abstractTree.h"
#include "splayTree.h"


abstractTree::abstractTree() {
    nrNoduri = 0;
}


abstractTree::~abstractTree() {
    nrNoduri = 0;
}


int abstractTree::getNrNoduri() {
    return nrNoduri;
}


template < class nodType >
void afis( std::ostream& output, nodType* nod ) {
    if ( nod->getFiu( 1 ) != nullptr )
        afis( output, nod->getFiu( 1 ) );
    output << nod->getVal() << " ";
    if ( nod->getFiu( 2 ) != nullptr )
        afis( output, nod->getFiu( 2 ) );
}


std::istream& operator>>( std::istream& input, abstractTree* tree ) {
    int nr;
    input >> nr;
    tree->insert( nr );
    return input;
}


std::ostream& operator<<( std::ostream& output, abstractTree* tree ) {
    afis( output, tree->getRoot() );
    return output;
}
