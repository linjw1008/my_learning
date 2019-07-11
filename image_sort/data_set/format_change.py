import os
import argparse
import re
from PIL import Image
from PIL import ImageFile

ImageFile.LOAD_TRUNCATED_IMAGES = True

parser = argparse.ArgumentParser(description = 'This script changes the format of images.')
parser.add_argument('-d', '--dir', type = str, nargs = '+', help = 'The dir of iamges to be changed format.')
args = parser.parse_args()
image_dir = args.dir

for dir in image_dir:
    image_list = os.listdir(dir)
    for image in image_list:
        print(image)
        try:
            img = Image.open(dir + '/' + image)
        except:
            print('File ' + image + ' open failed! It is deleted now.')
            os.remove(dir + '/' + image)
            continue
        img = img.convert("RGB")
        path = dir + '/' + image
        os.remove(path)
        img.save(path + '.jpeg', 'jpeg')