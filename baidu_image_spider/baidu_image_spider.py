import sys
import os
import re
import requests
from bs4 import BeautifulSoup
import argparse

def main():
    parser = argparse.ArgumentParser(description = 'This script downloads image from image.baidu.com.')
    parser.add_argument('-k', '--keyword', type = str, nargs = '+', help = 'The keywords of images that users want to download.') 
    parser.add_argument('-d', '--dir', type = str, help = 'The dir that is used to save images. Default: ./image.', default = './image')
    parser.add_argument('-n', '--num', type = int, help = 'The maximum number of each keyword\'s iamges to be downloaded. It had better to be the times of 60. Default: 10.', default = 60)
    args = parser.parse_args()
    max_num = args.num
    save_dir = args.dir
    keywords = args.keyword

    for keyword in keywords:
        download_baidu_image(keyword, save_dir + '/' + keyword, max_num)


def download_baidu_image(keyword, save_dir, max_num):
    pn = 0;
    while pn < max_num:
        url = 'https://image.baidu.com/search/flip?tn=baiduimage&ie=utf-8&word=' + keyword + '&pn=' + str(pn) + '&gsm=3c&ct=&ic=0&lm=-1&width=0&height=0'
        html = get_html(url)
        image_url_list = get_image_url_list(html)
        download_image(image_url_list, save_dir, pn, keyword)
        pn += 60 

def get_html(url):
    try:
        html = requests.get(url, timeout = 10)
    except requests.exceptions.ConnectionError:
        print('[get_html]Error: url ' + url + 'connected failed!!!')
        return
    html.encoding = html.apparent_encoding
    result = html.text
    return result

def get_image_url_list(html):
    image_url_list = []
    url_list = re.findall(r'"objURL":"(.*?)"', html, re.S)
    for url in url_list:
        image_url_list.append(url)
        print('[get_image_url_list]Info: find image url ' + url)
    return image_url_list

def download_image(image_url_list, dir, iamge_name_begin_num, iamge_name):
    if not os.path.exists(dir):
        os.makedirs(dir)
    i = iamge_name_begin_num
    for url in image_url_list:
        print('[download_iamge]Info: downloading picture ' + url)
        try:
            pic = requests.get(url, timeout = 10)
        except:
        # except requests.exceptions.ConnectionError:
            print('[download_iamge]Error: download picture ' + url + ' failed!!')
            continue
        save_dir = dir + '/' + iamge_name + '_' + str(i) + '.jpeg'
        fp = open(save_dir, 'wb')
        fp.write(pic.content)
        fp.close()
        i = i + 1

main()