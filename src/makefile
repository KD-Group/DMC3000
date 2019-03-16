all : motion.py motion_wrap.cxx motion.h
	python3 setup.py build_ext --inplace

install : all motion.h
	python3 setup.py install

motion.py : motion.i motion.h
	swig -python -c++ motion.i

motion_wrap.cxx : motion.i motion.h
	swig -python -c++ motion.i

clean:
	@rm -rf __pycache__ *.so build motion.py *_wrap.cxx *.pyc *.pyd
