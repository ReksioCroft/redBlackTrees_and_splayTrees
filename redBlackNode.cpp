#include "redBlackNode.h"


redBlackNode::redBlackNode( int nr ) : nod( nr ) {
    culoare = new char( 'R' );
}


redBlackNode::~redBlackNode() {
    delete culoare;
}


char redBlackNode::getCuloare() {
    return *culoare;
}


void redBlackNode::setCuloare( char c ) {
    *culoare = c;
}


redBlackNode* redBlackNode::getTata() {
    return dynamic_cast<redBlackNode*>(tata);
}


void redBlackNode::setTata( redBlackNode* nodCurent ) {
    tata = nodCurent;
}


redBlackNode* redBlackNode::getFiu( int nrFiu ) {
    if ( nrFiu == 1 )
        return dynamic_cast<redBlackNode*>(fiu1);
    else
        return dynamic_cast<redBlackNode*>(fiu2);
}


void redBlackNode::setFiu( int nrFiu, redBlackNode* nodCurent ) {
    if ( nrFiu == 1 )
        fiu1 = nodCurent;
    else
        fiu2 = nodCurent;
}


redBlackNode& redBlackNode::operator=( redBlackNode* nod2 ) {
    val = nod2->getVal();
    *culoare = nod2->getCuloare();
    return *this;
}


redBlackNode::redBlackNode( redBlackNode* nod2 ) : nod( nod2 ) {
    culoare = new char( nod2->getCuloare() );
}
