//
// Created by Xian Jian Zhang on 12/28/2021.
//

#include "memer.h"

sf::Image memer::generateMeme(sf::Image base, sf::String topText, sf::String bottomText,
                              int topX, int topY, int bottomX, int bottomY) {
    sf::Texture texture;
    texture.loadFromImage(base);
    sf::Sprite sprite = sf::Sprite(texture);
    sf::RenderTexture canvas;
    int width = base.getSize().x;
    int height = base.getSize().y;
    if (!canvas.create(width, height)){
        std::cout << "canvas not loaded!" << std::endl;
    }
    canvas.draw(sprite);
    sf::Font font;
    font.loadFromFile("Cave-Story.ttf");
    sf::Text top = sf::Text(topText, font);
    sf::Text bottom = sf::Text(bottomText, font);
    top.setOrigin(0, 0);
    bottom.setOrigin(0, 0);
    if (topX ==-1)
        topX = width/2 - 2*top.getCharacterSize();
    if (topY == -1)
        topY = height/3 - 10;
    top.setPosition(topX, topY);

    if (bottomX ==-1)
        bottomX = width/2 - 2*top.getCharacterSize();
    if (bottomY == -1)
        bottomY = height - height/3 + 10;
    bottom.setPosition(bottomX, bottomY);

    canvas.draw(top);
    canvas.draw(bottom);
    canvas.display();

    //Creating the window
    sf::RenderWindow window(sf::VideoMode(base.getSize().x, base.getSize().y), "Meme Generator");
    //Extracting image from the RenderTexture instance
    sf::Texture newTexture = sf::Texture(canvas.getTexture());
    sf::Image memeImage = newTexture.copyToImage();
    sf::Sprite memeSprite = sf::Sprite(newTexture);
    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(memeSprite);
        window.display();
    }
    return memeImage;
}

