//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once

#include <string>
#include "../../player/Player.h"
namespace atlas::game::player {
    class NimGamePlayer: public Player<int,int>{
    public:
        virtual ~NimGamePlayer()=default;

    };
}
