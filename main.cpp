#include <fstream>
#include "splayTree.h"


int main() {
    std::ifstream fin( "abce.in" );
    std::ofstream fout( "abce.out" );
    int nr, test, x, y, i;
    splayTree tree;
    fin >> nr;
    for ( i = 0; i < nr; i++ ) {
        fin >> test >> x;
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
        else {
            fin >> y;
            tree.printInterval( fout, x, y );
        }


    }
    fin.close();
    fout.close();
    return 0;
}
