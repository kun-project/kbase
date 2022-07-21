set_project("kun.kbase")

add_rules("mode.debug", "mode.release", "mode.releasedbg")

includes("xmake/options.lua")

target("kbase")
    set_kind("headeronly")
    add_includedirs("src/include", { public = true })
target_end()