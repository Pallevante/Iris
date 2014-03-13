#include <cstdlib>
#include <ctime>
#include <cstdio>
/*Iris

Uppbyggnad av kod - förslag av Peter


funktioner följer designen som visas nedan.

int main(){
	//Kod här.
}

if(vilkor == 1 &&
	vilkor == 2 ||
	vilkor == 3){
}


variabelnamn börjar med liten bokstav sedan följer "Camel case", medlemsvariabler börjar med bokstaven m.  

Klasser/Enums börjar med stor bokstav
Instanser av klasser hanteras som variabelnamn dvs börjar med liten bokstav.

Vad som krävs:
	Resurshanterare
	Save-hantering
	Basklass
	Världsklass
	Dekorators
	Simpel AI (kan ha en fungerande funktion för att få den att gå mot spelaren).
	Kollisionshantering (Samma som vi fick av micke?)
*/

#include "World.hpp"

int main()
{
	srand(time(NULL));
	World world;
	world.run();
	return 0;
}

