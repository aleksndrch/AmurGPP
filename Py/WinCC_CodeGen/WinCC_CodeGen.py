
# coding: utf-8

# In[16]:


MBTag = []
StructTag = []

with open('MBTag.txt','r') as f:
    MBTag = [line.strip() for line in f]
    
with open('StructTag.txt','r') as f:
    StructTag = [line.strip() for line in f]
    
with open('COutput.txt','w') as f:
    for i in range(0,len(MBTag),1):
        f.write('//'+ StructTag[i] + '\n')
        f.write('SetTagFloat("' + StructTag[i] + '.PV_Out#Value",(GetTagFloat("' + MBTag[i] + '")));' + '\n')
        f.write('GetTagFloatStateQC("' + MBTag[i] + '",&dwState,&dwQC);' + '\n')
        f.write('if(dwQC != OK){SetTagBit("' + StructTag[i] + '.TagQC",1);}' + '\n')
        f.write('else{SetTagBit("' + StructTag[i] + '.TagQC",0);}' + '\n')


# In[15]:


for i in range(0, len(MBTag), 1):
    print(MBTag[i], '\t', StructTag[i])

