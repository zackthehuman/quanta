#include "quanta/ui/HexagonShape.hpp"

#include <cmath>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

namespace quanta {

    const unsigned char HexagonShape::FACE_COUNT = 6;
    const unsigned char HexagonShape::VERTEX_COUNT = FACE_COUNT + 2;

    HexagonShape::HexagonShape(float faceLength, const sf::Color & color)
        : sf::Drawable()
        , faceLength(faceLength)
        , points(sf::TrianglesFan, VERTEX_COUNT)
    {
        calculateMetrics();
        calculateVerticies();
        setColor(color);
    }

    HexagonShape::~HexagonShape() {
        // dtor
    }

    void HexagonShape::calculateMetrics() {
        const float degree30 = 3.1415926548f / static_cast<float>(FACE_COUNT);

        height = std::sin(degree30) * faceLength;
        radius = std::cos(degree30) * faceLength;
        boundingBoxWidth = 2 * radius;
        boundingBoxHeight = faceLength + (2 * height);
    }

    void HexagonShape::calculateVerticies() {
        // This configuration assumes that points[0] is the central vertex and
        // the other verticies encircle the central vertex.
        points[0] = sf::Vertex(sf::Vector2f(boundingBoxWidth / 2.0f, boundingBoxHeight / 2.0f));
        points[1] = sf::Vertex(sf::Vector2f(radius,                  0.0f));
        points[2] = sf::Vertex(sf::Vector2f(boundingBoxWidth,        height));
        points[3] = sf::Vertex(sf::Vector2f(boundingBoxWidth,        height + faceLength));
        points[4] = sf::Vertex(sf::Vector2f(radius,                  boundingBoxHeight));
        points[5] = sf::Vertex(sf::Vector2f(0.0f,                    height + faceLength));
        points[6] = sf::Vertex(sf::Vector2f(0.0f,                    height));
        points[7] = sf::Vertex(points[1]); // Complete the convex shape.

        setOrigin(points[0].position);
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
        for(unsigned char i = 0; i < VERTEX_COUNT; ++i) {
            points[i].color = color;
        }
    }

    const sf::Color & HexagonShape::getColor() const {
        return points[0].color;
    }

} // quanta