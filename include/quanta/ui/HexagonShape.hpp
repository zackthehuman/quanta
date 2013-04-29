#ifndef QUANTA_HEXAGON_SHAPE
#define QUANTA_HEXAGON_SHAPE

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace quanta {

    class HexagonShape : public sf::Drawable, public sf::Transformable {
    private:
        static const unsigned char FACE_COUNT;    // how many faces this shape has
        static const unsigned char VERTEX_COUNT;  // how many verticies this shape has
        float faceLength;           // s
        float height;               // h
        float radius;               // r
        float boundingBoxWidth;     // a
        float boundingBoxHeight;    // b
        sf::VertexArray points;

        void calculateMetrics();
        void calculateVerticies();

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        HexagonShape(float faceLength, const sf::Color & color = sf::Color(128, 128, 128, 255));

        float getFaceLength() const;
        float getTriangleHeight() const;
        float getTriangleWidth() const;
        float getBoxHeight() const;
        float getBoxWidth() const;

        void setColor(const sf::Color & color);
        const sf::Color & getColor() const;
        
        virtual ~HexagonShape();
    };

} // quanta

#endif // QUANTA_HEXAGON_SHAPE