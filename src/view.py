import subprocess
import os

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
        
        # Define the name of the executable (adjust if necessary)
        executable = 'main'  # Replace with the actual executable name
        if os.name == 'nt':
            executable += '.exe'  # On Windows, add .exe extension
        
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
