# 2D-Simulator
[![GitHub release (latest by date including pre-releases)](https://img.shields.io/github/v/release/abansal755/2D-Simulator?include_prereleases&label=latest%20release)](https://github.com/abansal755/2D-Simulator/releases)
![GitHub (Pre-)Release Date](https://img.shields.io/github/release-date-pre/abansal755/2D-Simulator)
[![GitHub commit activity](https://img.shields.io/github/commit-activity/m/abansal755/2D-Simulator)](https://github.com/abansal755/2D-Simulator/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors/abansal755/2D-Simulator?color=brightgreen)](https://github.com/abansal755/2D-Simulator/graphs/contributors)
[![issues](https://img.shields.io/github/issues/abansal755/2D-Simulator)](https://github.com/abansal755/2D-Simulator/issues)

# Introduction
This is a 2D particles simulator which simulates a system of particles in presence of various fields in the system. The particles have their own attributes such as mass, charge, position, velocity and acceleration. The system has various fields and viscous forces. This will allow the user to trace the trajectory of particles and analyse the system performance by maintainig the system variables.

# Tools Used
- **Qt C++:** Qt is a free and open-source widget toolkit for creating graphical user interfaces as well as cross-platform applications that run on various software and hardware platforms such as Linux, Windows, macOS, Android or embedded systems with little or no change in the underlying codebase while still being a native application with native capabilities and speed.

# Download
You can download the latest version of [2D-Simulator](https://github.com/abansal755/2D-Simulator/releases) available for Windows, macOS and Linux.

# Usage
* Once you have downloaded a version, extract the zip file and run 2D-Simulator.
* Under system settings set the various parameters of system.

    ### System Settings
    * Simulation Name - Name of the directory for the simulation.
    * Scale - Determines how many meters a pixel corresponds to.
    * Width and Height - Render resolution.
    * FPS - FPS of render.
    * Iterations - Sets number of iterations to be performed per sec and must be multiple of FPS.
    * Duration - Sets time duration in secs for which simulations has to be performed.
    * Time Factor - Scales time (determines how fast time progress).
    * Viscosity - Sets the viscosity due to resistane offered by the medium.
* In the Particle tab add particles to system with New button.
* Now select each particle individually and with edit button set the particle parameters.

    ### Particle Settings
    * x and y - sets the initial spacial co-ordinates of the particle.
    * vx and vy - sets the initial components of velocity vector.
    * radius - sets the size of particle in the render.
    * trajectRadius - sets the width of trajectory.
    * Pick color - Sets the particle color in the render.
* In the Fields tab add New radial and uniform Gravitaional and Electirc fields to system with their respective New buttons.
* Now selelect each field individually and with edit button set the field parameters.
* You may also Delete any particle or field and search for them in search bar.


# References
* [Complete Documentation](https://doc.qt.io/)

# Contributing
 First of all, thanks for thinking of contributing to this project:smiley:.
 Before sending a Pull Request, please make sure that you're assigned the task on a GitHub issue.
* If a relevant issue already exists, discuss on the issue and get it assigned to yourself on GitHub.
* If no relevant issue exists, open a new issue and get it assigned to yourself on GitHub.
 Please proceed with a Pull Request only after you're assigned. It'd be sad if your Pull Request (and your hardwork) isn't accepted just because it isn't ideologically compatible.

 # Getting Started 
* [Download Qt Creator](https://www.qt.io/download)
* Fork this repository.
* Clone the forked repository to your PC.

    `git clone https://github.com/YOUR-USERNAME/2D-Simulator`
* Create a branch specific to the issue or feature you are working on.
   
   `git branch <new-branch>`  
    `git checkout <new-branch>`
* Push your work to that branch.

    `git add .`  
    `git commit -m "message"`  
    `git push`
* Create Pull Request.

# Contact Us
* [**Akshit Bansal**](https://www.linkedin.com/in/akshit-bansal-38b228191/)
* [**Akshat Ojha**](https://www.linkedin.com/in/akshat-ojha-a1821a191/)