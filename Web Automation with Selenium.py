from selenium import webdriver

#used to Chrome
browser = webdriver.Chrome("C:\\Users\\Abhishek Kumar\\Downloads\\chromedriver_win32\\chromedriver.exe")

browser.get("https://codechef.com") #used for opening any particular URL.


#using inspect find username, password and Login html code noted everyone's id
username_element = browser.find_element_by_id("edit-name")

username_element.send_keys("abhishek_2k18") #Text will get copied

password_element = browser.find_element_by_id("edit-pass")

#you can take password from send_keys but in this method password will be shown
#so you this method when you are using handling with password stuff
from getpass import getpass

password_element.send_keys(getpass("Enter Password : ")) 

login_element = browser.find_element_by_id("edit-submit")

login_element.click() #It will click the button

browser.get("https://www.codechef.com/submit/ICM2007")

browser.find_element_by_id("edit_area_toggle_checkbox_edit-program").click()
#Again inspect all ide(Toggle editor uncheck), language and
#submit Button noted all id names of all these
with open("C:\\Users\\Abhishek Kumar\\Downloads\\solution.cpp") as f:
    code = f.read()
code_element = browser.find_element_by_id('edit-program')

code_element.send_keys(code)

browser.find_element_by_id("edit-submit-1").click()

#How to change language path
#on option tag right click copy xpath
# then 
#browser.find_element_by_xpath('//*[@id="edit-language"]/option[10]').click()
#here x-path is of editor