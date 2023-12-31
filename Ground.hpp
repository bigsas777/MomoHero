#ifndef GROUND_HPP
#define GROUND_HPP
#include <SFML/Graphics.hpp>
#include <iostream>

class Ground {
    public:
        Ground(sf::Vector2u windowSize);
        sf::RectangleShape drawHitbox();
        // Getter
        sf::Sprite& getSprite();
        sf::Texture getTexture();
        sf::FloatRect getHitbox();
    private:
        sf::Sprite sprite;
        sf::Texture texture;
};

#endif 