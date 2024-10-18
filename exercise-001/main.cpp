#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    auto counter = 20;      // set a default of 20
    CLI::App app{PROJECT_NAME};     // create an instance of an App with variable name app
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        // Add a command line option -c or --count and fill the variable counter
        app.add_option("-c,--count", counter, "How many iteams to insert");
        app.parse(argc, argv);



    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */
    fmt::print("Value of argc, {}!\n", argc);
    fmt::print("Value of argv[0], {}!\n", argv[0]);
    //fmt::print("Value of argv[2], {}!\n", argv[2]); //possible nullpointer exception

    fmt::print("The value of the counter, {}!\n", counter);

    return 0; /* exit gracefully*/
}
