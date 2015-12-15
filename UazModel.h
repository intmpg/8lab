#pragma once
#include <SFML/Graphics.hpp>
#include "var.h"

using namespace sf;
using namespace std;


struct UazModel
{
	Sprite bodyCarSprite;
	Sprite leftWheel;
	Sprite rightWheel;
	
	void init_car();
	void draw_objects(RenderWindow &window, UazModel &uaz, RectangleShape background);
	void counting_speed(Event event, float time);
	void counting_rotation(Event event, float time);
	void set_car_position();
};