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

        //If there's at least 3 arguments (argv, image, toptext), our basic first case can start! (minimum requirement)
        if (argc >= 3){
            sf::Image image;
            if (!image.loadFromFile(fileName)){
                std::cout << "Image did not load" << std::endl;
            }

            //If there's exactly 3 arguments
            if (argc == 3){
                memeImage = meme.generateMeme(image, argv[2]);

            //More than 3 arguments
            }   else {

                // If the fourth arguments is another text caption
                if (std::atoi(argv[3]) == 0){

                    //if there's nothing more after it
                    if (argc == 4){
                        memeImage = meme.generateMeme(image, argv[2], argv[3]);

                    //If there's more numbers, fill in parameters as needed, otherwise, print "Too many inputs"
                    } else {
                        if (argc == 5)
                            memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]));
                        else if (argc == 6)
                            memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]), atoi(argv[5]));
                        else if (argc == 7)
                            memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
                        else if (argc == 8)
                            memeImage = meme.generateMeme(image, argv[2], argv[3], atoi(argv[4]), atoi(argv[5]), atoi(argv[6]), atoi(argv[7]));
                        else {
                            std::cout << "Too many inputs!" << std::endl;
                        }
                    }

                //Otherwise if the fourth caption is another integer, fill in the respective arguments (same process)
                } else {
                    if (argc == 4)
                        memeImage = meme.generateMeme(image, argv[2], "", atoi(argv[3]));
                    if (argc == 5)
                        memeImage = meme.generateMeme(image, argv[2], "", atoi(argv[3]), atoi(argv[4]));
                    if (argc == 6)
                        memeImage = meme.generateMeme(image, argv[2], "", atoi(argv[3]), atoi(argv[4]), atoi(argv[5]));
                    if (argc == 7)
                        memeImage = meme.generateMeme(image, argv[2], "", atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6]));
                }
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
