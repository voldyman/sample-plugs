#pragma once

using PrintLnFn = void(*)(const char*);

struct CoreAPI {
    PrintLnFn println;
};

enum class RunStatus {
    SUCCESS,
    FAILURE
};

using RunFn = RunStatus(*)();

struct PluginAPI {
    RunFn run;
};

using InitFn = PluginAPI(*)(CoreAPI*);
