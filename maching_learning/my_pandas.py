#!/usr/bin/env python
# coding: utf-8

# In[10]:


#pandas库的常用操作

import pandas as pd
import numpy as np


# In[2]:


step_data = [1, 1, 1, 1, 2, 3]
step_counts = pd.Series(step_data, name = 'step')
print(step_counts)


# In[3]:


step_counts.index = pd.date_range('20150329', periods = 6)
print(step_counts)


# In[4]:


print(step_counts['2015-03-29'])


# In[6]:


print(step_counts[0])


# In[7]:


print(step_counts['2015-03'])


# In[8]:


print(step_counts.dtypes)


# In[16]:


step_counts = step_counts.astype(np.float)
print(step_counts.dtypes)


# In[20]:


step_counts[1:3] = np.NaN
step_counts = step_counts.fillna(0.0000)
print(step_counts)


# In[22]:


cycling_data = [10, 10, 9, None]
joined_data = list(zip(step_data, cycling_data))


# In[24]:


activity_df = pd.DataFrame(joined_data)
print(activity_df)


# In[28]:


activity_df = pd.DataFrame(joined_data, index = pd.date_range('20150329', periods = 4), columns = ['Walking', 'Cycling'])
print(activity_df)


# In[29]:


print(activity_df.loc['2015-03-29'])


# In[38]:


print(activity_df.iloc[3])


# In[39]:


print(activity_df['Walking'])


# In[40]:


print(activity_df.Walking)


# In[41]:


print(activity_df.iloc[:,0])


# In[42]:


print(activity_df.iloc[:,1])


# In[44]:


print(activity_df.iloc[3,:])


# In[50]:


filepath = 'D:\linjw\AI-contest\dataSet\course1\data\Iris_Data.csv'
data = pd.read_csv(filepath)
print(data.iloc[:,4])


# In[53]:


data['sepal_area'] = data.sepal_length*data.sepal_width
print(data.iloc[:5,-4:])


# In[54]:


data['abbrev'] = (data.species.apply(lambda x: x.replace('Iris-','')))
print(data.abbrev)


# In[56]:


small_data = pd.concat([data.iloc[:2],data.iloc[-2:]])
print(small_data.iloc[:,:])


# In[58]:


#使用groupby方法进行聚合统计计算
group_sizes = (data.groupby('species').size())
print(group_sizes)


# In[64]:


#各种统计方法
#均值
print(data.mean())
#中位数
print(data.median())
#众数
print(data.mode())
#标准差、方差、SEM
print(data.std(),data.var(),data.sem())
#多项统计信息
print(data.describe())


# In[65]:


#随机取样
sample = (data.sample(n = 5, replace = False, random_state = 42))
print(sample)


# In[ ]:




