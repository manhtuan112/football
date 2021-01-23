#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include"block.h"
using namespace sf;
using namespace std;

class ball:public block
{
public:


	ball() {};

	void set(Texture texture) {
		s.setTexture(texture);
	}
	

	void Update() {
		x -= dx;
		y -= dy;
		for (int i = 0; i < n; i++)
			if (FloatRect(x + 2, y + 2, 6, 6).intersects(vt[i].getGlobalBounds()))
			{
				vt[i].setPosition(-300, 50); dx = -dx;
			}
		for (int i = 0; i < n; i++)
			if (FloatRect(x + 3, y + 3, 6, 6).intersects(vt[i].getGlobalBounds()))
			{
				vt[i].setPosition(-300, 50); dy = -dy;
			}
		if (x < 0 || x>700)  dx = -dx;
		if (y < 0|| y>400)  dy = -dy;
		s.setPosition(Vector2f(x, y));

	}

	void Draw(RenderWindow& rd)
	{
		
		rd.draw(s);
	}


private:
	Sprite s;
	float x = 335, dx = 6;
	float y = 225, dy = 5;
};

