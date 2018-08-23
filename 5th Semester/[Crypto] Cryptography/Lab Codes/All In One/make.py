from os import system, listdir
from os.path import splitext

# Variables
main_file = 'main'  # Change this to the name of the file containing the main() funnction
output_directory = 'bin'    # Change this to the directory that you want your executable binary to be stored
class_directory = 'class'   # Chage this to the directory containing the classes
objectfile_directory = 'class/objectfiles'  # change this to the fir directory where the compiled class objects will be stored
app_name = 'Crypto' # Change this to name the output executable

# Find and get all the necessary cpp files from the class directory
files = []
for file in listdir(class_directory):
    file_name, file_ext = splitext(file)
    if file_ext.lower() == '.cpp':
        files.append(file_name) # Will only contain filenames of files with .cpp extension

# Compile header files and move the compiled objects to class/objectfiles/
cmds = [['Clearing the screen', 'cls']]
for file in files:
    cmds.append(['Compiling {}.cpp'.format(file), 'g++ -c {0}/{1}.cpp'.format(class_directory ,file)])  # Compile the file and get a object file
    cmds.append(['Moving {0}.o to {1}/'.format(file, objectfile_directory), 'move {0}.o {1}/'.format(file, objectfile_directory)])  # Move the object file to the given directory

# Build the application and move it to bin/
compile_cmd = 'g++ -o {0} {1}.cpp'.format(app_name, main_file)
for file in files:
    compile_cmd += ' {0}/{1}.o'.format(objectfile_directory ,file)  # To link all the object files
cmds.append(['Building application', compile_cmd])
cmds.append(['Moving application to {0}/'.format(output_directory), 'move {0}.exe {1}/'.format(app_name, output_directory)])    # Move the program to the given directory

# Actually running the commands
for description, cmd in cmds:
    print('{} . . .'.format(description))
    if system(cmd) != 0:    # If the system returned error while running the command then quit
        print('Error!')
        system('del /F /Q *.o')
        exit(1)

# If everything worked, then clear screen and run app
print('Successful')
system('pause')
system('cls')
system('.\\bin\\{0}'.format(app_name))  # Execute the compiled program