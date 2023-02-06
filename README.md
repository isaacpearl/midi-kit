# cmake_plugin
`cmake_plugin` is a simple MVP for building a passthrough JUCE plugin with CMake, importing JUCE as a Git submodule.

## Build/setup
- `git clone --recurse-submodules git@github.com:isaacpearl/midi-kit.git && cd midi-kit`
- `cmake . -B cmake-build -DCMAKE_EXPORT_COMPILE_COMMANDS=YES`
- `cmake --build cmake-build --target MIDIKit_AU` (do `--target MIDIKit_All` for all, `--target MIDIKit_VST` for VST, etc)
