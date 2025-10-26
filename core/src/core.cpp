#include "core.h"



Core::Core(const FONEntry &params) :
    moduleManager(params)
{ }

void Core::serialize(FONEntry &save) const
{
    moduleManager.serialize(save);
}
