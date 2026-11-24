// Provides the shared configuration instance.
// The kiosk and coffee machine read shop defaults from it.

#include "machine_config.h"

MachineConfig& MachineConfig::instance() {
    // The first call constructs the shared settings. Later calls return the
    // same object.
    static MachineConfig config;
    return config;
}
