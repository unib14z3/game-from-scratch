#include "raylib.h"
#include <iostream>
#include <vector>
#include "algorithm"

class entity;

namespace {
    std::vector<entity*> entities;
}

 namespace WorldPhysics{

    void addGravity();
};



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
            entities.push_back(this);
            std::cout<<"Entity Created!!"<<std::endl;
        }

        ~entity() {
            auto it = std::find(entities.begin(), entities.end(), this);
            if (it != entities.end()) {
                entities.erase(it);
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
/////
void WorldPhysics::addGravity(){
    for(auto& e : entities){
        e->position.y +=10;
    }
}

void initWindow(){
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Raylib + C++");

    SetTargetFPS(60);
}

int main(){

    entity bird;
    Vector2 spawpos = {300, 280};
    Vector2 size = {50, 50};
    Color color = RED;

    bird.colour = color;
    bird.size = size;
    bird.position = spawpos;


    initWindow();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        bird.draw();
        bird.fly();
        WorldPhysics::addGravity();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
