
# coding: utf-8

# In[3]:


PVPostfix = ".PV_Out#Value"
AWPostfix = ['.PV_AH_Lim', '.PV_WH_Lim', '.PV_WL_Lim', '.PV_AL_Lim']
OutputPVsArr = []
OutputPVArr = []
OutputAWArr = []
OutputVar=[]

with open('TagNames.txt','r') as f:
    PrefixArr = [line.strip() for line in f]

for i in range(0,len(PrefixArr),1):
    OutputPVsArr.append(PrefixArr[i]+PVPostfix)
    for j in range(0,len(AWPostfix),1):
        OutputAWArr.append(PrefixArr[i]+AWPostfix[j])
        OutputPVArr.append(PrefixArr[i]+PVPostfix)
        
with open('OutTagPV.txt','w') as f:
    for i in range(0,len(OutputPVArr),1):
        f.write(OutputPVArr[i] + '\n')
        
with open('OutTagPVs.txt','w') as f:
    for i in range(0,len(OutputPVsArr),1):
        f.write(OutputPVsArr[i] + '\n')
        
with open('OutTagWH.txt','w') as f:
    for i in range(0,len(OutputPVArr),1):
        f.write(OutputAWArr[i] + '\n')     

