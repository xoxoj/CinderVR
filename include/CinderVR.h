#pragma once

#include <memory>
#include <functional>

namespace CinderVR {

    enum class VRDeviceType
    {
        OculusDK1,
        OculusDK2
    };

    using RenderFunction = std::function<void(/* whatever is needed to target the individual frames */)>;

    class VRDevice
    {
        VRDevice(const VRDevice&& ); // Move ctor
        void draw(RenderFunction);

    private:
        // Ensure copy constructor does not exist.
        VRDevice(const VRDevice&) = delete;
        VRDevice& operator=(const VRDevice&) = delete;
    };

    using VRDevicePtr = std::unique_ptr<VRDevice>;

    class VRDeviceManager
    {
    public:
        VRDevicePtr create(const VRDeviceType deviceType);
    };
}
