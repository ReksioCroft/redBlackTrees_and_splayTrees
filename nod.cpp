#include "nod.h"


nod::nod( int nr ) {
    tata = fiu1 = fiu2 = nullptr;
    val = nr;
}


nod::~nod() {
    tata = fiu1 = fiu2 = nullptr;
    val = 0;
}


nod* nod::getFiu( int nrFiu ) {
    if ( nrFiu == 1 )
        return fiu1;
    else
        return fiu2;
}


nod* nod::getTata() {
    return tata;
}


void nod::setFiu( int nrFiu, nod* nodNou ) {
    if ( nrFiu == 1 )
        fiu1 = nodNou;
    else
        fiu2 = nodNou;
}


void nod::setTata( nod* nodNou ) {
    tata = nodNou;
}


void nod::setVal( int nr ) {
    val = nr;
}


nod::nod( nod* nod2 ) {
    fiu1 = fiu2 = tata = nullptr;
    val = nod2->val;
}


int nod::getVal() {
    return val;
}


nod& nod::operator=( nod& nod2 ) {
    val = nod2.val;
    return *this;
}
