#include "abstractTree.h"
#include "splayTree.h"


abstractTree::abstractTree() {
    nrNoduri = 0;
}


abstractTree::~abstractTree() {
    nrNoduri = 0;
}


int abstractTree::getNrNoduri() {
    return nrNoduri;
}