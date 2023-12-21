#include <Windows.h>
#include <argh.h>

#include <iostream>

int main(int /*unused*/, char *argv[])
{
    argh::parser cmdl;
    cmdl.add_param({"w", "width"});
    cmdl.add_param({"h", "height"});
    cmdl.add_param({"r", "refresh-rate"});
    cmdl.parse(argv);

    DEVMODE deviceMode;
    // Populate with current settings
    EnumDisplaySettings(nullptr, ENUM_CURRENT_SETTINGS, &deviceMode);

    bool change = false;

    if(cmdl("w")) {
        const auto width = std::stoul(cmdl("w").str());
        if(deviceMode.dmPelsWidth != width) {
            deviceMode.dmPelsWidth  = width;
            deviceMode.dmFields    |= DM_PELSWIDTH;
            std::cout << "Changing width to " << width << "\n";
            change = true;
        }
    }
    if(cmdl("h")) {
        const auto height        = std::stoul(cmdl("h").str());
        if(deviceMode.dmPelsHeight != height) {
            deviceMode.dmPelsHeight  = height;
            deviceMode.dmFields     |= DM_PELSHEIGHT;
            std::cout << "Changing height to " << height << "\n";
            change = true;
        }
    }
    if(cmdl("r")) {
        const auto refreshRate         = std::stoul(cmdl("r").str());
        if(deviceMode.dmDisplayFrequency != refreshRate) {
            deviceMode.dmDisplayFrequency  = refreshRate;
            deviceMode.dmFields           |= DM_DISPLAYFREQUENCY;
            std::cout << "Changing refresh rate to " << refreshRate << "\n";
            change = true;
        }
    }

    if(change) {
        return ChangeDisplaySettings(
                   &deviceMode, CDS_UPDATEREGISTRY | CDS_GLOBAL | CDS_RESET
               ) != DISP_CHANGE_SUCCESSFUL;
    }

    return 0;
}
