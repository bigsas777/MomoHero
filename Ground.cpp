#include "Ground.hpp"

Ground::Ground(sf::Vector2u windowSize)
{
    if (!texture.loadFromFile("assets/ground.png"))
        std::cout << "Errore caricamento texture!" << std::endl;
    
    texture.setSmooth(true);

    // Sprite
    sprite.setTexture(texture);

    // Origine trasformazioni angolo basso sx
    sprite.setOrigin(0, 48);

    // Posizionamento ground
    sprite.setPosition(0, windowSize.y);
}

// Getter
sf::Sprite& Ground::getSprite()
{
    return sprite;
}

sf::Texture Ground::getTexture()
{
    return texture;
}

sf::FloatRect Ground::getHitbox()
{
    return sprite.getGlobalBounds();
}

sf::RectangleShape Ground::drawHitbox()
{
    sf::FloatRect hitbox = sprite.getLocalBounds();
    sf::RectangleShape rectangle(sf::Vector2f(hitbox.width, hitbox.height));
    rectangle.setOrigin(sprite.getOrigin());
    rectangle.setPosition(sprite.getPosition());
    rectangle.setRotation(sprite.getRotation());
    rectangle.setScale(sprite.getScale());
    rectangle.setFillColor(sf::Color::Transparent); // Rettangolo senza riempimento
    rectangle.setOutlineColor(sf::Color::Red); // Colore del bordo
    rectangle.setOutlineThickness(2.0f);

    return rectangle;
}