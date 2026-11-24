# 1337 Projects

A collection of projects completed during my studies at **1337 (42 Network)**. The repository brings together work in C, C++, graphics, networking, and algorithmic problem-solving.

Each project lives in its own directory and has its own scope and build requirements. There is no single build command for the whole repository; use the Makefile or instructions inside the relevant project.

## Project index

### C programming and libraries

| Project | Description | Directory |
|---|---|---|
| **libft** | Reimplementation of commonly used C library functions, including string, memory, conversion, and linked-list utilities. | [`libft/`](./libft/) |
| **get_next_line** | Reads from a file descriptor one line at a time, using buffered input and supporting the required reading behavior. | [`get_next_line/`](./get_next_line/) |
| **ft_printf** | Custom formatted-output function with conversion and formatting logic, including bonus work. | [`ft_printf/`](./ft_printf/) |

### Graphics and game programming

| Project | Description | Directory |
|---|---|---|
| **FdF** | Renders a wireframe representation of a 3D terrain map. | [`Fdf/`](./Fdf/) |
| **so_long** | 2D tile-based game with map validation, rendering, player movement, and bonus animations. | [`so_long/`](./so_long/) |
| **cub3D** | Raycasting-based 3D game with textured walls; the bonus work includes a minimap and mouse-look. | [`my_cub3d/`](./my_cub3d/) |

### C++

| Project | Description | Directory |
|---|---|---|
| **C++ Modules 00–09** | A sequence of C++ exercises covering the language and object-oriented programming concepts. Each exercise has its own directory and Makefile. | [`cpp_modules/`](./cpp_modules/) |

### Networking

| Project | Description | Directory |
|---|---|---|
| **NetPractice** | Practical IPv4 networking exercises involving IP addresses, subnet masks, routers, and network configuration. | [`net_practice/`](./net_practice/) |

### Algorithms and programming exercises

| Project | Description | Directory |
|---|---|---|
| **Work** | Standalone C++, JavaScript, and other programming exercises, including array, string, tree, and data-structure problems. | [`work/`](./work/) |

## Building projects

Projects are built independently. Examples:

```bash
# C libraries
make -C libft
make -C ft_printf

# Graphics projects
make -C Fdf
make -C so_long
make -C my_cub3d

# A single C++ exercise
cd cpp_modules/cpp_00/ex01
make
```

Check each project's Makefile and project-specific instructions before building. The graphics projects depend on MiniLibX and platform-specific graphics libraries; these dependencies may need to be installed or provided separately. In particular, check the MiniLibX path expected by each Makefile.

## Repository structure

```text
.
├── Fdf/                 # Wireframe terrain renderer
├── cpp_modules/         # C++ modules 00–09
├── ft_printf/           # Formatted-output implementation
├── get_next_line/       # Line-by-line file-descriptor reader
├── libft/               # C library reimplementations
├── my_cub3d/            # Raycasting 3D game
├── net_practice/        # IPv4 networking exercises
├── so_long/             # 2D game
└── work/                # Programming and problem-solving exercises
```

## Notes

- This is an academic project collection. The projects have different scopes, dependencies, and levels of completeness.
- Build outputs such as object files, static libraries, and compiled executables are generated files, not source code. Use each project's `make clean` or `make fclean` target where available.
- Read any project-specific README before building or running an individual project.
