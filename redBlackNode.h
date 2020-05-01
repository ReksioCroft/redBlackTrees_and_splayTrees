#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H


#include "nod.h"


class redBlackNode : public nod {
    char* culoare;
public:
    redBlackNode( int nr = 0 );

    ~redBlackNode();

    char getCuloare();

    void setCuloare( char c );
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
