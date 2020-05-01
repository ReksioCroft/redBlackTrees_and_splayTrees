#include "redBlackTree.h"


redBlackTree::redBlackTree() {
    root = nullptr;
}


void redBlackTree::insert( int nr ) {
    redBlackNode* nodNou = new redBlackNode( nr );
    if ( root == nullptr ) {
        nodNou->setCuloare( 'B' );
        root = nodNou;
    }
    else {
        redBlackNode* nodCurent = root;
        while ( nodCurent != nullptr ) {
            nodNou->setTata( nodCurent );
            if ( nodNou->getVal() < nodCurent->getVal() )
                nodCurent = nodCurent->getFiu( 1 );
            else
                nodCurent = nodCurent->getFiu( 2 );
        }
        if ( nodNou->getVal() < nodNou->getTata()->getVal() )
            nodNou->getTata()->setFiu( 1, nodNou );
        else
            nodNou->getTata()->setFiu( 2, nodNou );
        redBlackInsertionFix( nodNou );
    }

}


void redBlackTree::redBlackInsertionFix( redBlackNode* nodCurent ) {
    try {
        while ( nodCurent != nullptr && nodCurent->getTata() != nullptr &&
                nodCurent->getCuloare() == 'R' && nodCurent->getTata()->getCuloare() == 'R' ) {
            ///intrucat radacina e mereu neagra, suntem siguri ca avem bunic
            if ( nodCurent->getTata()->getTata()->getFiu( 1 ) == nodCurent->getTata() ) {
                ///daca tatal meu a fost un fiu stang
                redBlackNode* nodUnchi = nodCurent->getTata()->getTata()->getFiu( 2 );
                if ( nodUnchi != nullptr && nodUnchi->getCuloare() == 'R' ) {
                    nodCurent->getTata()->setCuloare( 'B' );
                    nodUnchi->setCuloare( 'B' );
                    nodCurent->getTata()->getTata()->setCuloare( 'R' );
                    nodCurent = nodCurent->getTata()->getTata();
                }
                else {
                    if ( nodCurent->getTata()->getFiu( 2 ) == nodCurent ) { ///daca sunt fiul drept al unui fiu stang
                        rotateLeft( root, nodCurent );
                        nodCurent = nodCurent->getFiu( 1 );
                    }
                    nodCurent->getTata()->setCuloare( 'B' );
                    nodCurent->getTata()->getTata()->setCuloare( 'R' );
                    rotateRight( root, nodCurent->getTata() );
                }
            }
            else {
                ///daca tatal meu a fost un fiu drept
                redBlackNode* nodUnchi = nodCurent->getTata()->getTata()->getFiu( 1 );
                if ( nodUnchi != nullptr && nodUnchi->getCuloare() == 'R' ) {
                    nodCurent->getTata()->setCuloare( 'B' );
                    nodUnchi->setCuloare( 'B' );
                    nodCurent->getTata()->getTata()->setCuloare( 'R' );
                    nodCurent = nodCurent->getTata()->getTata();
                }
                else {
                    if ( nodCurent->getTata()->getFiu( 1 ) == nodCurent ) { ///daca sunt fiul stang al unui fiu drept
                        rotateRight( root, nodCurent );
                        nodCurent = nodCurent->getFiu( 2 );
                    }
                    nodCurent->getTata()->setCuloare( 'B' );
                    nodCurent->getTata()->getTata()->setCuloare( 'R' );
                    rotateLeft( root, nodCurent->getTata() );
                }
            }
        }
        root->setCuloare( 'B' );
    }
    catch ( std::logic_error& e ) {
        std::cout << e.what() << "\n";
    }
}


void redBlackTree::deletion( int nr ) {
    redBlackNode* nodUltim;
    redBlackNode* nodSters;
    int lastMove;
    abstractTree::deletion( root, nodSters, lastMove, nodUltim, nr );
    if ( nodSters != nullptr && nodSters->getCuloare() == 'B' ) {
        int ok = 0;
        redBlackNode* nIL = new redBlackNode( -1 );
        nIL->setCuloare( 'B' );
        if ( nodUltim->getFiu( lastMove ) == nullptr ) {
            ok = 1;
            nodUltim->setFiu( lastMove, nIL );
            nIL->setTata( nodUltim );
        }
        redBlackDeletionFix( nodUltim->getFiu( lastMove ) );
        if ( ok == 1 ) {
            if ( nIL->getTata()->getFiu( 1 ) == nIL )
                nIL->getTata()->setFiu( 1, nullptr );
            else
                nIL->getTata()->setFiu( 2, nullptr );
            delete nIL;
        }
        delete nodSters;
    }

}


void redBlackTree::redBlackDeletionFix( redBlackNode* nodCurent ) {
    try {
        while ( nodCurent != root && nodCurent->getCuloare() == 'B' ) {
            if ( nodCurent->getTata()->getFiu( 1 ) == nodCurent ) {
                ///daca sunt un fiu stang
                redBlackNode* nodFrate = nodCurent->getTata()->getFiu( 2 );
                if ( nodFrate == nullptr )
                    nodCurent->setCuloare( 'R' );
                else {
                    if ( nodFrate->getCuloare() == 'R' ) {///implicit, tatal comun e negru
                        ///daca am un frate rosu, fac in asa fel incat sa am un frate negru =>tata rosu
                        nodFrate->setCuloare( 'B' );
                        nodCurent->getTata()->setCuloare( 'R' );
                        rotateLeft( root, nodFrate );
                        nodFrate = nodCurent->getTata()->getFiu( 2 );
                    }

                    if ( ( nodFrate->getFiu( 1 ) == nullptr || nodFrate->getFiu( 1 )->getCuloare() == 'B' ) &&
                         ( nodFrate->getFiu( 2 ) == nullptr || nodFrate->getFiu( 2 )->getCuloare() == 'B' ) ) {
                        ///fratele meu fiind sigur negru, daca nu are fii rosii, il fac rosu si am scapat
                        nodFrate->setCuloare( 'R' );
                        nodCurent->getTata()->setCuloare( 'B' );
                        nodCurent = nodCurent->getTata();
                    }
                    else {
                        if ( nodFrate->getFiu( 1 ) != nullptr && nodFrate->getFiu( 1 )->getCuloare() == 'R' ) {
                            nodFrate->getFiu( 1 )->setCuloare( 'B' );
                            nodFrate->setCuloare( 'R' );
                            rotateRight( root, nodFrate->getFiu( 1 ) );
                        }
                        nodFrate->setCuloare( nodCurent->getTata()->getCuloare() );
                        nodCurent->getTata()->setCuloare( 'B' );
                        if ( nodFrate->getFiu( 2 ) != nullptr )
                            nodFrate->getFiu( 2 )->setCuloare( 'B' );
                        rotateLeft( root, nodFrate );
                        nodCurent = root;
                    }

                }
            }
            else {
                ///daca sunt un fiu drept
                redBlackNode* nodFrate = nodCurent->getTata()->getFiu( 1 );
                if ( nodFrate == nullptr )
                    nodCurent->setCuloare( 'R' );
                else {
                    if ( nodFrate->getCuloare() == 'R' ) {///implicit, tatal comun e negru
                        ///daca am un frate rosu, fac in asa fel incat sa am un frate negru =>tata rosu
                        nodFrate->setCuloare( 'B' );
                        nodCurent->getTata()->setCuloare( 'R' );
                        rotateRight( root, nodFrate );
                        nodFrate = nodCurent->getTata()->getFiu( 1 );
                    }

                    if ( ( nodFrate->getFiu( 1 ) == nullptr || nodFrate->getFiu( 1 )->getCuloare() == 'B' ) &&
                         ( nodFrate->getFiu( 2 ) == nullptr || nodFrate->getFiu( 2 )->getCuloare() == 'B' ) ) {
                        ///fratele meu fiind sigur negru, daca nu are fii rosii, il fac rosu si am scapat
                        nodFrate->setCuloare( 'R' );
                        nodCurent->getTata()->setCuloare( 'B' );
                        nodCurent = nodCurent->getTata();
                    }
                    else {
                        if ( nodFrate->getFiu( 2 ) != nullptr && nodFrate->getFiu( 2 )->getCuloare() == 'R' ) {
                            nodFrate->getFiu( 2 )->setCuloare( 'B' );
                            nodFrate->setCuloare( 'R' );
                            rotateLeft( root, nodFrate->getFiu( 2 ) );
                        }
                        nodFrate->setCuloare( nodCurent->getTata()->getCuloare() );
                        nodCurent->getTata()->setCuloare( 'B' );
                        if ( nodFrate->getFiu( 1 ) != nullptr )
                            nodFrate->getFiu( 1 )->setCuloare( 'B' );
                        rotateRight( root, nodFrate );
                        nodCurent = root;
                    }
                }
            }
        }
        nodCurent->setCuloare( 'B' );
    }
    catch ( std::logic_error& e ) {
        std::cout << e.what() << '\n';
    }
}


bool redBlackTree::find( int nr ) {
    if ( root == nullptr )
        return false;
    redBlackNode* nodUltim;
    redBlackNode* lowerBound;
    redBlackNode* upperBound;
    redBlackNode* nodCautat = findNodeByValue( root, nr, nodUltim, lowerBound, upperBound );
    if ( nodCautat == nullptr )
        return false;
    else
        return true;

}


redBlackNode* redBlackTree::getRoot() {
    return root;
}


redBlackTree::~redBlackTree() {
    while ( nrNoduri > 0 )
        deletion( root->getVal() );
}