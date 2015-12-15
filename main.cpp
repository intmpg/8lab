#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "var.h"
#include "UazModel.h"

using namespace sf;
using namespace std;


void start_programm(RenderWindow &window, UazModel &uaz, RectangleShape background)
{
	Clock clock;

	background.setSize(Vector2f(WINDOW_SIZE.x, WINDOW_SIZE.y));
	background.setPosition(0, 0);
	background.setFillColor(Color::White);

	while (window.isOpen()) {
		sf::Event event;
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 600;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		uaz.counting_speed(event, time);
		uaz.draw_objects(window, uaz, background);
	}
}

int main(){

	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "UAZ Simulator");

	RectangleShape background;

	start_programm(window, uaz, background);
	return 0;
}
