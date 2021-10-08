# Fdf

Graphics programming introductory project at [Hive Helsinki](https://www.hive.fi/en/) coding school.

## Task

Discovering the basics of graphics programming in `C`, and in particular how
to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint.
The goal of this project was to build program that can read a formatted heightmap file and render it as an interactable 3D wireframe in a graphical window, with an internally developed `miniLibX` library.

<p align="center">
  <img src="https://github.com/pesonkim/fdf/blob/master/pic/Screen%20Shot%202020-08-21%20at%207.44.06%20AM.png">
</p>

**Project constraints:**
- Create a graphic wireframe (linking various x,y,z points via segments) representing a landscape from the file as a parameter to the program
- Including both isometric and perspective projections

- Allowed functions:
	- `open`, `read`, `write`, `close`
	- `malloc`, `free`, `exit`
	- `perror`, `strerror`
	- Anything in `math` or `miniLibX` libraries
