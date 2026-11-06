#pragma once
#include "raylib.h"
#include "world.hpp"

#include "string"
#include "iostream"

class entity{
    public:
        std::string name;
        Vector2 position;
        Vector2 size;
        Color colour;

        Rectangle sprite;

        //physics
        Vector2 velocity;

        entity(){
            records::entities.push_back(this);
            std::cout<<"Entity Created!!"<<std::endl;
        }

        ~entity() {
            auto it = std::find(records::entities.begin(), records::entities.end(), this);
            if (it != records::entities.end()) {
                records::entities.erase(it);
                std::cout << "Entity destroyed!!!"<<std::endl;
            }
        }

        void draw();
        void fly();
};

void entity::draw(){
    DrawRectangleV(position, size, colour);
}

void entity::fly(){
    if (IsKeyPressed(KEY_SPACE)){
        position.y -= 60;
    }
}
