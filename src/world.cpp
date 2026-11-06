#include "world.hpp"

void WorldPhysics::addGravity(){
    for(auto& e : records::entities){
        e->position.y +=10;
    }
}
