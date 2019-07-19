import os
import argparse
import re
from PIL import Image
from PIL import ImageFile

ImageFile.LOAD_TRUNCATED_IMAGES = True

parser = argparse.ArgumentParser(description = 'This script changes the format of images.')
parser.add_argument('-od', '--opendir', type = str, help = 'The dir of iamges to be changed format from.')
parser.add_argument('-sd', '--savedir', type = str, help = 'The dir of changed iamges to be saved in.')
parser.add_argument('-n', '--name', type = str, help = 'The name of iamges to be saved with.')
parser.add_argument('-w', '--width', type = str, help = 'The width of images.')
parser.add_argument('-H', '--height', type = str, help = 'The height of images.')
args = parser.parse_args()
image_dir = args.opendir
save_dir = args.savedir
name = args.name
width = float(args.width)
height = float(args.height)

image_list = os.listdir(image_dir)

if not os.path.exists(save_dir + '/' + name):
        os.makedirs(save_dir + '/' + name)

i = 0
    
for image in image_list:
    print(image)
    try:
        img = Image.open(image_dir + '/' + image)
    except:
        print('File ' + image + ' open failed! It is deleted now.')
        os.remove(image_dir + '/' + image)
        continue
    img = img.convert("RGB")
        
        
    (x, y) = img.size
    if float(x/y) > float(width/height):
        region = (int(float(x)/2 - (width/height*float(y))/2), 0, int(float(x)/2 + (width/height*float(y))/2), y)
    elif float(x/y) < float(width/height):
        region = (0, int(float(y)/2 - (height/width*float(x))/2), x, int(float(y)/2 + (height/width*float(x))/2))
    else:
        region = (0, 0, x, y)
    
    img = img.crop(region)
    
    img = img.resize((int(width), int(height)))

    image_path = image_dir + '/' + image
    #os.remove(image_path)
    save_path = save_dir + '/' + name + '/' + str(name) + str(i) 
    img.save(save_path + '.jpeg', 'jpeg')
    i = i + 1