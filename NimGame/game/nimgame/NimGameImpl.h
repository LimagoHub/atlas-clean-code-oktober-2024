//
// Created by JoachimWagner on 21.10.2024.
//

#pragma once
#include <vector>
#include "../AbstractGame.h"
#include "player/NimGamePlayer.h"
#include "../../io/Writer.h"

namespace atlas::game {
    class NimGameImpl: public AbstractGame<int,int>{

    public:
        explicit NimGameImpl(io::Writer &writer) : AbstractGame(writer) {
            setBoard(23);
        }

        // --------------- Implemetierungssumpf (sehr spezifisch)
    protected:

        void prepare() override {
            print(getCurrentPlayer()->getName() + " ist am Zug!\n");
        }

        void updateBoard() override{ setBoard(getBoard() - getTurn());}

        bool isGameover() const override{
            return getBoard() < 1 || getPlayers().empty();
        }

        bool isTurnValid() const override{ return getTurn() >= 1 && getTurn() <= 3; }
    };

}
