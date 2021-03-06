
#include "test.hpp"

#include "command_diff.hpp"

TEST_CASE("diff") {

    CommandDiff cmd;

    SECTION("no argments - need exactly two arguments") {
        REQUIRE_THROWS_AS(cmd.setup({}), argument_error);
    }

    SECTION("one argument - need exactly two arguments") {
        REQUIRE_THROWS_AS(cmd.setup({"x"}), argument_error);
    }

    SECTION("three arguments - need exactly two arguments") {
        REQUIRE_THROWS_AS(cmd.setup({"x", "y", "z"}), argument_error);
    }

    SECTION("quiet with output parameter -o") {
        REQUIRE_THROWS_AS(cmd.setup({"-q", "-o", "file"}), argument_error);
    }

    SECTION("quiet with output parameter -f") {
        REQUIRE_THROWS_AS(cmd.setup({"-q", "-f", "opl"}), argument_error);
    }

    SECTION("quiet with output parameter --fsync") {
        REQUIRE_THROWS_AS(cmd.setup({"-q", "--fsync"}), argument_error);
    }

    SECTION("quiet with output parameter --output-header") {
        REQUIRE_THROWS_AS(cmd.setup({"-q", "--output-header", "foo"}), argument_error);
    }

    SECTION("quiet with output parameter -O") {
        REQUIRE_THROWS_AS(cmd.setup({"-q", "-O"}), argument_error);
    }

}

