#include "Menu.hpp"

class MainMenu : public Menu{
public:
	enum mMenuItems{ 
		PLAY, 
		QUIT, 
		NUM_CHOICES };
	MainMenu();
	~MainMenu();

	void drawMenu(sf::RenderWindow& window);
	
	int getCurrentMenuItem();
	int getMaxItems();
	void setCurrentMenuItem(unsigned int i);
	

private:
	std::vector<sf::Sprite*> mButtonVector;
	sf::Sprite mActiveButton;
	sf::Sprite mBackground;
	int mCurrentMenuItem;
};