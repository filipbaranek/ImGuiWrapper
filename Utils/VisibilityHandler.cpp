#include "VisibilityHandler.h"

VisibilityHandler& VisibilityHandler::instance()
{
    static VisibilityHandler s_instance;
    return s_instance;
}

void VisibilityHandler::init(const std::string& layer)
{
    hide(layer);
    setInRange(layer);
}

bool VisibilityHandler::isVisible(const std::string& layer)
{
    VisibilityHandler& handler = instance();
    return handler.m_layerVisibility[layer] && handler.m_layerInRange[layer];
}

void VisibilityHandler::show(const std::string& layer)
{
    instance().m_layerVisibility[layer] = true;
}

void VisibilityHandler::hide(const std::string& layer)
{
    instance().m_layerVisibility[layer] = false;
}

void VisibilityHandler::setOutOfRange(const std::string& layer)
{
    instance().m_layerInRange[layer] = false;
}

void VisibilityHandler::setInRange(const std::string& layer)
{
    instance().m_layerInRange[layer] = true;
}
