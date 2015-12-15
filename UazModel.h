#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct UazModel
{
	float acceleration = 0.0001;
	float rotation = 0;
	float speed = 0;

	Sprite bodyCarSprite;
	Sprite leftWheel;
	Sprite rightWheel;
	
	sf::Vector2f carCoordinate = { 0, 200 };

	void init_car();
	void draw_objects(RenderWindow &window, UazModel &uaz, RectangleShape background);
	void counting_speed(Event event, float time);
	void counting_rotation(Event event, float time);
	void set_car_position();

};