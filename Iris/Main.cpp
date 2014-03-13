#include <cstdlib>
#include <ctime>
#include <cstdio>
/*Iris

Uppbyggnad av kod - f�rslag av Peter


funktioner f�ljer designen som visas nedan.

int main(){
	//Kod h�r.
}

if(vilkor == 1 &&
	vilkor == 2 ||
	vilkor == 3){
}


variabelnamn b�rjar med liten bokstav sedan f�ljer "Camel case", medlemsvariabler b�rjar med bokstaven m.  

Klasser/Enums b�rjar med stor bokstav
Instanser av klasser hanteras som variabelnamn dvs b�rjar med liten bokstav.

Vad som kr�vs:
	Resurshanterare
	Save-hantering
	Basklass
	V�rldsklass
	Dekorators
	Simpel AI (kan ha en fungerande funktion f�r att f� den att g� mot spelaren).
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

