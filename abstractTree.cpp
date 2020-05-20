#include "abstractTree.h"
#include "splayTree.h"


int abstractTree::nrInstante = 0;


abstractTree::abstractTree() {
    nrInstante++;
    nrNoduri = 0;
}


abstractTree::abstractTree( const abstractTree &tree2 ) {
    nrInstante++;
    nrNoduri = tree2.nrNoduri;
}


abstractTree::~abstractTree() {
    nrInstante--;
    nrNoduri = 0;
}


int abstractTree::getNrNoduri() const {
    return nrNoduri;
}


std::istream &operator>>( std::istream &input, abstractTree &tree ) {
    int nr;
    input >> nr;
    tree.insert( nr );
    return input;
}


std::ostream &operator<<( std::ostream &output, abstractTree &tree ) {
    if ( tree.getRoot() != nullptr ) {
        afis( output, tree.getRoot() );
        output << "\n";
    }
    else output << "Tree gol\n";
    return output;
}


int abstractTree::getNrInstante() {
    return nrInstante;
}