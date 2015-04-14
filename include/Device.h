#pragma once

#include <memory>
#include <functional>

namespace CinderVR {

using RenderFunction = std::function<void(/* Possible some arguments */)>;

class Device
{
public:
    Device();
    virtual ~Device();
    
    // Move Constructor
    Device(const Device&& );
    // Move Assignment
    Device& operator=(const Device&&);
    
    void draw(RenderFunction);
    
private:
    // Ensure copy constructor does not exist.
    // C++11 standard defines that these will not exist,
    // but some compilers are less nice, so force compliance
    Device(const Device&) = delete;
    Device& operator=(const Device&) = delete;
};

using DevicePtr = std::unique_ptr<Device>;

};
