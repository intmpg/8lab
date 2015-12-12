#include <SFML/Graphics.hpp>
#include <iostream> 
#include <windows.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "var.h"
#include "UazModel.h"

using namespace sf;
using namespace std;

void draw_objects(RenderWindow &window, UazModel &uaz, RectangleShape background)
{
	window.clear();
	window.draw(background);
	window.draw(uaz.bodyCarSprite);
	window.draw(uaz.leftWheel);
	window.draw(uaz.rightWheel);
	window.display();
}

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
		draw_objects(window, uaz, background);
	}
}

int main(){

	sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE.x, WINDOW_SIZE.y), "UAZ Simulator");

	Texture bodyCarTexture, carWheelTexture;
	bodyCarTexture.loadFromFile("images/body.png");
	carWheelTexture.loadFromFile("images/wheel.png");

	UazModel uaz;
	uaz.bodyCarSprite.setTexture(bodyCarTexture);

	uaz.leftWheel.setTexture(carWheelTexture);
	uaz.leftWheel.setOrigin(RADIUS_WHEEL, RADIUS_WHEEL);

	uaz.rightWheel.setTexture(carWheelTexture);
	uaz.rightWheel.setOrigin(RADIUS_WHEEL, RADIUS_WHEEL);

	RectangleShape background;

	start_programm(window, uaz, background);
	return 0;
}
