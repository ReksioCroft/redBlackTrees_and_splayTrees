#include "redBlackNode.h"


redBlackNode::redBlackNode( int nr ) : nod( nr ) {
    culoare = new char( 'r' );
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