//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once

#include <string>

namespace atlas::game::player {


    template<class BOARD, class TURN>
    class Player {
    public:
        virtual ~Player()=default;
        virtual TURN doTurn(const BOARD & board) const = 0;
        virtual std::string getName() const = 0;
    };
}
