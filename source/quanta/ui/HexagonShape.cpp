#include "quanta/ui/HexagonShape.hpp"

#include <cmath>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace quanta {

    HexagonShape::HexagonShape(float faceLength)
        : sf::Drawable()
        , faceLength(faceLength)
        , points(sf::TrianglesFan, 7)
    {
        calculateVerticies();
    }

    HexagonShape::~HexagonShape() {
        // dtor
    }

    void HexagonShape::calculateVerticies() {
        const float angle = (2.0f * 3.1415926538f) / 6.0f;

        for(int i = 0; i < 7; ++i) {
            points[i] = sf::Vertex(sf::Vector2f(std::sin(angle * i) *  faceLength, std::cos(angle * i) * faceLength), sf::Color::Green);
        }
    }

    void HexagonShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(points, states);
    }

} // quanta