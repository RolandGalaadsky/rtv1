# rtv1
ray tracing project in UNIT Factory on graphical branch.
## Installation

you need to have:
 * git
 * libx11-dev
 * libxext-dev
 * build-essential
 * clang
 * gcc
 
to install this packages you can write in your terminal :
  
```bash
sudo apt install git libx11-dev libxext-dev build-essential clang gcc
```
then just clone repo
```bash
git clone https://github.com/RolandGalaadsky/rtv1.git somewhere/rtv1
```
## Usage:
```bash
cd somewhere/rtv1
make
./rtv1 tests/somefile_test_file
```
## Test Files Description:

SHADOW(OPTION)
 CAM CORDS VIEW
 LIGHT TYPE INTENSITY POSITION/DIRECTION
 OBJECT TYPE COLOR SPECULAR POSITION REFLECTION DIRECTION RADIUS ANGLE

EXAMPLE:
```bash
CAM {0,0,-20} {0,0,0} #CAMERA IN (0,0,-20) position with view vector (0,0,1)
LIGHT AMBIENT 0.12 #ambient light with 0.12 intensity
LIGHT POINT 0.7 {20,20,-30} #point light in (20,20,-30) position
OBJECT SPHERE {255,0,0} 15 {-1,-1,10} 0.2 4 
#above sphere with (255,0,0) RGB color with 15 specular value with center in (-1,-1,10) 20 % reflective and radius 4
OBJECT CONE {255,255,50} 80 {4,0,10} 0.5 {0,0,-35} 37
#above cone with (255,255,50) RGB color with 80 specular value with center in (4,0,10) 50 % reflective direction vector {0,1,0} that is rotated around Z-axis on -35 degrees, with 37 degrees half angle
OBJECT PLANE {55,105,255} -1 {0,0,40} 0.1 {90,0,0}
#above plane with (55,105,255) RGB color without specular with point (0,0,40) 10 % reflective and normal vector {0,1,0} that is rotated around X-axis on 90 degrees, so it is {0,0,1} now
OBJECT PLANE {155,155,155} -1 {0,-4,0} 0.2 {0,0,0}
#above plane with (155,155,155) RGB color without specular with point (0,-4,0) 20 % reflective and normal vector {0,1,0} that is not rotated
OBJECT CYLINDER {72,255,72} -1 {-5,0,11} 0.3 {-10,0,45} 3
#above cylinder with (72,255,72) RGB color without specular value with center in (-5,0,11) 30 % reflective direction vector {0,1,0} that is rotated around X-axis in 10 degrees, then Y-axis in 0 degrees, and then 45 degrees around Z-axis, with 3 radius 
```
## Screnshots

### room test file
![room](https://github.com/RolandGalaadsky/rtv1/blob/master/Screenshot%20from%202018-10-28%2023-53-23.png)

### a_bit_of_everything test file
![a_bit_of_everything](https://github.com/RolandGalaadsky/rtv1/blob/master/Screenshot%20from%202018-10-28%2023-54-21.png)


### a_bit_of_everything_viewport test file
![a_bit_of_everything_viewport](https://github.com/RolandGalaadsky/rtv1/blob/master/Screenshot%20from%202018-10-28%2023-54-50.png)


### finally test file
![finally](https://github.com/RolandGalaadsky/rtv1/blob/master/Screenshot%20from%202018-10-28%2023-53-53.png)
