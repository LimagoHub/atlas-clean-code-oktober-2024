//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once

#include <string>

namespace atlas::game::player {
    class NimGamePlayer {
    public:
        virtual ~NimGamePlayer();
        virtual int doTurn(const int stones) const = 0;
        virtual std::string getName() const = 0;
    };
}
