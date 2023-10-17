#include "esphome.h"
#include "Adafruit_VEML7700.h"

#define TAG "VEML7700"

class Veml7700Sensor : public PollingComponent, public Sensor
{
private:
    Adafruit_VEML7700 veml = Adafruit_VEML7700();
    bool ok;

public:
    Veml7700Sensor() : PollingComponent(5000)
    {
    }

    void setup() override
    {
        if (!veml.begin())
        {
            ESP_LOGE(TAG, "Failed to set up VEML7700");
            ok = false;
        }
        else
        {
            ok = true;
        }
    }

    void update() override
    {
        if (!ok)
            return;

        float lux = veml.readLux(VEML_LUX_AUTO);

        int gain = veml.getGain();
        int integrationTime = veml.getIntegrationTime();
        int white = veml.readWhite(false);

        ESP_LOGI(TAG, "Lux %f, white %d, gain %d, integration %d", lux, white, gain, integrationTime);
        publish_state(lux);
    }
};
