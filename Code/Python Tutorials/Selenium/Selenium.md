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
  - [显式等待](#显式等待)
    - [等待条件](#等待条件)
    - [自定义等待条件](#自定义等待条件)
  - [隐式等待](#隐式等待)
- [页面对象](#页面对象)
  - [测试用例](#测试用例)
  - [页面对象类](#页面对象类)
- [WebDriver API](#webdriver-api)
- [FAQ](#faq)
- [实用小技巧](#实用小技巧)


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

现在越来越多的网站使用了AJAX技术，这使得WebDriver不能很准确地判断网页是否加载完毕，因此Selenium提供显式等待和隐式等待两种方式来进行辅助。

## 显式等待

显示等待就是我们指定一个条件，等待条件满足后再继续执行后面的程序，最简单的显示等待方式无疑就是`time.sleep()`。在网页操作中，为了尽可能提高效率，我们可以使用`WebDriverWait`和`expected_conditions`来表达我们的等待条件并等待其满足，比如最常见的等网页加载可以转化为等待某一个元素出现，下面是一个例子：

```Python
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.wait import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException

driver = webdriver.Firefox()
driver.get("http://somedomain/url_that_delays_loading")
try:
    element = WebDriverWait(driver, 10).until(
        EC.presence_of_element_located((By.ID, "myDynamicElement"))
    )
except TimeoutException:
    print('Timeout...')
finally:
    driver.quit()
```

在上面的例子中，`WebDriverWait`会等待ID为`myDynamicElement`的元素出现（默认每500毫秒查找一次）然后再继续，最多等待10秒，如果超过10秒还是没有找到则报`TimeoutException`异常。

### 等待条件

这里的等待条件即`expected_conditions`，Selenium已经预定义了很多常用的条件，我们只要`from selenium.webdriver.support import expected_conditions`然后直接使用即可，详细的使用文档见[Expected conditions Support](https://selenium-python.readthedocs.io/api.html#module-selenium.webdriver.support.expected_conditions)。

- `title_is`
- `title_contains`
- `presence_of_element_located`
- `visibility_of_element_located`
- `visibility_of`
- `presence_of_all_elements_located`
- `text_to_be_present_in_element`
- `text_to_be_present_in_element_value`
- `frame_to_be_available_and_switch_to_it`
- `invisibility_of_element_located`
- `element_to_be_clickable`
- `staleness_of`
- `element_to_be_selected`
- `element_located_to_be_selected`
- `element_selection_state_to_be`
- `element_located_selection_state_to_be`
- `alert_is_present`

### 自定义等待条件

如果上面Selenium预定义的等待条件还不够用，也可以自定义等待条件，基本格式是一个包含`__call__`方法（在条件不满足时返回`False`）的类，下面是一个例子：

```Python
class element_has_css_class(object):
  """An expectation for checking that an element has a particular css class.

  locator - used to find the element
  returns the WebElement once it has the particular css class
  """
  def __init__(self, locator, css_class):
    self.locator = locator
    self.css_class = css_class

  def __call__(self, driver):
    element = driver.find_element(*self.locator)   # Finding the referenced element
    if self.css_class in element.get_attribute("class"):
        return element
    else:
        return False

# Wait until an element with id='myNewInput' has class 'myCSSClass'
wait = WebDriverWait(driver, 10)
element = wait.until(element_has_css_class((By.ID, 'myNewInput'), "myCSSClass"))
```

## 隐式等待

所谓隐式等待其实就是设置一个超时时间，WebDriver会在这个时间内不停去查找指定元素，若超时还未找到就抛出异常。这个超时时间是对WebDriver实例设置的，在该实例的整个生命周期内有效，下面是一个例子：

```Python
from selenium import webdriver

driver = webdriver.Firefox()
driver.implicitly_wait(10) # seconds
driver.get("http://somedomain/url_that_delays_loading")
myDynamicElement = driver.find_element_by_id("myDynamicElement")
```

# 页面对象

本章是针对页面对象设计模式的一个简单介绍。
页面对象设计模式的好处：
- 测试用例的可读性好；
- 代码复用性好，可在多个测试用例中使用；
- 减少重复的代码；
- 如果用户界面发生改动，只需修改很少的代码。

## 测试用例

下面的代码是在python.org上查找一个词的测试用例。

```Python
import unittest
from selenium import webdriver
import page

class PythonOrgSearch(unittest.TestCase):
    """A sample test class to show how page object works"""

    def setUp(self):
        self.driver = webdriver.Firefox()
        self.driver.get("http://www.python.org")

    def test_search_in_python_org(self):
        """Tests python.org search feature. Searches for the word "pycon" then
        verified that some results show up.  Note that it does not look for
        any particular text in search results page. This test verifies that
        the results were not empty."""

        #Load the main page. In this case the home page of Python.org.
        main_page = page.MainPage(self.driver)
        #Checks if the word "Python" is in title
        self.assertTrue(main_page.is_title_matches(), "python.org title doesn't match.")
        #Sets the text of search textbox to "pycon"
        main_page.search_text_element = "pycon"
        main_page.click_go_button()
        search_results_page = page.SearchResultsPage(self.driver)
        #Verifies that the results page is not empty
        self.assertTrue(search_results_page.is_results_found(), "No results found.")

    def tearDown(self):
        self.driver.close()

if __name__ == "__main__":
    unittest.main()
```

## 页面对象类

页面对象模式为每个网页创建一个对象，从而将测试代码和具体的网页操作代码分开。比如在上面的例子中我们用到的`page`模块大概长这样：

```Python
from element import BasePageElement
from locators import MainPageLocators

class SearchTextElement(BasePageElement):
    """This class gets the search text from the specified locator"""

    #The locator for search box where search string is entered
    locator = 'q'


class BasePage(object):
    """Base class to initialize the base page that will be called from all
    pages"""

    def __init__(self, driver):
        self.driver = driver


class MainPage(BasePage):
    """Home page action methods come here. I.e. Python.org"""

    #Declares a variable that will contain the retrieved text
    search_text_element = SearchTextElement()

    def is_title_matches(self):
        """Verifies that the hardcoded text "Python" appears in page title"""

        return "Python" in self.driver.title

    def click_go_button(self):
        """Triggers the search"""

        element = self.driver.find_element(*MainPageLocators.GO_BUTTON)
        element.click()


class SearchResultsPage(BasePage):
    """Search results page action methods come here"""

    def is_results_found(self):
        # Probably should search for this text in the specific page
        # element, but as for now it works fine
        return "No results found." not in self.driver.page_source
```

同理，上面代码中的`element`模块大概长这样：

```Python
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait


class BasePageElement(object):
    """Base page class that is initialized on every page object class."""

    def __set__(self, obj, value):
        """Sets the text to the value supplied"""

        driver = obj.driver
        WebDriverWait(driver, 100).until(
            lambda driver: driver.find_element(By.NAME, self.locator))
        driver.find_element(By.NAME, self.locator).clear()
        driver.find_element(By.NAME, self.locator).send_keys(value)

    def __get__(self, obj, owner):
        """Gets the text of the specified object"""

        driver = obj.driver
        WebDriverWait(driver, 100).until(
            lambda driver: driver.find_element(By.NAME, self.locator))
        element = driver.find_element(By.NAME, self.locator)
        return element.get_attribute("value")
```

`locators`模块长这样：

```Python
from selenium.webdriver.common.by import By

class MainPageLocators(object):
    """A class for main page locators. All main page locators should come here"""

    GO_BUTTON = (By.ID, 'submit')

class SearchResultsPageLocators(object):
    """A class for search results locators. All search results locators should
    come here"""

    pass
```

# WebDriver API

Selenium WebDriver提供了非常丰富的API，在此不可能一一介绍，详细信息请参考[官方API文档](https://www.selenium.dev/selenium/docs/api/py/api.html)。

# FAQ

- 如何下载安装WebDriver？
  从[安装WebDriver](#安装webdriver)中给出的链接下载WebDriver文件后，解压得到可执行文件，然后将可执行文件放到`PATH`路径下，或者在实例化WebDriver时指明可执行文件的路径，例如：`driver = webdriver.Chrome(executable_path="/path/to/chromedriver")`

- 如何滚动到页面的底部？
  调用`execute_script`方法执行javascript：
  `driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")`

- 如何上传文件？
  找到`<input type="file">`元素并调用`send_keys()`方法发送文件路径，绝对路径和相对路径都可以，但是请注意Windows系统和Unix系统路径的区别。

- 如何截屏当前页面？
  使用`save_screenshot()`方法：
  `driver.save_screenshot('screenshot.png')`

# 实用小技巧

- 根据显示的文本快速定位元素
  对于按钮这样的元素，可以考虑根据按钮上的文字来定位，好处是代码简单清晰明了，坏处是不能兼容多语言，方法如下：
  ```html
  <button class="mm-box mm-text mm-button-base mm-button-base--size-md
  mm-button-base--block mm-button-primary mm-text--body-md-medium
  mm-box--padding-0 mm-box--padding-right-4 mm-box--padding-left-4
  mm-box--display-inline-flex mm-box--justify-content-center
  mm-box--align-items-center mm-box--color-primary-inverse
  mm-box--background-color-primary-default mm-box--rounded-pill"
  type="submit">创建</button>
  ```
  对于上面这段html，可以用`driver.find_element(By.XPATH, '//button[normalize-space()="创建"]')`来定位元素。实际上不局限于`button`类型，其他类型也可以，例如`driver.find_element(By.XPATH, '//p[normalize-space()="发送"]')`。

- `class`属性值包含空格导致不能用`By.CLASS_NAME`定位
  改用`By.CSS_SELECTOR`，把空格替换成`.`即可。

- 想用一些非常规的属性来定位怎么办
  类似于上面用文本定位按钮的方式，只不过把`[]`里换成`[@var_name="value"]`的格式即可，例如：
  ```html
  <button class="mm-box mm-button-icon mm-button-icon--size-sm
  mm-box--display-inline-flex mm-box--justify-content-center
  mm-box--align-items-center mm-box--color-icon-default
  mm-box--background-color-transparent mm-box--rounded-lg" aria-label=
  账户选项" data-testid="account-options-menu-button"><span
  class="mm-box mm-icon mm-icon--size-sm mm-box--display-inline-block
  mm-box--color-inherit" style="mask-image: url(&quot;./images/icons
  more-vertical.svg&quot;);"></span></button>
  ```
  对于上面这段html，如果为了代码看起来简介明了想用`aria-label`属性来定位`button`，可以写成`driver.find_element(By.XPATH, '//button[@aria-label="账户选项"]')`。