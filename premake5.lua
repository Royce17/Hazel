workspace "Hazel"
   architecture "x86_64"
   configurations 
   {
      "Debug",
      "Release",
      "Dist",
   }
   startproject "Sandbox" --Visual Studio Only

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Hazel"
   location "Hazel"
   kind "SharedLib"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files
   {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
   }

   includedirs
   {
      "%{prj.name}/src",
      "%{prj.name}/vendor/spdlog/include",
   }

   filter "system:windows"
      cppdialect "C++latest"
      staticruntime "On"
      systemversion "latest"

      defines
      {
         "HZ_BUILD_DLL",
         "HZ_PLATFORM_WINDOWS",
      }

      postbuildcommands
      {
         ("{COPY} %{cfg.buildtarget.relpath} ../bin/"..outputdir.."/Sandbox")
      }

   filter "configurations:Debug"
      defines "HZ_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "HZ_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "HZ_DIST"
      optimize "On"


project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   files
   {
      "%{prj.name}/src/**.h",
      "%{prj.name}/src/**.cpp",
   }

   includedirs
   {
      "Hazel/src",
      "Hazel/vendor/spdlog/include",
   }

   links
   {
      "Hazel",
   }

   filter "system:windows"
      cppdialect "C++latest"
      staticruntime "On"
      systemversion "latest"

      defines
      {
         "HZ_PLATFORM_WINDOWS",
      }

   filter "configurations:Debug"
      defines "HZ_DEBUG"
      symbols "On"

   filter "configurations:Release"
      defines "HZ_RELEASE"
      optimize "On"

   filter "configurations:Dist"
      defines "HZ_DIST"
      optimize "On"