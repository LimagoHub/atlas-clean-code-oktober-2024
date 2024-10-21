#include <iostream>
#include "game/nimgame/NimGameImpl.h"
#include "client/Client.h"



int main() {
    atlas::game::NimGameImpl game;
    client::Client client{game};
    client.go();
    return 0;
}
