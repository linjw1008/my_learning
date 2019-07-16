class trashType(object):
    
    def __init__(self, txt_dir):
        self.list = []
        with open(txt_dir, 'r') as f:
            text = f.readlines()  
            for line in text:
                t = line.split()        
                self.list.append(t)
        print(self.list)
        self.type = ['recyclable trash', 'dry trash', 'wet trash', 'harmful trash']

    def getTrashType(self, trash_name):
        i = 0
        for names in self.list:
            if trash_name in names:
                return self.type[i]
            i += 1