import numpy as np
import matplotlib as plt
from PIL import Image

with open('final.png', 'rb') as f:
    img = f.read()
    arr = bytearray(img)

print(len(arr))
