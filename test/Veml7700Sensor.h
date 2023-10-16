#include "esphome.h"

class Veml7700Sensor : public PollingComponent, public Sensor
{
public:
    Veml7700Sensor() : PollingComponent(5000) {}

    void setup() override
    {
    }

    void update() override
    {
        publish_state(42.0);
    }
};
