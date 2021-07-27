#!/usr/bin/env python
# coding: utf-8

# Body Mass Index (BMI) is found by taking your weight in kilograms and dividing by the square of your height in meters. The BMI categories are:
# 
# Underweight: <18.5
# 
# Normal weight: 18.5–24.9
# 
# Overweight: 25–29.9
# 
# Obesity: BMI of 30 or greater
# 
# Create a function that will accept weight and height (in kilos, pounds, meters, or inches) and return the BMI and the associated category. Round the BMI to the nearest tenth.
# 
# **Examples**
# 
# BMI("205 pounds", "73 inches") ➞ "27.0 Overweight"
# 
# BMI("55 kilos", "1.65 meters") ➞ "20.2 Normal weight"
# 
# BMI("154 pounds", "2 meters") ➞ "17.5 Underweight"
# 
# **Notes**
# 
# 1 inch = 0.0254 meter
# 
# 1 pound = 0.453592 kilo

# In[1]:


def cal_bmi(s1, s2):
    
    s1list = list(s1.split(' '))
    s2list = list(s2.split(' '))
    bmi = 0
    
    if s1list[-1] == 'kilos' and s2list[-1] == 'meters':
        bmi = float(s1list[0]) / pow(float(s2list[0]), 2)
    elif s1list[-1] == 'pounds' and s2list[-1] == 'meters':
        bmi = (float(s1list[0]) * 0.45) / pow(float(s2list[0]), 2)
    elif s1list[-1] == 'kilos' and s2list[-1] == 'inches':
        bmi = float(s1list[0]) / pow(float(s2list[0])*2.54*(1./100), 2)
    elif s1list[-1] == 'pounds' and s2list[-1] == 'inches':
        bmi = (float(s1list[0]) * 0.45) / pow(float(s2list[0])*2.54*(1./100), 2)
    else:
        bmi = 0
        
    #print(bmi)
        
    if bmi > 0 and bmi <= 18.5:
        return 'Underweight'
    elif bmi > 18.5 and bmi <= 24.9:
        return 'Normal weight'
    elif bmi > 24.9 and bmi <= 29.9:
        return 'Overweight'
    elif bmi > 29.9:
        return 'Obesity'
    else:
        return 'something must be wrong!!!'


# In[2]:


cal_bmi("205 pounds", "73 inches") 


# In[3]:


cal_bmi("55 kilos", "1.65 meters") 


# In[4]:


cal_bmi("154 pounds", "2 meters") 


# In[ ]:




