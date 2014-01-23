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

