#include "plug-api.h"

namespace {
CoreAPI* API;

RunStatus run() {
    API->println("Ran the plugin");
    return RunStatus::SUCCESS;
}
}

extern "C"
PluginAPI init(CoreAPI* api) {
    API = api;
    api->println("Plugin Initialized");

    return PluginAPI{run};
}
