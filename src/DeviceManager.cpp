#include "CinderVR.h"

#include <iostream>
#include <functional>
#include <map>

#include "cinder/app/App.h"

namespace CinderVR {

using FactoryFunction = std::function<DevicePtr()>;
using FactoryMapping = std::map<DeviceType, FactoryFunction>;

class DeviceManagerImpl {
    
public:
    DeviceManagerImpl()
    {
//        #ifdef OCULUS_ENABLED
        cinder::app::console() << "OculusSDK Enabled" << std::endl;
        m_mapping[DeviceType::OculusDK1] = []() -> DevicePtr {
            cinder::app::console() << "creating dk1" << std::endl;
            return DevicePtr(nullptr);
        };
        m_mapping[DeviceType::OculusDK2] = []() -> DevicePtr {
            cinder::app::console() << "created dk2" << std::endl;
            return DevicePtr(nullptr);
        };
//        #endif // OCULUS_ENABLED
    }
    
    virtual ~DeviceManagerImpl() = default;
    
    DevicePtr create(const DeviceType deviceType)
    {
        FactoryMapping::const_iterator factory = m_mapping.find(deviceType);
        if (factory == m_mapping.end())
        {
            return nullptr;
        }
        
        return factory->second();
    }
    
private:
    FactoryMapping m_mapping;
};


DeviceManager::DeviceManager()
: impl(new DeviceManagerImpl)
{
    
}

DeviceManager::~DeviceManager() = default;

DevicePtr DeviceManager::create(const DeviceType deviceType)
{
    return impl->create(deviceType);
}

}
