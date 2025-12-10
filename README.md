# FdF (Fil de Fer)

This project involves creating a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) using the MiniLibX graphic library.

## Project Overview
FdF is a graphic project where we represent the landscape of a given map on a screen. The project introduces the basics of graphic programming, including:
- Window management (opening, closing, minimizing).
- Pixel plotting.
- Handling keyboard and mouse events.
- Geometric projections (Isometric and/or Parallel).

## Features
- Reads map files (.fdf) containing height values.
- Renders the wireframe mesh in 3D projection.
- Supports zoom, translation, and rotation (if implemented as bonus).

## Usage
Compile and run the program with a map file:
```bash
make
./fdf maps/42.fdf
```
