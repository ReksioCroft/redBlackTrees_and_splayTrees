#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H


#include "nod.h"
#include <stdexcept>


class redBlackNode : public nod {
    char* culoare;
public:
    redBlackNode( int nr = 0 );

    redBlackNode( redBlackNode* nod2 );

    ~redBlackNode();

    char getCuloare();

    void setCuloare( char c );

    redBlackNode* getTata();

    void setTata( redBlackNode* nodCurent );

    redBlackNode* getFiu( int nrFiu );

    void setFiu( int nrFiu, redBlackNode* nodCurent );

    redBlackNode& operator=( redBlackNode* nod2 );
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
