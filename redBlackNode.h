#ifndef REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
#define REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H


#include "nod.h"


class redBlackNode : public nod {
    char culoare;
public:
    explicit redBlackNode( int nr = 0 );

    redBlackNode( const redBlackNode &nod2 );

    ~redBlackNode() override;

    char getCuloare() const;

    void setCuloare( char c );

    redBlackNode *getTata() override;

    redBlackNode *getFiu( int nrFiu ) override;

    redBlackNode &operator=( const redBlackNode &noCopyNode ) = delete;
};


#endif //REDBLACKTREES_SPLAYTREES_REDBLACKNODE_H
