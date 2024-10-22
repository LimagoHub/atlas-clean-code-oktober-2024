//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once

#include <iostream>
#include "Writer.h"

namespace atlas::io {
    class ConsoleWrite: public Writer {
    public:
        void write(std::string message) override {
            std::cout << message ;
        }
    };
}
