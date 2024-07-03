## Simple galaxy simulator

**Authors**: Damian Boquete Costa & Nikola Antonijevic

**Last modification**: 03.01.2021

---

<p align="center">
  <img src="exe.gif"/>
</p>

### Description
This practical work involved simulating the physical behavior of celestial entities orbiting around another entity that is much more massive than them. To achieve this, all the physics logic was implemented using the C language and the SDL library.

The simulation aims to replicate the behavior of a galaxy. In other words, it continuously displays the movement of pixels, governed by the laws of physics, around the red pixel representing the massive entity (referred to as a "black hole" from now on) mentioned above.

The paper named [rapport.pdf](rapport.pdf) (only in french) describes this work more in depth. 

### How to run (Linux)
If `SDL2` library is not already installed in your machine, execute the following command with adequate priviledges:
```
apt install libsdl2-dev
```

Then run the following command inside the project folder:
```
make exe
```
