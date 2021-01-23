#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
using namespace sf;
using namespace std;
class block
{
public:

    block() {};

     void set(Texture texture) {
        int m=0;
        for (int i = 1; i <= 15; i++)
            for (int j = 1; j <= 10; j++)
            {
                vt[m].setTexture(texture);
                vt[m].setPosition(i * 45, j * 20);
                m++;
            }
        this->n = m;
	}
     void Draw(RenderWindow& rd)
     {  
         rd.draw(vt[5]);
     }

protected:
    int n;
    Sprite vt[1000];

};

