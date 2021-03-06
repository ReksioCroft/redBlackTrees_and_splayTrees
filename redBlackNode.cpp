#include "redBlackNode.h"


redBlackNode::redBlackNode( int nr ) : nod( nr ) {
    culoare = 'R';
}


redBlackNode::redBlackNode( const redBlackNode &nod2 ) : nod( nod2 ) {
    culoare = nod2.getCuloare();
}


redBlackNode::~redBlackNode() {
    culoare = 0;
}


char redBlackNode::getCuloare() const {
    return culoare;
}


void redBlackNode::setCuloare( char c ) {
    culoare = c;
}


redBlackNode *redBlackNode::getTata() {
    return dynamic_cast<redBlackNode *>(tata);
}


redBlackNode *redBlackNode::getFiu( int nrFiu ) {
    if ( nrFiu == 1 )
        return dynamic_cast<redBlackNode *>(fiu1);
    else
        return dynamic_cast<redBlackNode *>(fiu2);
}
