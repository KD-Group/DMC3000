#!/usr/bin/env python
"""
setup.py file for motion module
"""

# # Use Swig by manual generate
# from setuptools import find_packages
# from distutils.core import setup, Extension
#
# motion_module = Extension('_motion', sources=['DMC3000/motion_3000_wrap.cxx'],
#                           library_dirs=['DMC3000'], libraries=['LTDMC'])
#
# setup(name='motion',
#       version='0.1',
#       author="SF Zhou, WingC",
#       author_email="1018957763@qq.com",
#       description="""Python module for DMC3000""",
#       license='GPL',
#       classifiers=[
#           'Development Status :: 3 - Alpha',
#           'Intended Audience :: Developers',
#
#           'License :: OSI Approved :: GNU Affero General Public License v3',
#           'Programming Language :: Python :: 3',
#       ],
#       ext_modules=[motion_module],
#       packages=find_packages(),
#       package_data={'DMC3000': ['*.h', '*.dll', '*.lib']}
#       )

import os
import shutil
from setuptools import Extension, find_packages, setup
from setuptools.command.build_py import build_py


def copy_ext_modules():
    ext_module_path = 'build/lib.win-amd64-3.4/_motion_3000.pyd'
    if os.path.exists(ext_module_path):
        shutil.copy(ext_module_path, 'DMC3000/_motion_3000.pyd')


MOTION_EXT = Extension(
    name='_motion_3000',
    sources=[
        'DMC3000/motion_3000.i',
    ],
    library_dirs=['DMC3000'],
    libraries=['LTDMC'],
    swig_opts=['-c++'],
)


# Build extensions before python modules,
# or the generated SWIG python files will be missing.
class BuildPy(build_py):
    def run(self):
        self.run_command('build_ext')
        super(build_py, self).run()


copy_ext_modules()

setup(name='DMC3000',
      version='0.1',
      author="SF Zhou, WingC",
      author_email="1018957763@qq.com",
      description="""Python module for DMC3000""",
      license='GPL',
      classifiers=[
          'Development Status :: 3 - Alpha',
          'Intended Audience :: Developers',

          'License :: OSI Approved :: GNU Affero General Public License v3',
          'Programming Language :: Python :: 3',
      ],
      cmdclass={
          'build_py': BuildPy,
      },
      packages=find_packages(),
      package_dir={'DMC3000': 'DMC3000'},
      ext_modules=[MOTION_EXT],
      package_data={'DMC3000': ['*.h', '*.dll', '*.lib', '*.pyd']},
      include_package_data=True,
      python_requires='>=3.4',
      )
