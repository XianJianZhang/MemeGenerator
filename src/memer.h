//
// Created by Xian Jian Zhang on 11/17/2021.
//

#ifndef LAB10_MEMER_H
#define LAB10_MEMER_H
#include <SFML/Graphics.hpp>
#include <iostream>
class memer {
public:
    sf::Image generateMeme(sf::Image base, sf::String topText, sf::String bottomText = "",
                           int topX = -1, int topY = -1, int bottomX = -1, int bottomY = -1);
};


#endif //LAB10_MEMER_H
