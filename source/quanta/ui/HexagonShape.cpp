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
        calculateMetrics();
        calculateVerticies();
    }

    HexagonShape::~HexagonShape() {
        // dtor
    }

    void HexagonShape::calculateMetrics() {
        const float degree30 = 3.1415926548f / 6.0f;

        height = std::sin(degree30) * faceLength;
        radius = std::cos(degree30) * faceLength;
        boundingBoxWidth = 2 * radius;
        boundingBoxHeight = faceLength + (2 * height);
    }

    void HexagonShape::calculateVerticies() {
        points[0] = sf::Vertex(sf::Vector2f(radius, 0.0f), sf::Color::Cyan);
        points[1] = sf::Vertex(sf::Vector2f(boundingBoxWidth, height), sf::Color::Red);
        points[2] = sf::Vertex(sf::Vector2f(boundingBoxWidth, height + faceLength), sf::Color::Yellow);
        points[3] = sf::Vertex(sf::Vector2f(radius, boundingBoxHeight), sf::Color::Green);
        points[4] = sf::Vertex(sf::Vector2f(0.0f, height + faceLength), sf::Color::Blue);
        points[5] = sf::Vertex(sf::Vector2f(0.0f, height), sf::Color::Magenta);
        points[6] = sf::Vertex(sf::Vector2f(radius, 0.0f), sf::Color::White);
    }

    void HexagonShape::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        target.draw(points, states);
    }


    float HexagonShape::getFaceLength() const {
        return faceLength;
    }

    float HexagonShape::getTriangleHeight() const {
        return height;
    }

    float HexagonShape::getTriangleWidth() const {
        return radius;
    }

    float HexagonShape::getBoxHeight() const {
        return boundingBoxHeight;
    }

    float HexagonShape::getBoxWidth() const {
        return boundingBoxWidth;
    }

} // quanta