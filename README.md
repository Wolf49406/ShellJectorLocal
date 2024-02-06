# ShellJectorLocal
Same as [ShellJector](https://github.com/Wolf49406/ShellJector) but works with local DLL

[![MSBuild](https://github.com/Wolf49406/ShellJectorLocal/actions/workflows/msbuild.yml/badge.svg?branch=main)](https://github.com/Wolf49406/ShellJectorLocal/actions/workflows/msbuild.yml)

## How to Build:
- Open `ShellJectorLocal.sln -> main.cpp`;
- Set `ProcName` and `DllName`;
- Build;

## Usage:
- Go to \ShellJectorLocal\Build;
  - OR just download the [Latest Release](https://github.com/Wolf49406/ShellJectorLocal/releases/latest);
  - Set launch arguments (down below);
- Open Target Process;
- Open `ShellJectorLocal.exe`;

## Arguments:
You can set `ProcName` and `DDllName` with `-proc` and `-dll` arguments  
(ex: `ShellJectorLocal.exe -proc explorer.exe -dll Payload.dll`)
Arguments are case **sensitive**!

## Notice:
ShellJectorLocal.exe will look for Payload.dll near itself!
