#ifndef LINE_H
#define LINE_H

#include <string>

class Line {
private:
    std::string lineName;

public:
    // Constructor
    Line(std::string name);

    // Getter for line name
    std::string getLineName() const;
};

#endif // LINE_H
