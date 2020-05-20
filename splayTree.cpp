///https://en.wikipedia.org/wiki/Splay_tree
///http://www.btechsmartclass.com/data_structures/splay-trees.html
///https://www.youtube.com/watch?v=IBY4NtxmGg8
#include "splayTree.h"


int splayTree::nrInstanteCurente = 0;


splayTree::splayTree() : abstractTree() {
    nrInstanteCurente++;
    root = nullptr;
}


splayTree *splayTree::getInstance() {
    if ( nrInstanteCurente == abstractTree::getNrInstante() ) {
        splayTree *tree = new splayTree;
        return tree;
    }
    else
        return nullptr;
}


splayTree::splayTree( const splayTree &tree2 ) : abstractTree( isOkToCallBaseConstructor( tree2 ) ) {
    nrInstanteCurente++;
    if ( tree2.root != nullptr ) {
        nod *nodNou = new nod( *tree2.root );
        root = nodNou;
        deepcopy( nodNou, tree2.root );
    }
    else
        root = nullptr;
}


const splayTree &splayTree::isOkToCallBaseConstructor( const splayTree &tree2 ) {
    if ( nrInstanteCurente != abstractTree::getNrInstante() )
        throw std::bad_function_call();
    return tree2;
}


splayTree &splayTree::operator=( splayTree tree2 ) {
    nod *aux = root;
    root = tree2.root;
    tree2.root = aux;

    nrNoduri += tree2.nrNoduri;
    tree2.nrNoduri = nrNoduri - tree2.nrNoduri;
    nrNoduri -= tree2.nrNoduri;
    tree2.clear();

    return *this;
}


splayTree::~splayTree() {
    nrInstanteCurente--;
    clear();
}


void splayTree::insert( int nr ) {
    nod *nodNou = new nod( nr );
    if ( root == nullptr ) {
        root = nodNou;
    }
    else {
        splayInsert( nodNou );
        splay( nodNou );
    }
    nrNoduri++;
}


void splayTree::splayInsert( nod *nodNou ) const {
    nod *nodCurent = root;
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


nod *splayTree::getRoot() {
    return root;
}


void splayTree::splay( nod *nodCurent ) {
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
        nod *nodTata = nodCurent->getTata();
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
    nod *nodUltim;
    nod *nodCautat = findNodeByValue( root, nr, T, nodUltim );
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
    nod *nodSters;
    nod *nodUltim;
    int lastMove;
    abstractTree::deletion( root, nodSters, lastMove, nodUltim, nr );
    delete nodSters;
    if ( nodUltim != nullptr )
        splay( nodUltim );
}


void splayTree::deepcopy( nod *nodNou, nod *nodCopiat ) {
    if ( nodCopiat->getFiu( 1 ) != nullptr ) {
        nod *nodNou1 = new nod( *nodCopiat->getFiu( 1 ) );
        nodNou->setFiu( 1, nodNou1 );
        nodNou1->setTata( nodNou );
        deepcopy( nodNou1, nodCopiat->getFiu( 1 ) );
    }
    if ( nodCopiat->getFiu( 2 ) != nullptr ) {
        nod *nodNou2 = new nod( *nodCopiat->getFiu( 2 ) );
        nodNou->setFiu( 2, nodNou2 );
        nodNou2->setTata( nodNou );
        deepcopy( nodNou2, nodCopiat->getFiu( 2 ) );
    }
}


void splayTree::clear() {
    while ( nrNoduri > 0 )
        deletion( root->getVal() );
}


