#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "var.h"
#include "UazModel.h"

using namespace sf;
using namespace std;

void start_programm(RectangleShape background)
{

	background.setSize(Vector2f(WINDOW_SIZE.x, WINDOW_SIZE.y));
	background.setPosition(0, 0);
	background.setFillColor(Color::White);

}

void programRun(RenderWindow &window, Event &event)
{
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "UAZ Simulator");
	RectangleShape background;
	Clock clock;
	start_programm(background);
	while (window.isOpen())
	{
		sf::Event event;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / SPEED;
		programRun(window, event);
		uaz.counting_speed(event, time);
		window.clear();
		uaz.draw_objects(window, uaz, background);
		window.display();
	}
	return 0;
}
