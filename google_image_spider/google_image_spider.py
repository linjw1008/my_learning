import argparse
from icrawler.builtin import GoogleImageCrawler

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
        print('Start to download the iamges of keyword: ' + keyword)
        google_storage = {'root_dir': save_dir + '/' + keyword}
        google_crawler = GoogleImageCrawler(parser_threads = 4, downloader_threads = 4, storage = google_storage)
        google_crawler.crawl(keyword = keyword, max_num = max_num)

main()