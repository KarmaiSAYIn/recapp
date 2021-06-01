#include "CoordinateTransformer.h"
#include "Vec.h"

class Camera final
{
public:
    Camera(CoordinateTransformer& transformer);

    Vec2 GetPos() const;
    void SetPos(Vec2 pos);
    float GetScale() const;
    void SetScale(float scale);
    void Translate(Vec2 offset);
    void DrawClosedPolyline(std::vector<Vec2> vertices, Color c);

private:
    float scale = 1.0f;
    Vec2 pos = {0.0f, 0.0f};
    CoordinateTransformer& transformer;
};
