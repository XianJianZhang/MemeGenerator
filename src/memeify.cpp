//
// Created by Xian Jian Zhang on 11/17/2021.
//

#include "memer.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char **argv) {
    if (argc > 1){
        memer meme;
        sf::Image memeImage;
        int periodIndex;
        std::string fileName = argv[1];
        if (argc == 3){
            sf::Image image;
            if (!image.loadFromFile(fileName)){
                std::cout << "Image did not load" << std::endl;
            }
            memeImage = meme.generateMeme(image, argv[2]);

        } else if (argc == 4){
            sf::Image image;
            if (!image.loadFromFile(fileName)){
                std::cout << "Image did not load" << std::endl;
            } else {
                memeImage = meme.generateMeme(image, argv[2], argv[3]);
            }

        } else if (argc == 5){
            sf::Image image;
            if (!image.loadFromFile(fileName)){
                std::cout << "Image did not load" << std::endl;
            } else {
                memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]));
            }

        } else if (argc == 6){
            sf::Image image;
            if (!image.loadFromFile(fileName)){
                std::cout << "Image did not load" << std::endl;
            } else {
                memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]), atoi(argv[5]));
            }
        } else if (argc == 7){
            sf::Image image;
            if (!image.loadFromFile(fileName)){
                std::cout << "Image did not load" << std::endl;
            } else {
                memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
            }
        } else if (argc == 8){
            sf::Image image;
            if (!image.loadFromFile(fileName)){
                std::cout << "Image did not load" << std::endl;
            } else {
                memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
            }
        }

        for (int x = 0; x < fileName.length(); x++){
            if (fileName.at(x) == '.'){
                periodIndex = x;
            }
        }

        std::string memeName = fileName.substr(0, periodIndex) + "-meme.jpg";
        memeImage.saveToFile(memeName);
    } else {
        std::cout << "Invalid input" << std::endl;
    }

    return 0;

}
