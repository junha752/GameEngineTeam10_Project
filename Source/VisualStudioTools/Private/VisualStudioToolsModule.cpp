#include "Modules/ModuleManager.h"

class FVisualStudioToolsModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FVisualStudioToolsModule, VisualStudioTools);
