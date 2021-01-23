#include <SFML/Graphics.hpp>
#include<iostream>
#include"ball.h"
#include"block.h"
#include <time.h>
using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(710, 450), "football");
    app.setFramerateLimit(60);
    Texture t2;
    t2.loadFromFile("images/background.jpg");



    Sprite bgSprite;
    bgSprite.setTexture(t2);
    bgSprite.setTextureRect(IntRect(0, 0, app.getSize().x, app.getSize().y));


    Texture t1, t3, t4;
    t1.loadFromFile("images/block03.png");
    t3.loadFromFile("images/ball.png");
    t4.loadFromFile("images/paddle.png");

    

    /*ball* Ball = new ball();
    block* Block = new block();
    Ball->set(t3);
    Block->set(t1);

    */

    int diem = 0;
    int mang = 3;
    Sprite ball, paddle;

    Sprite block[1000];

    ball.setTexture(t3);
    ball.setPosition(Vector2f(335, 440));

    paddle.setTexture(t4);
    paddle.setOrigin((Vector2f)paddle.getTexture()->getSize() * 0.5f);
    paddle.setPosition(335, 440);


    int n = 0;
    for (int i = 1; i <= 14; i++)
        for (int j = 1; j <= 10; j++)
        {
            block[n].setTexture(t1);
            block[n].setPosition(i * 45, j * 20);
            n++;
        }

    float dx = 6, dy = 5;
    float x = 300, y = 300;
    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
        }
        x += dx;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 2, y + 2, 6, 6).intersects(block[i].getGlobalBounds()))
            {
                block[i].setPosition(-100, 0); dx = -dx; diem++;
            }

        y += dy;
        for (int i = 0; i < n; i++)
            if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
            {
                block[i].setPosition(-100, 0); dy = -dy; diem++;

            }
        if (x < 0 || x>700)  dx = -dx;
        if (y < 0)  dy = -dy;

        if (y >= 440) {
            mang--;
            cout << mang << endl;
            if (mang != 0) {
                paddle.setTexture(t4);
                paddle.setOrigin((Vector2f)paddle.getTexture()->getSize() * 0.5f);
                paddle.setPosition(335, 440);
                app.draw(paddle);
            }
            else {
                cout << "End game!!" << endl;
                cout << diem << endl;
                cout << mang << endl;
                app.close();
            }
            

            
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) paddle.move(6, 0);
        if (Keyboard::isKeyPressed(Keyboard::Left)) paddle.move(-6, 0);

        if (FloatRect(x, y, 12, 12).intersects(paddle.getGlobalBounds())) dy = -(rand() % 1 + 2);

        ball.setPosition(x, y);

        
        //Ball->Update();





        app.clear();
        app.draw(bgSprite);
        app.draw(ball);
        app.draw(paddle);
        for (int i = 0; i < n; i++)
        {
            app.draw(block[i]);
        }

        /*for (int i = 0; i < 150; i++)
        {
            Block->Draw(app);
        }
        Ball->Draw(app);*/
        app.display();
    }

    return 0;
}