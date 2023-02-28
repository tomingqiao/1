# -*- coding: utf-8 -*-
from selenium import webdriver
from selenium.webdriver.support import expected_conditions as EC
import time

driver = webdriver.Chrome()
driver.get("https://ua.ulearning.cn/learnCourse/learnCourse.html?courseId=33998&chapterId=100876105&classId=485150&returnUrl=https%3A%2F%2Fcourseweb.ulearning.cn%2Fulearning%2Findex.html%23%2Fcourse%2Ftextbook%3FcourseId%3D96039") #输入你要的网址
#driver.switch_to.frame("iframeResult")
num=1000     #我只设置了点击10次弹窗
while(num):
    result = EC.alert_is_present()(driver)    #检测是否有弹窗
    if result:								  #当有弹窗时
        al = driver.switch_to_alert()		  #获取弹窗的位置
        time.sleep(1)
        al.accept()							  #点击弹窗的确定按钮
        num=num-1
        print(num)