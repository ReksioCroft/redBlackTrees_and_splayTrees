#ifndef REDBLACKTREES_SPLAYTREES_NOD_H
#define REDBLACKTREES_SPLAYTREES_NOD_H


class nod {
protected:
    nod *tata;
    nod *fiu1;
    nod *fiu2;
    int val;
public:
    explicit nod( int nr = 0 );

    nod( const nod &nod2 );

    virtual nod *getFiu( int nrFiu );

    void setFiu( int nrFiu, nod *nodNou );

    void setVal( int nr );

    virtual nod *getTata();

    void setTata( nod *nodNou );

    int getVal() const;

    virtual ~nod();

    nod &operator=( const nod &noCopyNode ) = delete;
};


#endif //REDBLACKTREES_SPLAYTREES_NOD_H
