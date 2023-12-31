#ifndef MOMO_HPP
#define MOMO_HPP
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

class Momo {
    public:
        Momo();
        void spawn(sf::Vector2u windowSize);
        void move(float xMove, float yMove);
        void rotate(char direction);
        sf::RectangleShape drawHitbox();
        void gravity();
        // Getter
        sf::Sprite& getSprite();
        sf::Texture getTexture();
        sf::FloatRect getHitbox();
        float getSpeed();
        // Setter
        void setSprite(sf::Sprite s);
        void setTexture(sf::Texture t);
    private:
        const float speed = 0.2f;
        const float rotateAngle = 0.1f;
        sf::Sprite sprite;
        sf::Texture texture;
};

#endif