#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H


#include "nod.h"


class redBlackNode : public nod {
    char* culoare;
public:
    explicit redBlackNode( int nr = 0 );

    explicit redBlackNode( redBlackNode& nod2 );

    ~redBlackNode();

    char getCuloare() const;

    void setCuloare( char c );

    redBlackNode* getTata();

    void setTata( redBlackNode* nodCurent );

    redBlackNode* getFiu( int nrFiu );

    void setFiu( int nrFiu, redBlackNode* nodCurent );

    redBlackNode& operator=( redBlackNode* nod2 );
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
