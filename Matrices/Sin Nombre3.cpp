#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
int n, i, j;
do {
cout << "Introduce un entero entre 1 y 20: ";
cin >> n;
} while ( n < 0 || n > 20 );
for(i=1; i<=n; i++) {
for (j=1; j<=n-i; j++) cout << " ";
for (j=1; j<=2*i-1; j++) cout << "*";
cout << endl;
}

return 0;
}
