# Godot visual studio 2022 CPP extension template
A quick setup project for godot cppExtensions, a godot project, and visual studio sln + proj file, that I use as a base for godot cpp extension projects for myself.

- Contains godot 4.6 executable (can be changed easily)
- project settings / setup / versions / godot executable / paths are handled by the game/source/Directory.Build.Props file
- Contains a Visual Studio 2022 SLN in /game/source that contains a single, runable / debuggable cpp extension named game
- Contains a cpp extension project named game, with an example registration, and CubeNode3D
- vcxproj post build hookup that copies the built DLL to the correct location in the godot project ( /bin/(extensionName)/ )
- A mostly empty Godot test scene, with a CubeNode3D example cppExtenion derrived Node3D
- A bat file to build release/debug libs for godot-cpp in /game/source/external/godot-cpp. It calls scons, so python + scons is required for godot-cpp building

# Submodules
- godot-cpp for godot 4.6 as a submodule in /game/source/external/godot-cpp/(version)
- nlohmann json as a submodule in /game/source/external/nlohmann-json


# Quick start
- open /game/source/Directory.Build.Props, and change the hard coded path in ProjectRoot that is not relative that must be set:

   it should point to the root checkout dir of the git repo: C:\code\GodotVisualStudioCppExtensionTemplate\

- build godot-cpp:
  
  requires an installation of python + scons
  
  run the bat file located here: /game/source/external/godot-cpp/


- there are two configurations that work right now:
 
  Debug_Editor_Exts : launches the editor with the extension in a debuggable state

  Debug_Game_Exts : launches a running instance of the godot game in a debuggable state


- changing versions of godot:
  
  if required, update the godot-cpp to a compatible version, check the godot-cpp rebuild script and make sure the version number is good
  
  download and put the godot exe into /game/godotExe/ following the existing pattern
  
  update the godot version in /game/source/Directory.Build.Props
  

