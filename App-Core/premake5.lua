local outputdir = "%{cfg.buildcfg}-%{cfg.system}"

project("DOS-Library")
kind("StaticLib")
language("C++")

targetdir("../bin/" .. outputdir .. "/%{prj.name}")
objdir("../build/" .. outputdir .. "/%{prj.name}")

files({
	"source/**.h",
	"source/**.cpp",
})

includedirs({
	"../vendor/raylib/include",

})

libdirs({
	"../vendor/raylib/lib",

})

links({
	"raylib"
})

--postbuildcommands({
--	"cp -r assets/ %{cfg.buildtarget.directory}",
--})

filter("system:Unix")
system("linux")
cdialect("C17")
systemversion("latest")
defines({
	"PLATFORM_LINUX",
})

filter("configurations:Debug")
defines("DEBUG")
symbols("on")

filter("configurations:Release")
defines("RELEASE")
optimize("on")

filter("configurations:Dist")
defines("DIST")
optimize("on")
kind("WindowedApp")