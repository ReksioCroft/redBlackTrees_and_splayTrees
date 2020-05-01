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
                nodCurent = static_cast<redBlackNode*>(nodCurent->getFiu( 1 ));
            else
                nodCurent = static_cast<redBlackNode*>(nodCurent->getFiu( 2 ));
        }
        if ( nodNou->getVal() < nodNou->getTata()->getVal() )
            nodNou->getTata()->setFiu( 1, nodNou );
        else
            nodNou->getTata()->setFiu( 2, nodNou );
        redBlackInsertionFix( nodNou );
    }

}


void redBlackTree::redBlackInsertionFix( redBlackNode* nodCurent ) {
    while ( nodCurent->getCuloare() == 'R' && ( nodCurent->getTata()->getCuloare() ) == 'R' ) {
        ///intrucat radacina e mereu neagra, suntem siguri ca avem bunic
        if ( nodCurent->getTata()->getTata()->getFiu( 1 ) == nodCurent->getTata() ) {
            ///daca tatal meu a fost un fiu stang
            redBlackNode* nodUnchi = nodCurent->getTata()->getTata()->getFiu( 2 );
            if ( nodUnchi->getCuloare() == 'R' ) {
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
            if ( nodUnchi->getCuloare() == 'R' ) {
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


void redBlackTree::deletion( int nr ) {
    redBlackNode* nodUltim;
    redBlackNode* nodSters;
    abstractTree::deletion( root, nodSters, nodUltim, nr );
    if ( nodSters->getCuloare() == 'B' )
        redBlackDeletionFix( nodUltim );
    delete nodSters;
}


void redBlackTree::redBlackDeletionFix( redBlackNode* nodCurent ) {
    try {
        while ( nodCurent != root && nodCurent->getCuloare() == 'B' ) {
            if ( nodCurent->getTata()->getFiu( 1 ) == nodCurent ) {
                ///daca sunt un fiu stang
                redBlackNode* node = nodCurent->getTata()->getFiu( 2 );
                if ( node->getCuloare() == 'R' ) {
                    node->setCuloare( 'B' );
                    nodCurent->getTata()->setCuloare( 'R' );
                    rotateLeft( root, node );
                    node = nodCurent->getTata()->getFiu( 2 );
                }
                if ( node->getFiu( 1 )->getCuloare() == 'B' && node->getFiu( 2 )->getCuloare() == 'B' ) {
                    node->setCuloare( 'R' );
                    nodCurent = nodCurent->getTata();
                }
                else {
                    if ( node->getFiu( 2 )->getCuloare() == 'B' ) {
                        node->getFiu( 1 )->setCuloare( 'B' );
                        node->setCuloare( 'R' );
                        rotateRight( root, node->getFiu( 1 ) );
                        node = nodCurent->getTata()->getFiu( 2 );
                    }
                    node->setCuloare( nodCurent->getTata()->getCuloare() );
                    nodCurent->getTata()->setCuloare( 'B' );
                    node->getFiu( 2 )->setCuloare( 'B' );
                    rotateLeft( root, nodCurent->getTata()->getFiu( 2 ) );
                }
            }
            else {
                ///daca sunt un fiu drept
                redBlackNode* node = nodCurent->getTata()->getFiu( 1 );
                if ( node->getCuloare() == 'R' ) {
                    node->setCuloare( 'B' );
                    nodCurent->getTata()->setCuloare( 'R' );
                    rotateRight( root, node );
                    node = nodCurent->getTata()->getFiu( 1 );
                }
                if ( node->getFiu( 2 )->getCuloare() == 'B' && node->getFiu( 1 )->getCuloare() == 'B' ) {
                    node->setCuloare( 'R' );
                    nodCurent = nodCurent->getTata();
                }
                else {
                    if ( node->getFiu( 1 )->getCuloare() == 'B' ) {
                        node->getFiu( 2 )->setCuloare( 'B' );
                        node->setCuloare( 'R' );
                        rotateLeft( root, node->getFiu( 2 ) );
                        node = nodCurent->getTata()->getFiu( 1 );
                    }
                    node->setCuloare( nodCurent->getTata()->getCuloare() );
                    nodCurent->getTata()->setCuloare( 'B' );
                    node->getFiu( 1 )->setCuloare( 'B' );
                    rotateRight( root, nodCurent->getTata()->getFiu( 1 ) );
                }
            }
        }
        nodCurent->setCuloare( 'B' );
    }
    catch ( ... ) {
        std::cout << "Something happened:(\n";
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