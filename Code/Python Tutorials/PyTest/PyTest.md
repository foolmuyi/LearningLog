- [PyTest Documentation](#pytest-documentation)
  - [Get Started](#get-started)
    - [Create your first test](#create-your-first-test)
    - [Run multiple tests](#run-multiple-tests)
    - [Assert that a certain exception is raised](#assert-that-a-certain-exception-is-raised)
    - [Group multiple tests in a class](#group-multiple-tests-in-a-class)


# PyTest Documentation

## Get Started

### Create your first test

```Python
def func(x):
    return x + 1


def test_answer():
    assert func(3) == 5
```

```Shell
$ pytest
=========================== test session starts ============================
platform linux -- Python 3.x.y, pytest-7.x.y, pluggy-1.x.y
rootdir: /home/sweet/project
collected 1 item

test_sample.py F                                                     [100%]

================================= FAILURES =================================
_______________________________ test_answer ________________________________

    def test_answer():
>       assert func(3) == 5
E       assert 4 == 5
E        +  where 4 = func(3)

test_sample.py:6: AssertionError
========================= short test summary info ==========================
FAILED test_sample.py::test_answer - assert 4 == 5
============================ 1 failed in 0.12s =============================
```

### Run multiple tests

简单地说，`pytest`会执行当前文件夹及其子文件夹中所有的 test_*.py文件和 *_test.py文件，对于这些文件，会执行的测试项为其中名称含有test前缀的函数（例如`test_answer()`）。更详细的规则见[官方文档](https://docs.pytest.org/en/7.4.x/explanation/goodpractices.html#test-discovery)。

### Assert that a certain exception is raised

使用PyTest的`raises`方法来捕捉特定的异常。

```Python
import pytest


def f():
    raise SystemExit(1)


def test_mytest():
    with pytest.raises(SystemExit):
        f()
```

```Shell
$ pytest -q test_sysexit.py
.                                                                    [100%]
1 passed in 0.12s
```

注意：`-q/--quiet`参数的作用是简化输出结果。

### Group multiple tests in a class

