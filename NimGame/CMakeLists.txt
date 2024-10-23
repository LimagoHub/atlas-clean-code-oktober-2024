cmake_minimum_required(VERSION 3.28)
project(NimGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(NimGame main.cpp
        game/Game.h
        game/Game.h
        client/Client.h
        game/nimgame/NimGameImpl.h
        game/nimgame/NimGameImpl.h
        game/nimgame/player/NimGamePlayer.h
        game/nimgame/player/AbstractNimGamePlayer.h
        game/nimgame/player/HumanPlayer.h
        game/nimgame/player/ComputerPlayer.h
        io/Writer.h
        io/ConsoleWrite.h
        game/player/Player.h
        game/player/AbstractPlayer.h
        game/AbstractGame.h
        Schwein.h)
