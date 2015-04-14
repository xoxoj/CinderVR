#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "CinderVR.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicOculusApp : public App {
public:
    void setup() override;
    void mouseDown( MouseEvent event ) override;
    void update() override;
    void draw() override;
    
private:
    DeviceManager deviceManager;
};

void BasicOculusApp::setup()
{
    auto device = deviceManager.create(DeviceType::OculusDK1);
}

void BasicOculusApp::mouseDown( MouseEvent event )
{
}

void BasicOculusApp::update()
{
}

void BasicOculusApp::draw()
{
    gl::clear( Color( 0, 0, 0 ) );
}

CINDER_APP( BasicOculusApp, RendererGl )
