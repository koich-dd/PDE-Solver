# PDE SOLVER

Optional student project in Advanced Programming

**2D steady state heat equation on C++**

Determines the temperature distribution of a board in steady state. 

- **Physical model** : 2 dimension board has temperature distribution profile represented with sin curves.
    `Txx + Tyy = -2pi^2 * sin(pi * x) * sin(pi * y)`
The boundaries are set to 0.


- **Analytical Solution** : `T(x,y) = sin(pi * x) * sin(pi * y)`

- **Simulation Concept**: It enables users to solve PDEs with different methods. 

- **How to Execute the Code**: User can choose either Gauss-Seidel method or Jacobi method. Both methods returns the solution as a matrix. user can see the output as a heatmap.

- **Example**: 10 nodes are assigned in both x and y directions. The consequence shown as below.
      
|  |  |  |  |  |  |  |  |  |  |  |  |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 0 | 0 |0 |  0 | 0 | 0 |0 | 0 | 0 | 0| 0 |0|
| 0 | 0.079914 |0.153354 |  0.21437 | 0.258019 | 0.280765  |0.280765  | 0.25802 | 0.214371 | 0.153354| 0.0799143 |0|
| 0 | 0.153354 |0.294284  |0.411373|  0.495136|  0.538785|  0.538785|  0.495136|  0.411374|  0.294285|  0.153354 |0|
|0  | 0.21437 | 0.411373 |  0.57505 | 0.692139 | 0.753156 | 0.753156 |  0.69214 | 0.575051 | 0.411374|  0.214371 |0|
|0 | 0.258019 | 0.495136 | 0.692139 |  0.83307  | 0.90651 | 0.906511 | 0.833071  | 0.69214 | 0.495137 |  0.25802|         0|
|0  |0.280765  |0.538785  |0.753156   |0.90651  |0.986425 | 0.986425 | 0.906511 | 0.753157 | 0.538786 | 0.280766    |     0|
|0  |0.280765  |0.538785  |0.753156  |0.906511  |0.986425 | 0.986426 |0.906512  |0.753157  |0.538786 | 0.280766     |    0|
|0   |0.25802  |0.495136  | 0.69214  |0.833071  |0.906511  |0.906512  |0.833072  |0.692141  |0.495137   |0.25802         |0|
|0  |0.214371  |0.411374  |0.575051   |0.69214  |0.753157  |0.753157  |0.692141  |0.575052  |0.411375  |0.214371         |0|
|0  |0.153354  |0.294285  |0.411374  |0.495137  |0.538786  |0.538786  |0.495137  |0.411375  |0.294286  |0.153355         |0|
|0 |0.0799143  |0.153354  |0.214371   |0.25802  |0.280766  |0.280766   |0.25802  |0.214371  |0.153355 |0.0799145         |0|
|0       |  0         |0       |  0    |     0  |       0   |      0   |      0    |     0   |      0    |   0  |0         |0|

      
In a heatmap, it is visualized as follows.

![Example result!](/sample/example.jpeg "Example")

____

### Set up

#### CMake

**On Windows**         
Go to the CMake download page. Download the Windows installer. Run the installer.          
**On Linux**      
```
sudo apt-get update 
sudo apt-get install cmake
``` 

#### Eigen

Install Eigen from https://eigen.tuxfamily.org as tar.gz or zip format, and extract it in the project directory.
Add the pass to eigen directory in C/C++: Edit Configuration (JSON) such as 
```
"includePath": [
                "${workspaceFolder}/**",
                "eigen-3.3.9"
            ]
```
         
The project directory should look like:     

PDE-SOLVER          
    |-- eigen-3.3.9          
    |-- src       
    |-- build        
    |-- sample         

_____

### How to use

1. Use CMake tools to configure the project such as *CMake Tools* on Visual Studio.
2. Run `streamlit run src/Home.py` to launch app.
3. On the *SolvePDE* page, set the configurations and run the solver.
4. View the results on the *Visualization* page.

