///https://en.wikipedia.org/wiki/Splay_tree
///http://www.btechsmartclass.com/data_structures/splay-trees.html
#include "splayTree.h"


splayTree::splayTree() : abstractTree() {
    root = nullptr;
}


splayTree::~splayTree() {
    while ( root != nullptr )
        deletion( root->getVal() );
}


void splayTree::insert( int nr ) {
    nod* nodNou = new nod( nr );
    if ( root == nullptr ) {
        root = nodNou;
    }
    else {
        splayInsert( nodNou );
        splay( nodNou );
    }
    nrNoduri++;
}


void splayTree::splayInsert( nod* nodNou ) {
    nod* nodCurent = root;
    int lastMove = 1;
    while ( nodCurent != nullptr ) {
        nodNou->setTata( nodCurent );
        if ( nodNou->getVal() < nodCurent->getVal() ) {
            nodCurent = nodCurent->getFiu( 1 );
            lastMove = 1;
        }
        else {
            nodCurent = nodCurent->getFiu( 2 );
            lastMove = 2;
        }
    }
    nodNou->getTata()->setFiu( lastMove, nodNou );
}


nod* splayTree::getRoot() {
    return root;
}


void splayTree::splay( nod* nodCurent ) {
    if ( nodCurent->getTata() == root ) {
        if ( nodCurent->getTata()->getFiu( 1 ) == nodCurent ) {
            ///daca sunt fiul din stanga al radacinii => "Zig Rotation"
            rotateRight <nod>( root, nodCurent );
        }
        else {
            rotateLeft <nod>( root, nodCurent );
            ///daca sunt fiul din dreapta al radacinii => "Zag Rotation"

        }
    }
    else if ( nodCurent != root ) { ///daca mai continui
        nod* nodTata = nodCurent->getTata();
        if ( nodCurent->getTata()->getFiu( 1 ) == nodCurent ) {
            ///sunt un fiu stang => Zig-zig sau Zig-zag
            if ( nodTata->getTata()->getFiu( 1 ) == nodTata ) {
                ///Zig-Zig step
                rotateRight <nod>( root, nodTata );
                rotateRight <nod>( root, nodCurent );
            }
            else {
                ///zig-zag
                rotateRight <nod>( root, nodCurent );
                rotateLeft <nod>( root, nodCurent );
            }

        }
        else {
            if ( nodTata->getTata()->getFiu( 2 ) == nodTata ) {
                ///zag-zag
                rotateLeft <nod>( root, nodTata );
                rotateLeft <nod>( root, nodCurent );
            }
            else {
                ///zag-zig
                rotateLeft <nod>( root, nodCurent );
                rotateRight <nod>( root, nodCurent );
            }
        }
        splay( nodCurent );
    }
}


bool splayTree::find( int nr ) {
    if ( root == nullptr )
        return false;
    nod* nodUltim;
    nod* lowerBound;
    nod* upperBound;
    nod* nodCautat = findNodeByValue( root, nr, nodUltim, lowerBound, upperBound );
    if ( nodCautat == nullptr ) {
        splay( nodUltim );
        return false;
    }
    else {
        splay( nodCautat );
        return true;
    }
}


void splayTree::deletion( int nr ) {
    nod* nodSters;
    nod* nodUltim;
    int lastMove;
    abstractTree::deletion( root, nodSters, lastMove, nodUltim, nr );
    delete nodSters;
    if ( nodUltim != nullptr )
        splay( nodUltim );
}


splayTree& splayTree::operator=( splayTree& tree2 ) {
    while ( nrNoduri > 0 )
        deletion( root->getVal() );
    nrNoduri = tree2.nrNoduri;
    if ( tree2.root != nullptr ) {
        nod* nodNou = new nod;
        root = nodNou;
        deepcopy( nodNou, tree2.root );
    }
    return *this;
}


void splayTree::deepcopy( nod* nodNou, nod* nodCopiat ) {
    *nodNou = nodCopiat;
    if ( nodCopiat->getFiu( 1 ) != nullptr ) {
        nod* nodNou1 = new nod;
        nodNou->setFiu( 1, nodNou1 );
        nodNou1->setTata( nodNou );
        deepcopy( nodNou1, nodCopiat->getFiu( 1 ) );
    }
    if ( nodCopiat->getFiu( 2 ) != nullptr ) {
        nod* nodNou2 = new nod;
        nodNou->setFiu( 2, nodNou2 );
        nodNou2->setTata( nodNou );
        deepcopy( nodNou2, nodCopiat->getFiu( 2 ) );
    }
}


splayTree::splayTree( splayTree& tree2 ) {
    *this = tree2;
}
