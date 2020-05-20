#include <fstream>
#include "splayTree.h"
#include "redBlackTree.h"
#include <list>
#include <functional>


template < class treeType >
void abce( std::ifstream &fin, std::ofstream &fout, treeType *&tree ) {
    int test, x, y;
    fin >> test;
    if ( test == 1 )
        fin >> *tree;
    else if ( test < 7 )
        fin >> x;
    if ( test == 2 )
        tree->deletion( x );
    else if ( test == 3 )
        fout << tree->find( x ) << "\n";
    else if ( test == 4 )
        fout << tree->lowerBound( tree->getRoot(), x ) << "\n";
    else if ( test == 5 )
        fout << tree->upperBound( tree->getRoot(), x ) << "\n";
    else if ( test == 6 ) {
        fin >> y;
        tree->printInterval( tree->getRoot(), fout, x, y );
    }
    else if ( test == 7 )
        fout << tree->getNrNoduri() << "\n";
    //  else if ( test == 8 )
    //    fout << tree->blackHigh() << '\n';
}


template <>
void abce <redBlackTree>( std::ifstream &fin, std::ofstream &fout, redBlackTree *&tree ) {
    int test, x, y;
    fin >> test;
    if ( test == 1 )
        fin >> *tree;
    else if ( test < 7 )
        fin >> x;
    if ( test == 2 )
        tree->deletion( x );
    else if ( test == 3 )
        fout << tree->find( x ) << "\n";
    else if ( test == 4 )
        fout << tree->lowerBound( tree->getRoot(), x ) << "\n";
    else if ( test == 5 )
        fout << tree->upperBound( tree->getRoot(), x ) << "\n";
    else if ( test == 6 ) {
        fin >> y;
        tree->printInterval( tree->getRoot(), fout, x, y );
    }
    else if ( test == 7 )
        fout << tree->getNrNoduri() << "\n";
    else if ( test == 8 )
        fout << tree->blackHigh() << '\n';
}


template < class treeType, class treeType2 >
void solve() {
    std::cout << "Testul pentru " << typeid( treeType ).name() << '\n';
    std::ifstream fin( "abce.in" );
    std::ofstream fout( "abce.out" );
    std::list <treeType *> trees;
    treeType *tree = treeType::getInstance();
    trees.push_back( tree );
    try {
        int nr = 0;
        if ( fin.fail() )
            throw std::runtime_error( "Nu exista fisierul abce.in" );
        fin >> nr;
        for ( int i = 0; i < nr; i++ ) {
            abce( fin, fout, tree );
        }
    }
    catch ( std::runtime_error &e ) {
        std::cout << e.what() << '\n';
    }
    std::cout << *tree;
    //*tree = *tree;
    treeType tree1( *tree );
    //tree1 = tree1;
    std::cout << tree1;
    tree->clear();
    std::cout << tree1;
    std::cout << *tree;
    treeType *tree2 = treeType::getInstance();
    trees.push_back( tree2 );
    *tree2 = tree1;
    tree1.clear();
    std::cout << *tree2;
    try {
        treeType2 *s = treeType2::getInstance();
        if ( s != nullptr ) {
            treeType2 s2( *s );
            throw std::logic_error( "Design-Pattern incorrect implement" );
        }
        else
            throw std::bad_function_call();
    }
    catch ( std::logic_error &e ) {
        std::cout << e.what() << "\n";
    }
    catch ( std::bad_function_call &e ) {
        std::cout << e.what() << '\n';
    }
    while ( trees.empty() == false ) {
        delete *( trees.begin() );
        trees.pop_front();
    }
    std::cout << "\n";
    fin.close();
    fout.close();
}


int main() {
    solve <redBlackTree, splayTree>();
    solve <splayTree, redBlackTree>();
    return 0;
}
