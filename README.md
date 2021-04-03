# terminalOpen
A simple terminal file manager mainly focused for users who dont want their file manager to intrude into their daily terminal life. Meant to be keybinded as your usual file manager just to quickly move files and open terminal at a path 

## Dependencies
- clang-g++
- some patience

## Useage
When launched from a terminal, this opens the file manager in currently in the working directoy of the terminal
The program currently has the following functionalities
- Moving across files with 'hjkl' ( vim style because this is meant to be efficient) (Will add support for arrow keys some day)
- Opening the terminal in the current file with 'o'
- 'd' for deleting the highlighted file ( with [y/n] conformation)
- 'x' for cutting and 'c' for copying the highlighted file and 'v' for pasting it (currently this feature might not work as expected, work in progress)
- 'q' for quitting and closing without any action

