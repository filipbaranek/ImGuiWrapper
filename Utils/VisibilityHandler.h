#pragma once
#include <map>
#include <string>

class VisibilityHandler
{
public:
    VisibilityHandler(const VisibilityHandler&) = delete;

    VisibilityHandler& operator=(const VisibilityHandler&) = delete;

    static VisibilityHandler& instance();

    void init(const std::string& layer);

    bool isVisible(const std::string& layer);

    void show(const std::string& layer);

    void hide(const std::string& layer);

    void setOutOfRange(const std::string& layer);

    void setInRange(const std::string& layer);

private:
    VisibilityHandler() = default;

    ~VisibilityHandler() = default;

private:
    std::map<std::string, bool> m_layerVisibility;
    std::map<std::string, bool> m_layerInRange;
};
