//
// Created by JoachimWagner on 22.10.2024.
//

#pragma once

#include <string>

namespace atlas::io {
    class Writer {
    public:
        virtual ~Writer() = default;
        virtual void write(std::string message)= 0;
    };
}
