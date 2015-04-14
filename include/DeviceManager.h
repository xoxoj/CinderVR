#pragma once

#include <memory>

namespace CinderVR {
class DeviceManagerImpl;
enum class DeviceType;
class Device;

using DevicePtr = std::unique_ptr<Device>;

class DeviceManager
{
public:
    DeviceManager();
    virtual ~DeviceManager();
    DevicePtr create(const DeviceType deviceType);
private:
    std::unique_ptr<DeviceManagerImpl> impl;
};

};
