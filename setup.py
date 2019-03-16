#!/usr/bin/env python
"""
setup.py file for motion module
"""

# # Use Swig by manual generate
# from setuptools import find_packages
# from distutils.core import setup, Extension
#
# motion_module = Extension('_motion', sources=['./src/motion_wrap.cxx'], library_dirs=['./src'], libraries=['LTDMC'])
#
# setup(name='motion',
#       version='0.1',
#       author="SF Zhou, WingC",
#       author_email="1018957763@qq.com",
#       description="""Python module for src""",
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
#       package_data={'src': ['*.h', '*.dll', '*.lib']}
#       )

from setuptools import Extension, find_packages, setup
from setuptools.command.build_py import build_py

MOTION_EXT = Extension(
    name='_motion',
    sources=[
        'src/motion.i',
    ],
    library_dirs=['.'],
    libraries=['LTDMC'],
    swig_opts=['-c++'],
    extra_compile_args=[  # The g++ (4.8) in Travis needs this
        '-std=c++11',
    ]
)


# Build extensions before python modules,
# or the generated SWIG python files will be missing.
class BuildPy(build_py):
    def run(self):
        self.run_command('build_ext')
        super(build_py, self).run()


setup(name='motion',
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
      packages=find_packages('src'),
      package_dir={'': 'src'},
      package_data={'src': ['*.h', '*.dll', '*.lib']},
      ext_modules=[MOTION_EXT],
      cmdclass={
          'build_py': BuildPy,
      },

      python_requires='>=3.4',
      )
