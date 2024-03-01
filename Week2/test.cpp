#include <iostream>
using namespace std ;
class Table {
    char *p ;
    int sz ;
public:
    Table(int s=15) {
        p = new char[100] ;
        cout << "constructor" << endl ;
    }
    ~Table() { delete[] p ;
        cout << "destructor" << endl ;
    }
};

int main() {
    Table *t1 = new Table(20);
    Table *t2 = t1 ;
    // Table t3 ;
    // t3 = t2 ;

    delete t1;
    delete t2;
    return 0;
}
