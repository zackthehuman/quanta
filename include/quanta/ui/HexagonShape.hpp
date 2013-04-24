#ifndef QUANTA_HEXAGON_SHAPE
#define QUANTA_HEXAGON_SHAPE

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>

namespace quanta {

    class HexagonShape : public sf::Drawable, public sf::Transformable {
    private:
        float faceLength;
        sf::VertexArray points;

        void calculateVerticies();

    protected:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    public:
        HexagonShape(float faceLength);
        virtual ~HexagonShape();
    };

} // quanta

#endif // QUANTA_HEXAGON_SHAPE