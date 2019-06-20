#!/usr/bin/env python
# coding: utf-8

# In[39]:


#pandas库的常用操作

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns


# In[2]:


step_data = [1, 1, 1, 1, 2, 3]
step_counts = pd.Series(step_data, name = 'step')
print(step_counts)


# In[3]:


step_counts.index = pd.date_range('20150329', periods = 6)
print(step_counts)


# In[4]:


print(step_counts['2015-03-29'])


# In[5]:


print(step_counts[0])


# In[6]:


print(step_counts['2015-03'])


# In[7]:


print(step_counts.dtypes)


# In[8]:


step_counts = step_counts.astype(np.float)
print(step_counts.dtypes)


# In[9]:


step_counts[1:3] = np.NaN
step_counts = step_counts.fillna(0.0000)
print(step_counts)


# In[10]:


cycling_data = [10, 10, 9, None]
joined_data = list(zip(step_data, cycling_data))


# In[11]:


activity_df = pd.DataFrame(joined_data)
print(activity_df)


# In[12]:


activity_df = pd.DataFrame(joined_data, index = pd.date_range('20150329', periods = 4), columns = ['Walking', 'Cycling'])
print(activity_df)


# In[13]:


print(activity_df.loc['2015-03-29'])


# In[14]:


print(activity_df.iloc[3])


# In[15]:


print(activity_df['Walking'])


# In[16]:


print(activity_df.Walking)


# In[17]:


print(activity_df.iloc[:,0])


# In[18]:


print(activity_df.iloc[:,1])


# In[19]:


print(activity_df.iloc[3,:])


# In[20]:


filepath = 'D:\linjw\AI-contest\dataSet\course1\data\Iris_Data.csv'
data = pd.read_csv(filepath)
print(data.iloc[:,4])


# In[21]:


data['sepal_area'] = data.sepal_length*data.sepal_width
print(data.iloc[:5,-4:])


# In[22]:


data['abbrev'] = (data.species.apply(lambda x: x.replace('Iris-','')))
print(data.abbrev)


# In[23]:


small_data = pd.concat([data.iloc[:2],data.iloc[-2:]])
print(small_data.iloc[:,:])


# In[24]:


#使用groupby方法进行聚合统计计算
group_sizes = (data.groupby('species').size())
print(group_sizes)


# In[25]:


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


# In[26]:


#随机取样
sample = (data.sample(n = 5, replace = False, random_state = 42))
print(sample)


# In[32]:


#利用Matplotlib绘制散点图
plt.figure(1)
plt.plot(data.sepal_length, data.sepal_width, ls = '', marker = 'o', label = 'sepal')
plt.plot(data.petal_length, data.petal_width, ls = '', marker = 'o', label = 'petal')


# In[35]:


#利用Matplotlib绘制直方图
plt.figure(2)
plt.hist(data.sepal_length, bins = 25)


# In[46]:


#定制化Matplotlib绘图
plt.figure(3)
flg, ax = plt.subplots()
ax.barh(np.arange(10), data.sepal_width.iloc[:10])
ax.set_yticks(np.arange(0.4, 10.4, 1.0))
ax.set(xlabel = 'xlabel', ylabel = 'ylabel', title = 'Title')


# In[38]:


#利用Pandas进行绘图，基于Matplotlib
plt.figure(4)
data.groupby('species').mean().plot(color = ['red', 'blue', 'green'], fontsize = 10.0, figsize = (4, 4))


# In[42]:


#利用Seaborn绘图
#创建联合分布和散点图
plt.figure(5)
sns.jointplot(x = 'sepal_length', y = 'sepal_width', data = data, height = 4)


# In[47]:


#绘制变量之间的关联图
plt.figure(6)
sns.pairplot(data, hue = 'species', height = 3)


# In[ ]:




