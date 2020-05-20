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


int abstractTree::getNrInstante() {
    return nrInstante;
}


std::istream &operator>>( std::istream &input, abstractTree &tree ) {
    int nr;
    input >> nr;
    tree.insert( nr );
    return input;
}


std::ostream &operator<<( std::ostream &output, abstractTree &tree ) {
    if ( tree.getRoot() != nullptr ) {
        abstractTree::afis( output, tree.getRoot() );
        output << "\n";
    }
    else output << "Tree gol\n";
    return output;
}


void abstractTree::afis( std::ostream &output, nod *nod ) {
    if ( nod->getFiu( 1 ) != nullptr )
        afis( output, nod->getFiu( 1 ) );
    output << nod->getVal() << " ";
    if ( nod->getFiu( 2 ) != nullptr )
        afis( output, nod->getFiu( 2 ) );
}


int abstractTree::lowerBound( nod *root, int nr ) {
    nod *lowerBound;
    findNodeByValue( root, nr, L, lowerBound );
    return lowerBound->getVal();
}


int abstractTree::upperBound( nod *root, int nr ) {
    nod *upperBound;
    findNodeByValue( root, nr, U, upperBound );
    return upperBound->getVal();
}


void abstractTree::printInterval( nod *root, std::ostream &output, int lowerBound, int upperBound ) {
    interval( output, root, lowerBound, upperBound );
    output << '\n';
}


void abstractTree::interval( std::ostream &output, nod *nodCurent, int lowerBound, int upperBound ) {
    if ( nodCurent->getFiu( 1 ) != nullptr && nodCurent->getVal() >= lowerBound )
        interval( output, nodCurent->getFiu( 1 ), lowerBound, upperBound );
    if ( nodCurent->getVal() >= lowerBound && nodCurent->getVal() <= upperBound )
        output << nodCurent->getVal() << " ";
    if ( nodCurent->getFiu( 2 ) != nullptr && nodCurent->getVal() <= upperBound )
        interval( output, nodCurent->getFiu( 2 ), lowerBound, upperBound );
}
