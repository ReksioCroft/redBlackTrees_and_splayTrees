#ifndef SPLAYTREES_NOD_H
#define SPLAYTREES_NOD_H


class nod {
    nod* tata;
    nod* fiu1;
    nod* fiu2;
    int val;
public:
    explicit nod( int nr = 0 );

    nod* getFiu( int nrFiu );

    void setFiu( int nrFiu, nod* nodNou );

    void setVal( int nr );

    nod* getTata();

    void setTata( nod* nodNou );

    int getVal();

    ~nod();
};


#endif //SPLAYTREES_NOD_H
