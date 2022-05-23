'''
*Universidad Sergio Arboleda
*Autor: Oscar Julian Reyes Torres
Computación Paralela y Distribuida
'''
from distutils.core import setup, Extension
from Cython.Build import cythonize

exts = (cythonize('heatCython.pyx'))

setup(ext_modules=exts)
