add_requires("gtest")
add_rules("mode.profile", "mode.releasedbg", "mode.release")

set_languages("c17", "cxx17")
set_warnings("all", "error")

if is_plat("windows") then
    add_cxxflags("/Zc:__cplusplus")
end

target("kbase")
    set_kind("headeronly")
    add_includedirs("include/", { public = true })

target("kbase_test")
    set_kind("binary")
    add_files("tests/*.cpp")
    add_deps("kbase")
    add_packages("gtest")