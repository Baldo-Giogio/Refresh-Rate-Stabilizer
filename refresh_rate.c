#include <windows.h>
#include <stdio.h>

// Function to set the refresh rate
void set_refresh_rate(int refresh_rate) {
    DEVMODE devMode;
    if (EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode)) {
        devMode.dmFields = DM_DISPLAYFREQUENCY;
        devMode.dmDisplayFrequency = refresh_rate;

        if (ChangeDisplaySettings(&devMode, CDS_UPDATEREGISTRY) != DISP_CHANGE_SUCCESSFUL) {
            printf("Failed to change the refresh rate to %dHz\n", refresh_rate);
        } else {
            printf("Refresh rate set to %dHz\n", refresh_rate);
        }
    } else {
        printf("Failed to get current display settings\n");
    }
}

// Function to check if the laptop is plugged in
int is_plugged_in() {
    SYSTEM_POWER_STATUS status;
    if (GetSystemPowerStatus(&status)) {
        return status.ACLineStatus == 1;  // 1 means plugged in, 0 means on battery
    }
    return 0;
}

int main() {
    int plugged_in = is_plugged_in();  // Initial power state
    int last_power_state = plugged_in;

    // Set the initial refresh rate based on the current power state
    if (plugged_in) {
        set_refresh_rate(144);  // Set to 144Hz if plugged in
    } else {
        set_refresh_rate(60);  // Set to 60Hz if on battery
    }

    while (1) {
        plugged_in = is_plugged_in();  // Check the current power state

        if (plugged_in != last_power_state) {  // If the power state has changed
            if (plugged_in) {
                printf("Power state changed: Laptop is now plugged in.\n");
                set_refresh_rate(144);  // Set to 144Hz if plugged in
            } else {
                printf("Power state changed: Laptop is now on battery.\n");
                set_refresh_rate(60);  // Set to 60Hz if on battery
            }
            last_power_state = plugged_in;  // Update the last known power state
        }

        Sleep(5000);  // Check every 5 seconds
    }

    return 0;
}
