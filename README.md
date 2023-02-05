# cmake_plugin
`cmake_plugin` is a simple MVP for building a passthrough JUCE plugin with CMake, importing JUCE as a Git submodule.

## Build/setup
- `git clone --recurse-submodules git@github.com:isaacpearl/cmake_plugin.git && cd cmake_plugin`
- `cmake . -B cmake-build -DCMAKE_EXPORT_COMPILE_COMMANDS=YES`
- `cmake --build cmake-build --target AudioPluginExample_AU` (do `--target AudioPluginExample_All` for all, `--target AudioPluginExample_VST` for VST, etc)
