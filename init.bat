git submodule update --init --recursive
scripts\init.bat
 & @echo  ^@scripts\run_py_cmd.bat scripts\run.py %%* > beast.bat
