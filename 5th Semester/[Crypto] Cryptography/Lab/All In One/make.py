from os import system, listdir
from os.path import splitext

# Variables
main_file = 'main'
output_directory = 'bin'
class_directory = 'class'
objectfile_directory = 'class/objectfiles'
app_name = 'Crypto'

# Find and get all the necessary cpp files frm the class directory
files = []
for file in listdir(class_directory):
    file_name, file_ext = splitext(file)
    if file_ext.lower() == '.cpp':
        files.append(file_name)

# Compile header files and move the compiled objects to class/objectfiles/
cmds = [['Clearing the screen', 'cls']]
for file in files:
    cmds.append(['Compiling {}.cpp'.format(file), 'g++ -c {0}/{1}.cpp'.format(class_directory ,file)])
    cmds.append(['Moving {0}.o to {1}/'.format(file, objectfile_directory), 'move {0}.o {1}/'.format(file, objectfile_directory)])

# Build the application and move it to bin/
compile_cmd = 'g++ -o {0} {1}.cpp'.format(app_name, main_file)
for file in files:
    compile_cmd += ' {0}/{1}.o'.format(objectfile_directory ,file)
cmds.append(['Building application', compile_cmd])
cmds.append(['Moving application to {0}/'.format(output_directory), 'move {0}.exe {1}/'.format(app_name, output_directory)])

# Actually running the commands
for description, cmd in cmds:
    print('{} . . .'.format(description))
    if system(cmd) != 0:
        print('Error!')
        system('del /F /Q *.o')
        exit(1)

# If everything worked, then clear screen and run app
print('Successful')
system('pause')
system('cls')
system('.\\bin\\{0}'.format(app_name))