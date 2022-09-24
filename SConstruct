env = Environment(CXXFLAGS=['/O2', '/W1'])

sdl_include = 'C:\\Program Files (x86)\\SDL2\\include'
sdl_lib = 'C:\\Program Files (x86)\\SDL2\\lib'
sdl_libs = ['C:\\Program Files\ (x86)\\SDL2\\lib\\SDL2.lib', 'C:\\Program Files (x86)\\SDL2\\lib\\SDL2_test.lib', 'C:\\Program Files (x86)\\SDL2\\lib\\SDL2main.lib', 'C:\\Program Files (x86)\\SDL2\\lib\\SDL2-static.lib']
sdl_bin = 'C:\\Program Files (x86)\\SDL2\\bin'

env.Append(CPPPATH=sdl_include, LIBS=['SDL2main', 'SDL2', 'SDL2_test'], LIBPATH=[sdl_lib])
env.Append(LINKFLAGS=['/SUBSYSTEM:CONSOLE'])

env.Program('sdl_windows_test',Glob('*.cpp'))

env.Install('.',env.Glob(sdl_bin+"/*.dll"))
