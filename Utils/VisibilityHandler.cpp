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
    return m_layerVisibility[layer] && m_layerInRange[layer];
}

void VisibilityHandler::show(const std::string& layer)
{
    m_layerVisibility[layer] = true;
}

void VisibilityHandler::hide(const std::string& layer)
{
    m_layerVisibility[layer] = false;
}

void VisibilityHandler::setOutOfRange(const std::string& layer)
{
    m_layerInRange[layer] = false;
}

void VisibilityHandler::setInRange(const std::string& layer)
{
    m_layerInRange[layer] = true;
}
