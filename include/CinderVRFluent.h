#pragma once

// An alternative interface that favors the fluent-style interface

namespace CinderVR
{
    class DeviceManager;
    enum class DeviceType;
    class Device;
    using DevicePtr = std::unique_ptr<Device>;

    namespace Fluent
    {
        class DeviceManager : private CinderVR::DeviceManager
        {
        public:
            DeviceManager() : CinderVR::DeviceManager() {}
            DeviceManager& withDeviceType(const CinderVR::DeviceType deviceType)
            {
                m_deviceType = deviceType;
                return *this;
            }

            DevicePtr create() {
                return CinderVR::DeviceManager::create(m_deviceType);
            }
        private:
            DeviceType m_deviceType;
        };
    }
}
