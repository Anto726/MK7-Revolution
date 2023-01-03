# MK7-Revolution
A [CTRPluginFramework-RevolutionBase](https://github.com/Anto726/CTRPluginFramework-RevolutionBase) plugin for Mario Kart 7.  
Strictly for educational purposes.

## Build
- [git](https://git-scm.com/downloads)
- [devkitPro](https://github.com/devkitPro/installer/releases)
- [CTRPluginFramework](https://gitlab.com/thepixellizeross/ctrpluginframework/-/releases)
- [3gxtool](https://gitlab.com/thepixellizeross/3gxtool/-/releases)

1. Clone the repository locally by running `git clone <repo url> --recurse-submodules`.
2. Update devkitPro by running `pacman -Syuw 3ds-dev` and `pacman -Syuw 3ds-portlibs`.
3. Move `libctrpf.tar.bz2` into [assets](../assets) and install it by running `./install.sh libctrpf.tar.bz2` **in MSys2**.
4. Move `3gxtool` to `devkitPro/tools/bin`.
5. Run `make` in the cloned repository.