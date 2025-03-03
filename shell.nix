{
  pkgs ? import <nixpkgs> { },
}:
# Patches added: autostart, bar, barborders?, barcolors, barpadding, swallow, vanitygaps
/*
  Terminal: Mod+Return
  Run: Mod+r
  Close: Mod+Shift+C
  Quit: Mod+Shift+Q
  Shift Stack: Mod+Tab
*/
pkgs.mkShell {
  name = "mydwl";
  nativeBuildInputs = with pkgs; [
    gnumake
    pkg-config
    wayland
    wayland-protocols
    wayland-scanner
    wlroots
    libinput
    libxkbcommon
    pixman
    libdrm
    fcft
    xorg.libxcb
    xorg.xcbutilwm
    xwayland
  ];
  shellHook = ''
    echo "dev time!"
  '';
}
