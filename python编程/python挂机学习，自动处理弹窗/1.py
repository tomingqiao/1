# -*- coding: utf-8 -*-
from selenium import webdriver
from selenium.webdriver.support import expected_conditions as EC
import time

driver = webdriver.Chrome()
driver.get("https://ua.ulearning.cn/learnCourse/learnCourse.html?courseId=33998&chapterId=100876105&classId=485150&returnUrl=https%3A%2F%2Fcourseweb.ulearning.cn%2Fulearning%2Findex.html%23%2Fcourse%2Ftextbook%3FcourseId%3D96039") #������Ҫ����ַ
#driver.switch_to.frame("iframeResult")
num=1000     #��ֻ�����˵��10�ε���
while(num):
    result = EC.alert_is_present()(driver)    #����Ƿ��е���
    if result:								  #���е���ʱ
        al = driver.switch_to_alert()		  #��ȡ������λ��
        time.sleep(1)
        al.accept()							  #���������ȷ����ť
        num=num-1
        print(num)