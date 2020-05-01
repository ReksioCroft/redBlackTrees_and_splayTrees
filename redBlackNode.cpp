#include "redBlackNode.h"

redBlackNode::redBlackNode( int nr ) : nod( nr ) {
    culoare = new char( 'R' );
}


redBlackNode::~redBlackNode() {
    delete culoare;
}


char redBlackNode::getCuloare() {
    if ( this == nullptr )
        throw std::logic_error( "Ai ajuns sa ceri informatie din neant" );
    return *culoare;
}


void redBlackNode::setCuloare( char c ) {
    if ( this == nullptr )
        throw std::logic_error( "Ai ajuns sa dai informatie in neant" );
    *culoare = c;
}


redBlackNode* redBlackNode::getTata() {
    if ( this == nullptr )
        throw std::logic_error( "Ai ajuns sa ceri informatie din neant" );
    return dynamic_cast<redBlackNode*>(tata);
}


void redBlackNode::setTata( redBlackNode* nodCurent ) {
    if ( this == nullptr )
        throw std::logic_error( "Ai ajuns sa dai informatie in neant" );
    tata = nodCurent;
}


redBlackNode* redBlackNode::getFiu( int nrFiu ) {
    if ( this == nullptr )
        throw std::logic_error( "Ai ajuns sa ceri informatie din neant" );
    if ( nrFiu == 1 )
        return dynamic_cast<redBlackNode*>(fiu1);
    else
        return dynamic_cast<redBlackNode*>(fiu2);
}


void redBlackNode::setFiu( int nrFiu, redBlackNode* nodCurent ) {
    if ( this == nullptr )
        throw std::logic_error( "Ai ajuns sa dai informatie in neant" );
    if ( nrFiu == 1 )
        fiu1 = nodCurent;
    else
        fiu2 = nodCurent;
}

