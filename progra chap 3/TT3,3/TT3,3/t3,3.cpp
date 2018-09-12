#include "Includes.h"

int main()
{
	string previous = " "; 
	string current; 
	while (cin >> current) { 
		if (previous == current) 
			cout << "palabra repetidas: " << current << '\n';
		previous = current; // She she laughed He He He because what he did did not look very very good good
		
	}
}

/*She
she
laughed
He
He
palabra repetidas: He
He
palabra repetidas: He
because
what
he
did
did
palabra repetidas: did
not
look
very
very
palabra repetidas: very
good
good
palabra repetidas: good

*/