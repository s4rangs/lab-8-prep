// maybe something here...

#ifndef BASIC_TRANSFORM_H
#define BASIC_TRANSFORM_H

#include "vector_util.h"
#include <SFML/System/Vector2.hpp>

struct BasicTransform {
    // methods...
    BasicTransform(const sf::Vector2f& scale = {1.f, 1.f}, const sf::Vector2f& translation = {0.f, 0.f}) {

    this->scale = scale;
    this->translation = translation;
}
    sf::Vector2f applyPoint(const sf::Vector2f& p) const {
        return {
            p.x * scale.x + translation.x,
            p.y * scale.y + translation.y
        };
    }

    sf::Vector2f applyVector(const sf::Vector2f& p) const {
        return {
            p.x * scale.x,
            p.y * scale.y
        };
    }

    bool operator==(const BasicTransform& other) const {
        return scale == other.scale &&
            translation == other.translation;
    }

    sf::Vector2f scale;
    sf::Vector2f translation;

};

#endif