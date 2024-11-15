#include "Line.h"
#include <stdexcept>

// Constructor with exception handling
Line::Line(std::string name) {
    if (name.empty()) {
        throw std::invalid_argument("Line name cannot be empty.");
    }
    lineName = name;
}

// Getter for line name
std::string Line::getLineName() const {
    if (lineName.empty()) {
        throw std::runtime_error("Line name is not set.");
    }
    return lineName;
}
