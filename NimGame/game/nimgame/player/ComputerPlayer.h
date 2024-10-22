//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once

#include <iostream>
#include "AbstractNimGamePlayer.h"
namespace atlas::game::player {

    class ComputerPlayer: public AbstractNimGamePlayer{
    public:

        explicit ComputerPlayer(const std::string &name) : AbstractNimGamePlayer(name) {}

        int doTurn(const int stones) const override {
            const int turns[] = {3,1,1,2};
            const int turn = turns[stones % 4];
            std::cout << "Computer nimmt " << turn << " Steine." << std::endl;
            return turn;
        }


    };
}
