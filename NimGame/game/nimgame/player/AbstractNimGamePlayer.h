//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once
#include "NimGamePlayer.h"
namespace atlas::game::player {
    class AbstractNimGamePlayer : public NimGamePlayer{

    public:
        explicit AbstractNimGamePlayer(const std::string &name) : name(name) {}



        ~AbstractNimGamePlayer() override {

        }

        std::string getName() const override {
            return name;
        }
    private:
        std::string name;
    };


}
