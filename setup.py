"""Copyright 2024 The excelize Authors. All rights reserved. Use of this source
code is governed by a BSD-style license that can be found in the LICENSE file.

Package excelize-py is a Python port of Go Excelize library, providing a set of
functions that allow you to write and read from XLAM / XLSM / XLSX / XLTM / XLTX
files. Supports reading and writing spreadsheet documents generated by Microsoft
Excel™ 2007 and later. Supports complex components by high compatibility, and
provided streaming API for generating or reading data from a worksheet with huge
amounts of data. This library needs Python version 3.10 or later.
"""

from __future__ import annotations
import sys
from warnings import warn
import os
import shutil
from setuptools import setup
from setuptools.command.install import install

if sys.version_info < (3, 10):
    warn("The minimum Python version supported by excelize is 3.10")
    exit()


class CustomInstallCommand(install):
    def run(self):
        install.run(self)
        os.makedirs(self.install_lib, exist_ok=True)
        for shared_library in [
            "libexcelize.amd64.linux.so",
            "libexcelize.arm64.linux.so",
            "libexcelize.amd64.darwin.dylib",
            "libexcelize.arm64.darwin.dylib",
            "libexcelize.amd64.windows.dll",
            "libexcelize.arm64.windows.dll",
        ]:
            shutil.copy(shared_library, self.install_lib)


setup(
    name="excelize",
    version="0.0.2",
    license="BSD 3-Clause",
    license_files=("LICENSE"),
    description="A Python build of the Go Excelize library for reading and writing Microsoft Excel™ (XLAM / XLSM / XLSX / XLTM / XLTX) spreadsheets",
    long_description=open("README.md").read(),
    long_description_content_type="text/markdown",
    author="xuri",
    author_email="xuri.me@gmail.com",
    maintainer="xuri",
    maintainer_email="xuri.me@gmail.com",
    zip_safe=False,
    project_urls={
        "Source": "https://github.com/xuri/excelize-py",
        "Documentation": "https://xuri.me/excelize",
    },
    cmdclass={"install": CustomInstallCommand},
    py_modules=[
        "excelize",
        "types_go",
        "types_py",
    ],
    python_requires=">=3.10",
    keywords=[
        "excelize",
        "excel",
        "xlsx",
        "xlsm",
        "xltx",
        "xltm",
        "xls",
        "spreadsheet",
        "workbook",
        "vba",
        "macro",
    ],
    classifiers=[
        "Development Status :: 5 - Production/Stable",
        "License :: OSI Approved :: BSD License",
        "Programming Language :: Python",
        "Programming Language :: Python :: 3 :: Only",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.10",
        "Programming Language :: Python :: 3.11",
        "Programming Language :: Python :: 3.12",
        "Programming Language :: Python :: 3.13",
    ],
)
