#pragma once
#include <map>
#include <string>

class VisibilityHandler
{
public:
    VisibilityHandler(const VisibilityHandler&) = delete;

    VisibilityHandler& operator=(const VisibilityHandler&) = delete;

    static void init(const std::string& layer);

    static bool isVisible(const std::string& layer);

    static void show(const std::string& layer);

    static void hide(const std::string& layer);

    static void setOutOfRange(const std::string& layer);

    static void setInRange(const std::string& layer);

private:
    VisibilityHandler() = default;

    ~VisibilityHandler() = default;

    static VisibilityHandler& instance();

private:
    std::map<std::string, bool> m_layerVisibility;
    std::map<std::string, bool> m_layerInRange;
};
