# vctutorial_V.0.1
vctutorial_V is a product was developed during my training at vectorcamp.
# Description
The V0.1 includes the vectorization of the following algorithms:<br />
    src/Maths: in folder Maths included the vectorized versions of the, dot product calculation, min and max value search as well as comparisons.
    Furthermore, file with test names include init test of all above.<br /><br />
    src/memman: in folder memman(memory manipulation) included the vectorized versions of memcpy, memset and memchr as well as their init tests.<br /><br />
    src/Linear_Algebra: in this folder the vectorized versions and tests of matrix transposure, additiona and multiplication was indcluded.<br /><br />
    src/Prints: this folder includes the print functions of the project with aim to help me in the debuging proccess.<br /><br />
    src/include: this folder includes all header files.<br /><br />
    src/Benchmarks: last but not least, this folder includes all benchmarks with aim to illustate the optimization of any algorithm.<br /><br />
    Makefile: file which build the project.
    
# Instalation
With aim to run the project you have to install:<br />
1 - c++ compiler: $ sudo apt install build-essential<br /><br />

With aim to run plots of benchmarks:<br />
2 - python language: sudo apt istall python3.8 (usualy python is preinstalled in ubuntu)<br />
2.1 - matplotlib: pip3 install matplotlib.<br /><br />
(If you do not want to plot benchmarks just remove the -DWITHOUT_NUMPY -I/usr/include/python3.8 from CXXFLAGS and -lpython3.8 from LBFLAGS in makefile)

