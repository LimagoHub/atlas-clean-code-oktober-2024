//
// Created by JoachimWagner on 21.10.2024.
//

#pragma once
#include "../Game.h"
namespace atlas::game {
    class NimGameImpl: public Game{
    public:
        NimGameImpl():stones(23) {}

        void play() override {
            while( ! isGameover()) {
                playRound();
            }
        }

    private:
        int stones;

        void playRound() {
            humanturn();
            computerturn();
        }

        void humanturn() {
            int turn;
            while(true) {
                std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3!" << std::endl;
                std::cin >> turn;
                if(turn >= 1 && turn <= 3) break;
                std::cout << " Ungueltiger Zug" << std::endl;
            }
            stones -= turn;
        }

        void computerturn() {
            const int turns[] = {3,1,1,2};

            if(isGameover()) {
                std::cout << "Du Loser" << std::endl;
                return;
            }

            if(stones == 1) {
                std::cout << "Du hast nur Glueck gehabt" << std::endl;
                stones -= 1;
                return;
            }
            const int turn = turns[stones % 4];
            std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
            stones -= turn;
        }

        bool isGameover() {
            return stones < 1;
        }
    };

}
