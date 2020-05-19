#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H


#include "nod.h"


class redBlackNode : public nod {
    char* culoare;
public:
    explicit redBlackNode( int nr = 0 );

    redBlackNode( redBlackNode& nod2 );

    ~redBlackNode() override;

    char getCuloare() const;

    void setCuloare( char c );

    redBlackNode* getTata() override;

    void setTata( redBlackNode* nodCurent );

    redBlackNode* getFiu( int nrFiu ) override;

    void setFiu( int nrFiu, redBlackNode* nodCurent );

    redBlackNode& operator=( redBlackNode* nod2 );
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
