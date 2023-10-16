import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.const import CONF_ID

MULTI_CONF = True
AUTO_LOAD = ["sensor"]

veml7700_ns = cg.esphome_ns.namespace("veml7700")
Veml7700Component = veml7700_ns.class("Veml7700Component", cg.PollingComponent)

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(Veml7700Component),
    }
).extend(cv.polling_component_schema("60s"))


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)
    cg.add_library("https://github.com/kgrozdanovski/veml7700-esp-idf", None)

