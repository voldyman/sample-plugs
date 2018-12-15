#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

#include "plug-api.h"

int main() {
    void* dl_hd = dlopen("./plugin.so", RTLD_LAZY);
    if (dl_hd == nullptr) {
        fprintf(stderr, "%s\n", dlerror());
        return EXIT_FAILURE;
    }

    InitFn init_fn = (InitFn) dlsym(dl_hd, "init");
    if (init_fn == nullptr) {
        fprintf(stderr, "%s\n", dlerror());
        return EXIT_FAILURE;
    }

    auto println = [](const char* str) {
        fprintf(stderr, "%s\n", str);
    };
    CoreAPI core{println};
    PluginAPI api = init_fn(&core);
    api.run();

    if (dlclose(dl_hd) != 0) {
        fprintf(stderr, "%s\n", dlerror());
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
