#include <iostream>
#include <vector>
using namespace std;

int main()
{
#ifdef __sgi
	cout << "__sgi" << endl;
#endif

#ifdef __GUNC__
	cout << "__GUNC__" << endl;
	cout << "__GUNC__"  << ' ' << __GUNC_MINOR__ << endl;
#endif
	return 0;
}