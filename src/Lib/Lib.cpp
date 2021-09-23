#include "Lib/Lib.h"

#include <Common/IdGenerators/UuId4Generator.h>
#include <spdlog/spdlog.h>

namespace cps
{
    void Lib::HelloLib()
    {
        spdlog::info("Hello Basic Cpp Project!");

        auto idGenerator = ct::UuId4Generator();
        spdlog::info("New id generated {}", idGenerator.Generate());
    }
} // namespace cps
