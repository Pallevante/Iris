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


#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

