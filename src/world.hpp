#pragma once
#include "entity.hpp"

#include "vector"

namespace records {
    std::vector<entity*> entities;
}

 namespace WorldPhysics{
    void addGravity();
};
