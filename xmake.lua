add_requires("gtest")
add_rules("mode.profile", "mode.releasedbg", "mode.release")

set_languages("c17", "cxx17")
set_warnings("all", "error")

add_cxxflags("/Zc:__cplusplus", "/utf-8", { tools = { "cl", "clang-cl" } })
add_cxxflags("-ftime-trace", { tools = { "clang" } })
add_cxxflags("/d1reportTimeSummary", { tools = {"cl", "clang-cl"}, force = true })

-- Dump compilation info ---
--/Bt                     -- total time spent in frontend (d1) and backend (d2)
--/d1templateStats        -- show info regarding template use
--/d1reportTimeSummary    -- show frontend compile time summary
--/d1reportTime           -- show (very) detailed frontend compile time info
--/d2cgsummary            -- show backend compile time summary


target("kbase")
    set_kind("headeronly")
    add_includedirs("include/", { public = true })

target("kbase_test")
    set_kind("binary")
    add_files("tests/*.cpp")
    add_deps("kbase")
    add_packages("gtest")