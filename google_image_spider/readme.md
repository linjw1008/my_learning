## 功能

用于爬取相应关键词的谷歌图片。基于icrawler。

## 环境

python 3

## 用法

命令行运行google_image_spider.py文件，输入参数为：
-k(--keyword): 关键词，可同时输入多个关键词，用空格分开
-n(--num)：每个关键词要保存的最大图片数量
-d(--dir)：图片保存目录，默认为程序运行目录下的image文件夹，若无，会自动创建

## 示例

以下例子用于爬取关键词为“塑料瓶”、“废纸”的图片，默认保存目录，每个关键词爬取的最大数量为120张

> python google_image_spider.py -k 塑料瓶 废纸 -n 120

> python google_image_spider.py --keyword 塑料瓶 废纸 --num 120