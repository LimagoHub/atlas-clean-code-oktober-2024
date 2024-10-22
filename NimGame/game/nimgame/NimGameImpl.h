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
        int turn;


        void playRound() {
            humanturn();
            computerturn();
        }

        void humanturn() {
            if(isGameover()) return;
            executeTurn();
            terminateTurn( "Player");
        }



        void executeTurn()  {
            do {
                concreteHumanTurn();
            }  while(playersTurnIsInvalid());
        }

        bool playersTurnIsInvalid()  {
            if(isTurnValid()) return false;
            std::cout << "Ungueltiger Zug!" << std::endl;
            return true;
        }

        void concreteHumanTurn() {
            std::cout << "Es gibt " << stones << " Steine. Bitte nehmen Sie 1, 2 oder 3!" << std::endl;
            std::cin >> turn;
        }

        void computerturn() {
            if(isGameover()) return;
            const int turns[] = {3,1,1,2};

            turn = turns[stones % 4];
            std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
            terminateTurn("Computer");
        }

        void terminateTurn(std::string playername) { // Integration
            updateBoard();
            printGameOverMessageWhenGameIsOver(playername);
        }

        void printGameOverMessageWhenGameIsOver(const std::string &playername) { // Operation
            if(isGameover()) {
                std::cout << playername << " hat verloren!" << std::endl;
            }
        }


        // --------------- Implemetierungssumpf (sehr spezifisch)
        void updateBoard() { stones -= turn; }

        bool isGameover() {
            return stones < 1;
        }

        bool isTurnValid() const { return turn >= 1 && turn <= 3; }
    };

}
