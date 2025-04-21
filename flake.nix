{
  description = "dwl development flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs =
    { self, nixpkgs }:
    let
      pkgs = nixpkgs.legacyPackages."x86_64-linux";
    in
    {
      devShells."x86_64-linux".default = pkgs.mkShell {
        packages = with pkgs; [
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
      };
    };
}
