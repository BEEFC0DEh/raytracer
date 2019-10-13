#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <algorithm>

template <typename DataT>
struct Vec3
{
    DataT x;
    DataT y;
    DataT z;

    explicit Vec3(DataT number): x{number}, y{number}, z{number} {}
    explicit Vec3(DataT nx = 0, DataT ny = 0, DataT nz = 0): x{nx}, y{ny}, z{nz} {}

    Vec3<DataT> cross(const Vec3<DataT>& other) const
    {
        return Vec3<DataT> {
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        };
    }

    DataT dot(const Vec3<DataT>& other)
    {
        return x * other.x + y * other.y + z * other.z;
    }
};

using Vec3f = Vec3<float>;

template <typename T>
constexpr const T& clamp(const T& value)
{
    return std::max( T{0.0}, std::min( value, T{1.0} ) );
}

class Framebuffer
{
public:
    explicit Framebuffer(std::size_t width = 0, std::size_t height = 0): m_data(width * height), m_width{width}, m_height{height} {}

    const std::vector<Vec3f>& data() const
    {
        return m_data;
    }

    std::vector<Vec3f>& data()
    {
        return m_data;
    }

    std::size_t width() const
    {
        return m_width;
    }

    std::size_t height() const
    {
        return m_height;
    }

private:
    std::vector<Vec3f> m_data;
    const std::size_t m_width;
    const std::size_t m_height;
};

#endif // STRUCTURES_H
