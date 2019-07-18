class trashType(object):
    
    def __init__(self, txt_en_dir, txt_cn_dir):
        self.list_en = []
        self.list_cn = []
        self.dict = {}
        with open(txt_en_dir, 'r') as f:
            text = f.readlines()  
            for line in text:
                t = line.split()        
                self.list_en.append(t)
        with open(txt_cn_dir, 'r') as f:
            text = f.readlines()  
            for line in text:
                t = line.split()        
                self.list_cn.append(t)
        i = 0
        j = 0
        for line in self.list_en:
            j = 0
            for item in line:
                self.dict[item] = self.list_cn[i][j]
                j = j + 1
            i = i + 1                 
        print(self.list_en)
        print(self.list_cn)
        print(self.dict)
        self.type_en = ['recyclable trash', 'dry trash', 'wet trash', 'harmful trash']
        self.type_cn = ['可回收垃圾', '干垃圾', '湿垃圾', '有害垃圾']

    def getTrashType(self, trash_name):
        i = 0
        for names in self.list_en:
            if trash_name in names:
                return self.type_en[i]
            i += 1

    def getTrashNameInChinese(self, trash_name):
        return self.dict[trash_name]
    
    def getTrashTypeInChinese(self, trash_type):
        return self.type_cn[self.type_en.index(trash_type)]