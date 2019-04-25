// Vec2 definition
struct Vec2
{
// ...
Vec2 & operator +=( Vec2 const & v);
Vec2 & operator -=( Vec2 const & v);
Vec2 & operator *=( float s);
Vec2 & operator /=( float s);
// ...
};

Fügen Sie ihre Dateien und Änderungen zu git hinzu:

git add source / vec2 .hpp source / vec2 .cpp
git commit -m "Add Vec2 definition "
git add source / tests .cpp source / CMakeLists .txt
git commit -m "Add tests for Vec2
[