#include <iostream>
#include "../test_version/lib.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

int main(int, char*[])
{
    auto logger = spdlog::stdout_color_mt("console");    
    logger->info("version {} was started", version());
    std::cout << "build " << version() << std::endl;
    std::cout << "Hello, World!";

    return 0;
}