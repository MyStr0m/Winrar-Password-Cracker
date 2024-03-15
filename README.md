# Winrar Password Cracking Tool - Unrar and Password Removal

This script facilitates the cracking of Winrar passwords.


**Note**: The rar file should be located in `C:\Program Files\WinRAR`.

## Overview

This program is designed to crack Winrar passwords. It runs on Windows platforms, requires installation of Visual Studio and [Winrar](https://www.win-rar.com/start.html).
The future goal is to create a custom window for this project.
As the name suggests, the program tests all possible solutions to crack the Winrar password, including all printable strings.
The following flags are available for customization:

```
-a  Enable all printable characters
-l  Enable lowercase letters (default)
-u  Enable uppercase letters
-n  Enable numbers
-s  Enable symbols
```

You can configure the combination based on your requirements.


### Caution
The more characters you enable, the slower the execution becomes. A powerful processor is recommended. Future enhancements to improve execution speed are under consideration.

_This project is purely for entertainment purposes, and I don't intend to crack every Winrar password out there :)_.

## Getting Started
1. Download the Repo to your computer as zip
2. Extract Project to Folder.
3. Visual Studio is required for compilation. [Download it](https://visualstudio.microsoft.com/en/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&passive=false&cid=2030) if it's not already on your machine.
4. Open the solution file (.sln).
5. Select **Build Solution** from the **Build** menu or press `Ctrl+Shift+B` to compile WinrarCracker.
6. When the build is complete, select **Start Without Debugging** from the **Debug** menu or press `Ctrl+F5` to run WinrarCracker.
7. Your bruteforcer can be found in the root directory of the project as ```RarBrutForce(.exe)```.

## Disclaimer

This software is for educational and research purposes only. Any legal liability that may arise from the use of the software lies entirely with the user. The developer cannot be held responsible for any misuse of the software.

## License

This project is licensed under the MIT. For more information, see the [License](LICENSE).