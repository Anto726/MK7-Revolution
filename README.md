# MK7-Revolution
A [CTRPluginFramework-RevolutionBase](https://github.com/Anto726/CTRPluginFramework-RevolutionBase) plugin for Mario Kart 7.  
Strictly for educational purposes.

## Build
- [git](https://git-scm.com/downloads)
- [devkitPro](https://github.com/devkitPro/installer/releases)
- [CTRPluginFramework](https://gitlab.com/thepixellizeross/ctrpluginframework/-/releases)
- [3gxtool](https://gitlab.com/thepixellizeross/3gxtool/-/releases)

1. Clone the repository locally by running `git clone <repo url> --recurse-submodules`
2. Make sure devkitPro is updated either by running its updater and installing the 3DS Development toolchain, or by running `pacman -Syuw 3ds-dev` and `pacman -Syuw 3ds-portlibs` in the command line.
3. Move libctrpf.tar.bz2 into the `Assets` folder and install it by running `./install.sh libctrpf.tar.bz2` in MSys2.
4. Move 3gxtool to `devkitPro/tools/bin`.
5. Run `make` in the command line while in the main directory.