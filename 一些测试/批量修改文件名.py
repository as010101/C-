def findTypeFileNotNone(rootdir):
    '''
    1.遍历文件夹中非空的文件  2.修改文件名字  3.统计文件内同行数  4.记录信息到文件中
    :param rootdir: 文件根目录
    :return: 
    '''
    for parent, dirnames, filenames in os.walk(rootdir):  # 三个参数：分别返回1.父目录 2.所有文件夹名字（不含路径） 3.所有文件名字

        for dir in dirnames:
             for parent, dirnames, filenames in os.walk(rootdir+'\\'+dir):
                 print(filenames)
                 for ele in filenames:
                     os.rename(rootdir+'\\'+dir+'\\'+ele, rootdir+'\\'+dir+'\\'+'lev2_'+ele[0:6]+'_'+dir+'.csv')



if __name__ == '__main__':
    findTypeFileNotNone('D:\A-ZIP2')
