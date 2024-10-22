#include <iostream>
#include "io/ConsoleWrite.h"
#include "game/nimgame/player/HumanPlayer.h"
#include "game/nimgame/player/ComputerPlayer.h"
#include "game/nimgame/NimGameImpl.h"
#include "client/Client.h"



int main() {
    atlas::io::ConsoleWrite writer;
    atlas::game::player::HumanPlayer mensch{"Fritz"};
    atlas::game::player::ComputerPlayer computer{"HAL"};

    atlas::game::NimGameImpl game{writer};
    game.addPlayer(&mensch);
    game.addPlayer(&computer);
    client::Client client{game};
    client.go();
    return 0;
}
