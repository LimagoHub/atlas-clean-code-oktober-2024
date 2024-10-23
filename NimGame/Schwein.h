//
// Created by JoachimWagner on 23.10.2024.
//

#pragma once


#include <string>

class Schwein {

    std::string name_;
    int gewicht_;
    void setGewicht(int gewicht) {
        gewicht_ = gewicht;
    }
public:

    [[nodiscard]] const std::string &getName() const {
        return name_;
    }

    void setName(std::string_view name) {
        name_ = name;
    }

    [[nodiscard]] int getGewicht() const {
        return gewicht_;
    }

    void fuettern() {
        setGewicht(getGewicht() + 1);
    }
};
