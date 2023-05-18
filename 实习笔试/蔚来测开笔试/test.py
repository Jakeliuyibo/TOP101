
# # 冒泡排序
# def bubble(num):
#     n = len(num)

#     for ii in range(n):
#         for jj in range(n-1):
#             if num[jj] > num[jj+1]:
#                 tmp = num[jj+1]
#                 num[jj+1] = num[jj]
#                 num[jj]   = tmp

#     return num

# # 输入
# nums = [1,3,2,4,5,7,6]

# # 冒泡
# nums_sort = bubble(nums)
# for num in nums_sort:
#     print(f"{num} ")

# 输入
# str = "sjdkfabsjdfksabsdjfklsdfjlabsjdfklsfjabasjdkflabab"
str = "abcab"


n = len(str)       #  长度
for left in range(n,-1,-1):
    for right in range(n-1,-1,-1):
        # 截取字符串
        substr = str[left: right]
        print(f" sub = {substr}  ")

        if str.count(substr) > 1:
            print(f"rm {left}-{right}")
            # str[left: right] = "x"
    
# 输出
print(f"{str} ")