//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once
#include <vector>
#include "Game.h"
#include "player/Player.h"
#include "../io/Writer.h"

namespace atlas::game{
    template< class BOARD, class TURN>
    class AbstractGame :public Game{
        using PLAYER = atlas::game::player::Player<BOARD,TURN>;
    public:
        explicit AbstractGame(io::Writer &writer) : writer(writer) {}

        void play() override {
            while( ! isGameover()) {
                playRound();
            }
        }

        void addPlayer(PLAYER * player) {
            //player.setWriter(writer);
            players.push_back(player);
        }

        void removePlayer(PLAYER * player){
            // TODO implement
        }
    private:


        void playRound() {
            for (auto &player :players) {
                setCurrentPlayer(player);
                playSingleTurn();
            }
        }

        void playSingleTurn() {
            if(initTurnFails()) return;
            executeTurn();
            terminateTurn();
        }



        bool initTurnFails(){
            if(isGameover()) return true;
            prepare();
            return false;
        }

        void executeTurn()  {
            do {
                turn = getCurrentPlayer()->doTurn(board);
            }  while(playersTurnIsInvalid());
        }
        void terminateTurn() { // Integration
            updateBoard();
            printGameOverMessageWhenGameIsOver();
        }


        bool playersTurnIsInvalid()  {
            if(isTurnValid()) return false;
            print("Ungueltiger Zug!");
            return true;
        }



        void printGameOverMessageWhenGameIsOver() { // Operation
            if(isGameover()) {
                print( currentPlayer->getName() + " hat verloren!\n");
            }
        }

        void setCurrentPlayer(PLAYER *currentPlayer) {
            AbstractGame::currentPlayer = currentPlayer;
        }

        std::vector<PLAYER *> players;

        PLAYER * currentPlayer;

        atlas::io::Writer & writer;

        BOARD board;
        TURN turn;
    protected:


        BOARD getBoard() const {
            return board;
        }

        void setBoard(BOARD board) {
            AbstractGame::board = board;
        }

        TURN getTurn() const {
            return turn;
        }

        void setTurn(TURN turn) {
            AbstractGame::turn = turn;
        }

    protected:

        virtual void prepare() {
            // OK
            // NOP
        }

        PLAYER *getCurrentPlayer() const {
            return currentPlayer;
        }




        const std::vector<PLAYER *> &getPlayers() const {
            return players;
        }



        virtual void print(std::string message) {
            writer.write(message);
        }
        virtual void updateBoard() = 0;

        virtual bool isGameover() const  = 0;

        virtual bool isTurnValid() const = 0;
    };
}
