import pandas as pd 
import numpy as np
import gravedad
import gravedadCy
import time

# Initialized planet for python
earth   = gravedad.Planet()
earth.x = 100e3
earth.y = 300e3
earth.z = 300e3
earth.vx= 2e3
earth.vy= 29.87e3
earth.vz= 0.034e3
earth.m = 5.9736e24

# Initialized planet for cython
earth_Cy   = gravedadCy.Planet()
earth_Cy.x = 100e3
earth_Cy.y = 300e3
earth_Cy.z = 300e3
earth_Cy.vx= 2e3
earth_Cy.vy= 29.87e3
earth_Cy.vz= 0.034e3
earth_Cy.m = 5.9736e24

def execute(time_span = 600, n_steps = 500000):
    initTime    = time.time()
    gravedad.step_time(planet = earth, time_span = time_span, n_steps = n_steps)
    totalTimePy = time.time() - initTime

    initTimeCy = time.time()
    gravedadCy.step_time(planet = earth_Cy, time_span = time_span, n_steps = n_steps)
    totalTimeCy = time.time() - initTimeCy

    return (totalTimePy, totalTimeCy)

n = 0
final_times = []

for _ in range (10):
    py_times, cy_times = [], [] 
    n += 100000

    for _ in range(36):
        temp_execution = execute(n_steps = n)
        py_times.append(temp_execution[0])
        cy_times.append(temp_execution[1])

    final_times.append((n, sum(py_times)/len(py_times), sum(cy_times)/len(cy_times)))

pd.DataFrame(final_times).to_csv('samples.csv',  index_label = "Index", header  = ['n_steps', 'Python', 'Cython'])   
