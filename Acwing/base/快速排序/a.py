# 读取文件 in.txt 的内容
with open('in.txt', 'r') as infile:
    lines = infile.readlines()

# 反转每一行的内容
reversed_lines = [line[::-1] for line in lines]

# 将结果写入文件 out.txt
with open('out.txt', 'w') as outfile:
    outfile.writelines(reversed_lines)

print("内容已反转并写入 out.txt")
