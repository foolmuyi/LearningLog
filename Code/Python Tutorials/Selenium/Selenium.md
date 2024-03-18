- [安装](#安装)
  - [安装Selenium](#安装selenium)
  - [安装WebDriver](#安装webdriver)
- [快速入门](#快速入门)
- [开始冲浪](#开始冲浪)
  - [网页交互](#网页交互)
  - [标签页与窗口](#标签页与窗口)
  - [弹出对话框](#弹出对话框)
  - [网页前进后退](#网页前进后退)
  - [Cookies](#cookies)
- [查找元素](#查找元素)
  - [ID \& NAME](#id--name)
  - [XPATH](#xpath)
  - [LINK\_TEXT \& PARTIAL\_LINK\_TEXT](#link_text--partial_link_text)
  - [TAG\_NAME](#tag_name)
  - [CLASS\_NAME](#class_name)
  - [CSS\_SELECTOR](#css_selector)
- [等待](#等待)
- [页面对象](#页面对象)
- [WebDriver API](#webdriver-api)
- [FAQ](#faq)


***本文为学习Selenium-Python文档过程中的随手记，完整文档见[Selenium With Python](https://selenium-python.readthedocs.io/index.html)***

# 安装

## 安装Selenium

`pip install selenium`

## 安装WebDriver

常用浏览器的WebDriver下载地址如下表：

| 浏览器 | WebDriver链接 |
| :-: | :- |
| Chrome | https://sites.google.com/chromium.org/driver/ |
| Edge | https://developer.microsoft.com/en-us/microsoft-edge/tools/webdriver/ |
| Firefox | https://github.com/mozilla/geckodriver/releases |

注意：在Ubuntu22.04系统中，由于系统自带的Firefox是通过snap安装的，因此使用当前版本的geckodriver (0.34.0)打开Firefox时会触发报错`Your Firefox profile cannot be loaded. It may be missing or inaccessible`，此问题为已知bug。目前的解决方法为卸载snap安装的Firefox，然后按照[官方教程](https://support.mozilla.org/zh-CN/kb/install-firefox-linux?utm_source=www.mozilla.org&utm_medium=referral&utm_campaign=firefox-download-thanks#w_shi-yong-ji-yu-debian-fa-xing-ban-de-deb-bao-an-zhuang-firefox)使用apt安装。需要说明的是，直接使用`sudo apt install firefox`安装仍然是使用snap安装的，要强制使用apt安装需要按上述教程一步一步操作。

# 快速入门

一个简单的例子
```Python
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By

driver = webdriver.Firefox()
driver.get("http://www.python.org")
assert "Python" in driver.title
elem = driver.find_element(By.NAME, "q")
elem.clear()
elem.send_keys("pycon")
elem.send_keys(Keys.RETURN)
assert "No results found." not in driver.page_source
driver.close()
```

下面对例子中不太容易理解的部分稍加解释。
`from selenium.webdriver.common.keys import Keys` 使用浏览器时少不了键盘操作，`Keys`类就是提供键盘按键的，例如*回车*、*F1*、*ALT*等。
`from selenium.webdriver.common.by import By` Selenium提供了多种查找元素的方法，这些方法定义在`By`类里面，比如在这个例子中我们使用了`By.NAME`的方法来按照`name`属性查找元素。
`elem.clear()` 由于此处的对象是一个输入框，安全起见在输入内容前我们先清空一下输入框，以免其中有默认内容。
`driver.close()` 关闭当前标签页。如果当前只有一个标签页，大部分浏览器的默认操作是关闭浏览器。也可以使用`driver.quit()`来直接关闭浏览器。

# 开始冲浪

冲浪第一步，先用`get`方法获取网页。例如
`driver.get('https://www.google.com/')`
WebDriver将会等待页面加载完成（实际上是等待`onload`事件完成）再执行后续代码，但是当页面有太多AJAX需要加载时，WebDriver可能会不知道页面是否加载完毕，这种情况下如果需要确保页面加载完毕，需要用到后续[等待](#等待)章节的内容。

## 网页交互

Selenium提供了多种方式来定位页面上的元素，例如，对于这个元素：
`<input type="text" name="passwd" id="passwd-id" />`
可以通过以下几种方式来定位：
```Python
element = driver.find_element(By.ID, "passwd-id")
element = driver.find_element(By.NAME, "passwd")
element = driver.find_element(By.XPATH, "//input[@id='passwd-id']")
element = driver.find_element(By.CSS_SELECTOR, "input#passwd-id")
```

## 标签页与窗口

在浏览器中操作时，我们往往需要打开多个标签页或者窗口，Selenium提供了一系列方法来进行此类操作。WebDriver其实不区分标签页和窗口，因为WebDriver的操作都是针对每一个标签页的，每一个标签页都有单独的句柄，不管它们在不在同一个窗口，因此方法名称中的`window`其实应该理解为标签页。

```Python
driver.switch_to.new_window('tab')    #打开并切换到一个新的标签页
driver.switch_to.new_window('window')    # 打开并切换到一个新的窗口
driver.current_window_handle    # 获取当前标签页的句柄
driver.switch_to.window(window_handle)    # 切换标签页
driver.close()    # 关闭当前标签页
driver.quit()    # 关闭浏览器
```

更多关于窗口全屏、最小化等操作见[Window management](https://www.selenium.dev/documentation/webdriver/interactions/windows/#window-management)。

## 弹出对话框

WebDriver也支持对浏览器的弹出对话框进行操作，我们可以使用`alert = driver.switch_to.alert`切换到弹出对话框，然后进行确认、取消、输入内容等操作，具体见[Alerts](https://www.selenium.dev/documentation/webdriver/interactions/alerts/)。

## 网页前进后退

```Python
driver.forward()
driver.back()
```

## Cookies

WebDriver也支持cookies，例如：

```Python
driver.get("http://www.example.com")
cookie = {'name' : 'foo', 'value' : 'bar'}
driver.add_cookie(cookie)
```

除此之外，还支持一系列的cookie操作：

```Python
driver.add_cookie({"name": "key", "value": "value"})    # 添加cookie
driver.get_cookie("foo")    # 获取指定名称的cookie
driver.get_cookies()    # 获取全部cookie
driver.delete_cookie("test1")    # 删除指定名称的cookie
driver.delete_all_cookies()    # 删除全部cookie
```

# 查找元素

Selenium中定位元素的方法是`find_element()`和`find_elements()`，前者返回找到的第一个元素，后者返回一个包含所有符合条件的元素的列表。Selenium支持按照多种属性查找元素，这些属性定义在`By`类里，所以需要`from selenium.webdriver.common.by import By`，具体的属性有：

```Python
ID = "id"
NAME = "name"
XPATH = "xpath"
LINK_TEXT = "link text"
PARTIAL_LINK_TEXT = "partial link text"
TAG_NAME = "tag name"
CLASS_NAME = "class name"
CSS_SELECTOR = "css selector"
```

## ID & NAME

ID和NAME属性不用多说，F12然后检查元素看是否有这两个属性即可。

## XPATH

XPATH需要注意，一个元素的XPATH可以有多种写法，比如绝对路径和相对路径，一般建议写相对于一个有ID或者NAME属性的元素的相对路径，这样不容易因为页面改动而失效。下面是一个例子：

```html
<html>
 <body>
  <form id="loginForm">
   <input name="username" type="text" />
   <input name="password" type="password" />
   <input name="continue" type="submit" value="Login" />
   <input name="continue" type="button" value="Clear" />
  </form>
</body>
</html>
```
对于上面这一段html，表格元素的XPATH可以有以下几种写法：
```Python
# Absolute path (would break if the HTML was changed only slightly)
login_form = driver.find_element(By.XPATH, "/html/body/form[1]")
# First form element in the HTML
login_form = driver.find_element(By.XPATH, "//form[1]")
# The form element with attribute id set to loginForm
login_form = driver.find_element(By.XPATH, "//form[@id='loginForm']")
```
`username`元素也有几种不同写法：
```Python
# First form element with an input child element with name set to username
username = driver.find_element(By.XPATH, "//form[input/@name='username']")
# First input child element of the form element with attribute id set to loginForm
username = driver.find_element(By.XPATH, "//form[@id='loginForm']/input[1]")
# First input element with attribute name set to username
username = driver.find_element(By.XPATH, "//input[@name='username']")
```
由于XPATH的写法比较复杂，确实需要用到时，可以借助一些插件来查看元素的XPATH，比如[xPath Finder](https://addons.mozilla.org/en-US/firefox/addon/xpath_finder)和[XPath Helper](https://chrome.google.com/webstore/detail/hgimnogjllphhhkhlmebbmlgjoejdpjl)

## LINK_TEXT & PARTIAL_LINK_TEXT

这两个属性主要是使我们在查找超链接时可以直接根据文本信息去寻找，更加直观易用。举个栗子：

```html
<html>
 <body>
  <p>Are you sure you want to do this?</p>
  <a href="continue.html">Continue</a>
  <a href="cancel.html">Cancel</a>
</body>
</html>
```
查找Continue：
```Python
continue_link = driver.find_element(By.LINK_TEXT, 'Continue')
continue_link = driver.find_element(By.PARTIAL_LINK_TEXT, 'Conti')
```

## TAG_NAME

tag就是html代码中的`<p>`、`<a>`、`<div>`之类的标签，一般用于在比较整齐的元素中提取出某一类子元素，比如从表格中提取出每一个子元素。还是举个栗子：

```html
<html>
 <body>
  <h1>Welcome</h1>
  <p>Site content goes here.</p>
</body>
</html>
```
查找Welcome:
```Python
heading1 = driver.find_element(By.TAG_NAME, 'h1')
```

## CLASS_NAME

即通过元素的`class`属性来定位元素。直接上栗子：

```html
<html>
 <body>
  <p class="content">Site content goes here.</p>
</body>
</html>
```
```Python
content = driver.find_element(By.CLASS_NAME, 'content')
```

## CSS_SELECTOR

CSS不太懂，要用的时候直接检查元素找到以后右键 -> Copy -> Copy selector吧。随便留个栗子：

```html
<html>
 <body>
  <p class="content">Site content goes here.</p>
</body>
</html>
```
```Python
content = driver.find_element(By.CSS_SELECTOR, 'p.content')
```

# 等待
# 页面对象
# WebDriver API
# FAQ