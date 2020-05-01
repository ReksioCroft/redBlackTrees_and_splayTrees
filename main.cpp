#include <fstream>
#include "splayTree.h"


int main() {
    std::ifstream fin( "abce.in" );
    std::ofstream fout( "abce.out" );
    int nr, test, x, y, i;
    splayTree tree;
    fin >> nr;
    for ( i = 0; i < nr; i++ ) {
        fin >> test;
        if ( test != 7 )
            fin >> x;
        if ( test == 1 )
            tree.insert( x );
        else if ( test == 2 )
            tree.deletion( x );
        else if ( test == 3 )
            fout << tree.find( x ) << "\n";
        else if ( test == 4 )
            fout << tree.lowerBound( x ) << "\n";
        else if ( test == 5 )
            fout << tree.upperBound( x ) << "\n";
        else if ( test == 6 ) {
            fin >> y;
            tree.printInterval( fout, x, y );
        }
        else
            fout << tree.getNrNoduri() << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}
