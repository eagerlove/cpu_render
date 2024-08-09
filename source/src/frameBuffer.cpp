#include "frameBuffer.hpp"

namespace CPURender {
    FrameBuffer::FrameBuffer(size_t width, size_t height) : m_width(width), m_height(height){
        pixels.resize(width * height);
    }

    void FrameBuffer::save(const std::filesystem::path &filename) {
        
    }
}