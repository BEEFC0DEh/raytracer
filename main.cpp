#include <fstream>
#include "structures.h"

void writeToFile(const Framebuffer& framebuffer)
{
    const auto width  {framebuffer.width()};
    const auto height {framebuffer.height()};

    const unsigned int PPM_MAX_VALUE {255};

    std::ofstream ofs; // save the framebuffer to file
    ofs.open("./out.ppm");
    ofs << "P6\n" << width << " " << height << "\n" << PPM_MAX_VALUE << "\n";
    for (size_t i = 0; i < height * width; ++i) {
        const auto writeByte = [&ofs](auto value) {
            ofs.put( PPM_MAX_VALUE * clamp(value) );
        };
        writeByte(framebuffer.data()[i].x);
        writeByte(framebuffer.data()[i].y);
        writeByte(framebuffer.data()[i].z);
    }
    ofs.close();
}

void render(Framebuffer& framebuffer)
{
    const auto width  {framebuffer.width()};
    const auto height {framebuffer.height()};

    for (size_t j = 0; j < height; j++) {
        for (size_t i = 0; i < width; i++) {
            framebuffer.data()[i + j * width] = Vec3f(j / float(height), i / float(width), 0);
        }
    }
}

int main()
{
    Framebuffer framebuffer(1920, 1080);
    render(framebuffer);
    writeToFile(framebuffer);
    return 0;
}
