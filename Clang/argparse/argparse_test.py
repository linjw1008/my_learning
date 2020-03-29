import argparse

# 创建一个解析器
# 并定义了帮助文档内容
parser = argparse.ArgumentParser(description = 'Process some integers.')

# 给解析器添加参数
# 添加一个名为“echo”的参数，positional arguments，必选参数
parser.add_argument("echo")
# 添加一个可选参数
# 通过-或--来指定，可以共存
parser.add_argument('-v', '--verbosity', help = "increase output verbosity")
# 添加一个可选参数
# 不需要指定参数值
parser.add_argument('-l', '--lin', help = "test", action = "store_true")
# 添加一个可选参数
# 指定参数的类型
parser.add_argument('x', type = int, help = "the base")
# 添加一个可选参数
# 指定可选值
parser.add_argument('-j', '--jw', type = int, choices = [0, 1, 2], help = "chose a value from 0, 1, 2")
# 定义互斥参数，不可同时出现
# 定义一个互斥组
group = parser.add_mutually_exclusive_group()
group.add_argument('-d', '--ddd', action = "store_true")
group.add_argument('-q', '--qqq', action = "store_true")
# 定义一个可选参数
# 指定默认值
parser.add_argument('-a', '-aaa', default = 1)
args = parser.parse_args()
answer = args.x ** 2
print(args.echo)
if args.verbosity:
    print("verbosity turned on")
    print(args.verbosity)
if args.lin:
    print("lin turned on")
    print(args.lin)
print(answer)
if args.jw:
    print("jw turned on")
    print(args.jw)
if args.ddd:
    print('ddd turned on')
if args.qqq:
    print('qqq turned on')
print(args.a)
# 解析参数
#parser.parse_args(['--sum', '7', '-1', '42'])