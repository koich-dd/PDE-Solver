import streamlit as st
import subprocess
import os

# Set title and description of this page.
st.title("Solve PDE")
st.write("Fill the configurations and click Run button to solve PDE.")

# Set select box for the choice of solver, and number inputs for nodes in x and y directions.
solver = st.selectbox("Solver", ("Gauss-Seidel method", "Jacobi method"))
x = st.number_input("Assign a number of nodes in horizontal direction", value=10)
y = st.number_input("Assign a number of nodes in vertical direction", value=10)

new_config = "c"

# Once "Run" button is clicked, overwrite the config.txt file based on the user's choice.
# After that, run main.cpp
if st.button("Run"):
    new_config = new_config + "\n" + str(x) + "\n" + str(y)
    if solver == "Gauss-Seidel method":
        new_config = new_config + "\ng"
    if solver == "Jacobi method":
        new_config = new_config + "\nj"
    with open("config.txt", "w") as file:
        file.write(new_config)

    # Define the build directory
    build_dir = 'build'

    # Create the build directory if it doesn't exist
    if not os.path.exists(build_dir):
        os.makedirs(build_dir)

    # Change to the build directory
    os.chdir(build_dir)

    # Run CMake to configure the project
    cmake_command = ['cmake', '../src']
    cmake_result = subprocess.run(cmake_command, capture_output=True, text=True)

    # Check if CMake configuration was successful
    if cmake_result.returncode == 0:
        print("CMake configuration successful.")
        print(cmake_result.stdout)
        
        # Run CMake to build the project
        build_command = ['cmake', '--build', '.']
        build_result = subprocess.run(build_command, capture_output=True, text=True)
        
        # Check if the build was successful
        if build_result.returncode == 0:
            print("Build successful.")
            print(build_result.stdout)
            
            # Define the name of the executable
            executable = 'main'  
            if os.name == 'nt':
                executable += '.exe'  
            
            # Run the compiled executable
            run_command = [os.path.join('.', executable)]
            run_result = subprocess.run(run_command, capture_output=True, text=True)
            
            # Print the output of the executable
            print("Program output:")
            print(run_result.stdout)
        else:
            print("Build failed.")
            print(build_result.stderr)
    else:
        print("CMake configuration failed.")
        print(cmake_result.stderr)
    # Back to the main working directory
    os.chdir("../")
