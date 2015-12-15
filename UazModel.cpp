#include <SFML/Graphics.hpp>
#include "UazModel.h"
#include "var.h"

void UazModel::init_car()
{
	Texture bodyCarTexture, carWheelTexture;
	bodyCarTexture.loadFromFile("images/body.png");
	carWheelTexture.loadFromFile("images/wheel.png");

	UazModel uaz;
	uaz.bodyCarSprite.setTexture(bodyCarTexture);
	uaz.leftWheel.setTexture(carWheelTexture);
	uaz.leftWheel.setOrigin(RADIUS_WHEEL, RADIUS_WHEEL);

	uaz.rightWheel.setTexture(carWheelTexture);
	uaz.rightWheel.setOrigin(RADIUS_WHEEL, RADIUS_WHEEL);
}

void UazModel::draw_objects(RenderWindow & window, UazModel & uaz, RectangleShape background)
{
	window.clear();
	window.draw(background);
	window.draw(uaz.bodyCarSprite);
	window.draw(uaz.leftWheel);
	window.draw(uaz.rightWheel);
	window.display();
}

void UazModel::counting_speed(Event event, float time)
{
	if (event.type == Event::KeyPressed && event.key.code == Keyboard::Right) {
		speed += acceleration * time;
	}
	else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Left) {
		speed -= acceleration * time;
	}
	else {
		if (speed > 0)
			speed -= (acceleration * time) / 2;
		if (speed < 0)
			speed += (acceleration * time) / 2;
	}
	counting_rotation(event, time);
}

void UazModel::counting_rotation(Event event, float time)
{
	carCoordinate.x += speed;
	rotation = carCoordinate.x * 360 / CIRCLE_LENGTH;
	set_car_position();
}

void UazModel::set_car_position()
{
	rightWheel.setRotation(rotation);
	rightWheel.setPosition(carCoordinate.x + RIGHT_WHEEL_X, carCoordinate.y + RIGHT_WHEEL_Y);

	leftWheel.setRotation(rotation);
	leftWheel.setPosition(carCoordinate.x + LEFT_WHEEL_X, carCoordinate.y + LEFT_WHEEL_Y);

	bodyCarSprite.setPosition(carCoordinate);
}
