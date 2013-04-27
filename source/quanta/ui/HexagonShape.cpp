#include "quanta/ui/HexagonShape.hpp"

#include <cmath>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace quanta {

    HexagonShape::HexagonShape(float faceLength, const sf::Color & color)
        : sf::Drawable()
        , faceLength(faceLength)
        , points(sf::TrianglesFan, 7)
    {
        calculateMetrics();
        calculateVerticies();
        setColor(color);
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
        points[0] = sf::Vertex(sf::Vector2f(radius, 0.0f));
        points[1] = sf::Vertex(sf::Vector2f(boundingBoxWidth, height));
        points[2] = sf::Vertex(sf::Vector2f(boundingBoxWidth, height + faceLength));
        points[3] = sf::Vertex(sf::Vector2f(radius, boundingBoxHeight));
        points[4] = sf::Vertex(sf::Vector2f(0.0f, height + faceLength));
        points[5] = sf::Vertex(sf::Vector2f(0.0f, height));
        points[6] = sf::Vertex(sf::Vector2f(radius, 0.0f));
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

    void HexagonShape::setColor(const sf::Color & color) {
        for(int i = 0; i < 7; ++i) {
            points[i].color = color;
        }
    }

    const sf::Color & HexagonShape::getColor() const {
        return points[0].color;
    }

} // quanta