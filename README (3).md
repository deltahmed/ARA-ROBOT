

<h1 align="center">🔲 ARA - ROBOT 🔳</h1>

</p>
<p align="center"> 
  <a href="https://github.com/deltahmed/ARA-ROBOT">
    <img src="https://img.shields.io/github/contributors/deltahmed/ARA-ROBOT.svg?style=for-the-badge" alt="deltahmed" /> </a>
  <a href="https://github.com/deltahmed/ARA-ROBOT">
    <img alt="" src="https://img.shields.io/github/issues/deltahmed/ARA-ROBOT.svg?style=for-the-badge">
    </a>
  <a href="https://github.com/deltahmed/ARA-ROBOT">
    <img alt="" src="https://img.shields.io/github/forks/deltahmed/ARA-ROBOT.svg?style=for-the-badge"></a>
  <a href="https://github.com/deltahmed/ARA-ROBOT">
    <img alt="" src="https://img.shields.io/github/stars/deltahmed/ARA-ROBOT.svg?style=for-the-badge"></a>
  <a href="https://raw.githubusercontent.com/deltahmed/ARA-ROBOT/master/LICENSE">
    <img src="https://img.shields.io/badge/License-BSD%202%20-blue?style=for-the-badge" alt="deltahmed" /> </a>
</p>



</p>
<p align="center"> 
  <a href="https://github.com/deltahmed/ARA-ROBOT">
    <img src="https://raw.githubusercontent.com/deltahmed/ARA-ROBOT/main/data/demo.gif" alt="deltahmed" /> </a>
</p>


## Table of Contents

* [About The Project](#about-the-project)
  * [Built With](#built-with)
* [Prerequisites](#prerequisites)
* [Environment](#environment)
* [Installation](#installation)
* [Launching the Game](#launching-the-game)
* [How to Play](#how-to-play)
* [Contributors](#contributors)
* [License](#license)


<!-- ABOUT THE PROJECT -->

## About The Project

**ARA-ROBOT** is a C game using the `ncursesw` library, created as part of a school project for the end of the second semester of the first year of preparatory engineering. The game is a **Rogue Lite** where you play as a robot moving through portals within a randomly generated map. Inside these maps, you will encounter **space monsters** that you must either eliminate or try to escape from as they are quite fast. Embark on an adventure and discover numerous **tasks** to complete inside this monster-infested ship.

### Built With

![GCC](https://img.shields.io/badge/-GCC-05122A?style=for-the-badge&logo=GNU)
![C](https://img.shields.io/badge/-C-05122A?style=for-the-badge&logo=C)
![C](https://img.shields.io/badge/-ncursesw-05122A?style=for-the-badge&logo=C)
![Make](https://img.shields.io/badge/-make-05122A?style=for-the-badge&logo=C)
![Make](https://img.shields.io/badge/-linux-05122A?style=for-the-badge&logo=linux)


## Prerequisites
- A recent version of the C compiler and make.
- The `ncurses` library installed.


## Environment 
- This project was created in unix/linux environment.

## Installation
1. Make sure you have installed `ncursesw`:
   ```sh
   sudo apt-get install libncurses5-dev libncursesw5-dev libncurses5 libncursesw5
   ```
2. Clone this repository:
   ```sh
   git clone https://github.com/deltahmed/ARA-ROBOT.git
   ```
3. Navigate to the project directory:
   ```sh
   cd ARA-ROBOT
   ```
4. Compile the project:
   ```sh
   make
   ```

## Launching the Game
1. Run the project:
   ```sh
   make run
   ```
2. Or 
   ```sh
   ./ARA_ROBOT
   ```

The main menu offers several options:
- **New Game**: Start a new adventure.
- **Load Game**: Resume from a saved game.
- **Credits**: View the project contributors.
- **Quit**: Exit the game.

## How to Play

The game controls are as follows (Arrows work):
- `z` to move forward
- `q` to move left
- `s` to move backward
- `d` to move right
- `m` to go to menu
- `space` to interact with tasks

Detailed instructions and objectives are explained in the game.

## Contributors

<a href="https://github.com/deltahmed/ARA-ROBOT/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=deltahmed/ARA-ROBOT" />
</a>

## Licence 
![Licence](https://img.shields.io/badge/License-BSD%202%20-blue?style=for-the-badge)

