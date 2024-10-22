//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once


#include "Player.h"
namespace atlas::game::player {
    template<class TURN, class BOARD>
    class AbstractPlayer : public Player<TURN,BOARD>{

    public:
        explicit AbstractPlayer(const std::string &name) : name(name) {}



        ~AbstractPlayer() override {

        }

        std::string getName() const override {
            return name;
        }
    private:
        std::string name;
    };


}
