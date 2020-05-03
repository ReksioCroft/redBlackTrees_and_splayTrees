#include <fstream>
#include "splayTree.h"
#include "redBlackTree.h"


int main() {
    std::ifstream fin( "abce.in" );
    std::ofstream fout( "abce.out" );
    int nr, test, x, y, i;
    redBlackTree tree;
    fin >> nr;
    for ( i = 0; i < nr; i++ ) {
        fin >> test;
        if ( test == 1 )
            fin >> tree;
        else if ( test < 7 )
            fin >> x;
        if ( test == 2 )
            tree.deletion( x );
        else if ( test == 3 )
            fout << tree.find( x ) << "\n";
        else if ( test == 4 )
            fout << tree.lowerBound( tree.getRoot(), x ) << "\n";
        else if ( test == 5 )
            fout << tree.upperBound( tree.getRoot(), x ) << "\n";
        else if ( test == 6 ) {
            fin >> y;
            tree.printInterval( tree.getRoot(), fout, x, y );
        }
        //  else if ( test == 7 )
        //   fout << tree.getNrNoduri() << "\n";
        //else
        //  fout << tree.blackHigh() << '\n';
    }
    std::cout << tree;
    redBlackTree tree1( tree );
    std::cout << tree1;
    while ( tree.getNrNoduri() > 0 )
        tree.deletion( tree.getRoot()->getVal() );
    std::cout << tree1;
    std::cout << tree;
    redBlackTree tree2;
    tree2 = tree1;
    std::cout << tree2;
    fin.close();
    fout.close();
    return 0;
}
